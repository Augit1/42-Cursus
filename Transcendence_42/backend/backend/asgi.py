"""
ASGI config for backend project.

It exposes the ASGI callable as a module-level variable named ``application``.

For more information on this file, see
https://docs.djangoproject.com/en/5.1/howto/deployment/asgi/
"""

import os
from django.core.asgi import get_asgi_application
from channels.routing import ProtocolTypeRouter, URLRouter
from channels.auth import AuthMiddlewareStack

from django.urls import path
from api.game.stream_socket import StreamSocket
import os, django

os.environ.setdefault("DJANGO_SETTINGS_MODULE", "backend.settings")
django.setup()


application = ProtocolTypeRouter(
    {
        "http": get_asgi_application(),
        "websocket": AuthMiddlewareStack(
            URLRouter(
                [
                    path("game/", StreamSocket.as_asgi()),
                ] # re_path(r'game/(?P<id>[0-9a-f-]{36})/$', .as_asgi()),

            )
        ),
    }
)
