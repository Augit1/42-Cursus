from django.conf import settings
from django.http import HttpResponseRedirect, JsonResponse
from django.contrib.auth import authenticate, login
from rest_framework.permissions import AllowAny
from rest_framework.response import Response
from rest_framework.views import APIView
from rest_framework_simplejwt.tokens import RefreshToken

import json
import base64
import qrcode
import requests

import logging
logger = logging.getLogger(__name__)

# DB TABLES
from api.models import UserProfile

logger = logging.getLogger(__name__)


def get_or_create_user(user_data):
    """Create or get a user from 42 database."""
    #print("Received user_data from 42: ", user_data)
    username = user_data['login']
    email = user_data['email']
    given_name = user_data['displayname'].split()[0]
    surname = ' '.join(user_data['displayname'].split()[1:]) or ''
    
    # Check if a user with the same username exists but is not a 42 user
    try:
        existing_user = UserProfile.objects.get(username=username)
        if not existing_user.is_42user:
            return None, "username"
    except UserProfile.DoesNotExist:
        pass
    
    # Check if a user with the same email exists but is not a 42 user
    try:
        existing_user = UserProfile.objects.get(email=email)
        if not existing_user.is_42user:
            return None, "email"
    except UserProfile.DoesNotExist:
        pass
    
    # Check if a user with the same name exists but is not a 42 user
    try:
        existing_user = UserProfile.objects.get(given_name=given_name, surname=surname)
        if not existing_user.is_42user:
            return None, "name"
    except UserProfile.DoesNotExist:
        pass
    
    # If no conflicts found, create or get the user
    user, created = UserProfile.objects.get_or_create(
        username=username,
        defaults={
            'email': email,
            'is_42user': True,
            'given_name': given_name,
            'surname': surname,
            'username': username
        }
    )
    return user, None

class FTAuthCallbackView(APIView):
    permission_classes = [AllowAny]
    def get(self, request):
        code = request.GET.get('code')
        state = request.GET.get('state')

        if not code:
            # User denied permission or there was an error
            error_message = "Authentication with 42 was cancelled or denied. Please try again or use regular login."
            # Try to get the redirect_uri from state if available
            redirect_uri = None
            if state:
                try:
                    state_data = json.loads(state)
                    redirect_uri = state_data.get('redirect_uri')
                except json.JSONDecodeError:
                    pass
            
            if redirect_uri:
                callback_uri = redirect_uri.replace('/api/auth/42/callback', '/login/callback')
                redirect_url = f"{callback_uri}?error={error_message}"
                return HttpResponseRedirect(redirect_url)
            else:
                # Fallback if we can't get the redirect_uri
                return JsonResponse({'error': error_message}, status=400)

        if not state:
            return JsonResponse({'error': 'Missing state parameter'}, status=400)

        state_data = json.loads(state)
        redirect_uri = state_data.get('redirect_uri')
        logger.info(f"Retrieved redirect_uri from state: {redirect_uri}")
        token_url = "https://api.intra.42.fr/oauth/token"
        payload = {
            'grant_type': 'authorization_code',
            'client_id': settings.FT_CLIENT_ID,
            'client_secret': settings.FT_CLIENT_SECRET,
            'code': code,
            'redirect_uri': redirect_uri,
        }
        response = requests.post(token_url, data=payload)
        if response.status_code != 200:
            logger.error(f"Token request failed: {response.status_code} - {response.text}")
            logger.info(f"Sent payload: {payload}")
            error_message = "Failed to authenticate with 42. Please try again or use regular login."
            callback_uri = redirect_uri.replace('/api/auth/42/callback', '/login/callback')
            redirect_url = f"{callback_uri}?error={error_message}"
            return HttpResponseRedirect(redirect_url)

        token_data = response.json()
        access_token = token_data.get('access_token')

        # Get user info
        user_info_url = "https://api.intra.42.fr/v2/me"
        headers = {'Authorization': f'Bearer {access_token}'}
        user_response = requests.get(user_info_url, headers=headers)
        if user_response.status_code != 200:
            error_message = "Failed to get user information from 42. Please try again or use regular login."
            callback_uri = redirect_uri.replace('/api/auth/42/callback', '/login/callback')
            redirect_url = f"{callback_uri}?error={error_message}"
            return HttpResponseRedirect(redirect_url)

        user_data = user_response.json()
        user, conflict_type = get_or_create_user(user_data)
        
        # If there's a conflict, redirect with an error message
        if user is None:
            error_message = f"An account with this {conflict_type} already exists. Please use your regular login credentials."
            callback_uri = redirect_uri.replace('/api/auth/42/callback', '/login/callback')
            redirect_url = f"{callback_uri}?error={error_message}"
            return HttpResponseRedirect(redirect_url)

        # Connect user
        authenticate(request, username=user.username)
        login(request, user)
        refresh = RefreshToken.for_user(user)    
        user.active = True
        user.save(update_fields=['active'])
        
        # Redirect to frontend
        callback_uri = redirect_uri.replace('/api/auth/42/callback', '/login/callback')
        redirect_url = f"{callback_uri}?access={refresh.access_token}"
        return HttpResponseRedirect(redirect_url)