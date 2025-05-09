from django.urls import path

from rest_framework_simplejwt.views import TokenRefreshView


from api.views.user.views import CreateUserView, UserProfileView, LoginView, CheckUserExistsView, UserFriendsView, OthersProfileView, MatchesPlayedView, MatchesWonView, UserListMatchesView, UserActiveView, OthersActiveView, BeaconLogoutView
from api.views.match.views import game_settings, MatchCreationView, CreateOnlineMatchView, UserMatchListView, MatchScoreUpdateView, AvailableMatchView
from api.views.auth.TwoFA import Setup2FAView
from api.views.auth.auth42 import FTAuthCallbackView
from api.views.auth.jwt import CustomTokenRefreshView
from api.views.game.cli_views import GameStateView, GameControlView, PlayerMoveView, GameStatsView
from api.views.tournament.views import CreateTournamentView, AddMatchToTournamentView, AddWinnerToTournamentView, UserTournWinnerCountView, UserParticipationCountView, TournamentDetailView
from api.views.blockchain.views import TournamentBlockchainScoresView, blockchain_score

urlpatterns = [
    # User endpoints
    path('user/login/',                           LoginView.as_view(), name='login'), #POST #ANY
    path('user/register/',                        CreateUserView.as_view(), name='register'), #POST #ANY
    path('user/profile/',                         UserProfileView.as_view(), name='profile'), #UPDT & GET #AUTH
    path('user/refresh/',                         CustomTokenRefreshView.as_view(), name='refresh'), #GET? #AUTH 
    path('user/active/',                          UserActiveView.as_view(), name='active'), #GET & UPDT #AUTH
    path('user/logout/',                          BeaconLogoutView.as_view(), name='active'), #POST #ANY
    path('user/friends/active/<str:username>',    OthersActiveView.as_view(), name='friends'), #GET #AUTH
    
    path('user/exists/<str:username>', CheckUserExistsView.as_view(), name='check_username'), #GET #AUTH
    path('user/friends/<str:username>', UserFriendsView.as_view(), name='friends'), #GET POST DELETE #AUTH
    path('user/matches-played/<str:username>/', MatchesPlayedView.as_view(), name='matches-played'), #GET
    path('user/list-matches-played/<str:username>/', UserListMatchesView.as_view(), name='get_user_matches'), #GET
    path('user/matches-won/<str:username>/', MatchesWonView.as_view(), name='matches-won'), #GET
    path('user/profile/<str:username>',           OthersProfileView.as_view(), name='profile'), #UPDT & GET #AUTH
    path('user/exists/<str:username>',            CheckUserExistsView.as_view(), name='check_username'), #GET #AUTH

    # 2FA endpoints
    path('setup-2fa/',                            Setup2FAView.as_view(), name='setup2fa'),# GET & POST
    
    # 42 Auth endpoints
    path('auth/42/callback/',                     FTAuthCallbackView.as_view(), name='ft_callback'), #GET

    # Match endpoints
    path('matches/',                              MatchCreationView.as_view(), name='match-create'), #POST create match
    path('matches/<uuid:pk>',                     MatchScoreUpdateView.as_view(), name='match-update'),#UPDT Updates Matches scores and duration
    path('matches/list',                          UserMatchListView.as_view(), name='list-match'), # GET Can specify match-id or list all user matches
    path('matches/available/',                    AvailableMatchView.as_view(), name='match-available'),

    # Tournament endpoints
    path('tournament/',                                       CreateTournamentView.as_view(), name='tournament'),
    path('tournaments/<uuid:pk>/add-matches/',                AddMatchToTournamentView.as_view(), name='add-matches-to-tournament'),
    path('tournaments/<uuid:pk>/add-winner/',                 AddWinnerToTournamentView.as_view(), name='add-winner-to-tournament'),
    path('tournaments/<uuid:tournament_id>/',                 TournamentDetailView.as_view(), name='tournament-detail'),
    path('tournament/<str:tournament_id>/blockchain-scores/', TournamentBlockchainScoresView.as_view(), name='tournament-blockchain-scores'),
    path('tournaments/<uuid:UserID>/count-wins/',             UserTournWinnerCountView.as_view(), name='count-amount-of-tournament-wins'),
    path('tournaments/<uuid:UserID>/count-matches/',          UserParticipationCountView.as_view(), name='count-amount-of-tournament-plays'),

    # Blockchain endpoints
    path('blockchain/score/', blockchain_score, name='blockchain-score'),

    # Game CLI endpoints
    path('game/cli/state/<uuid:match_id>/',                   GameStateView.as_view(), name='game-cli-state'),
    path('game/cli/control/<uuid:match_id>/',                 GameControlView.as_view(), name='game-cli-control'),
    path('game/cli/move/<uuid:match_id>/',                    PlayerMoveView.as_view(), name='game-cli-move'),
    path('game/cli/stats/<uuid:match_id>/',                   GameStatsView.as_view(), name='game-cli-stats'),

    # Game Settings Endpoint
    path('game-settings/', game_settings, name='game-settings')
]