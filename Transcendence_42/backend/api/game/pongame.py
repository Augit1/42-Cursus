import json
import math
import random
import time
from typing import Dict, Tuple, Optional
from api.game.game_constants import GAME_SETTINGS

class PongGame:
    def __init__(self, player1, player2=None):
        self.__left_player = player1
        self.__right_player = player2
        self.__width = GAME_SETTINGS['CANVAS_WIDTH']
        self.__height = GAME_SETTINGS['CANVAS_HEIGHT']
        self.__initial_ball_speed = GAME_SETTINGS['INITIAL_BALL_SPEED']  # Base speed
        self.__max_ball_speed = GAME_SETTINGS['MAX_BALL_SPEED']      # Maximum speed
        self.__max_score = GAME_SETTINGS['WINNING_SCORE']
        self.reset_game()

    def get_gameState(self):
        return {
            "players": self.__players,
            "ball": self.__ball,
            "active": self.__game_active
        }

    def IsGameActive(self):
        return self.__game_active

    def SetGameActive(self, active):
        was_active = self.__game_active
        self.__game_active = bool(active)
        
        # Only initialize ball velocity when transitioning from inactive to active
        if not was_active and self.__game_active:
            self.reset_ball(random.choice(['left', 'right']))

    def set_player2(self, player2):
        self.__right_player = player2

    def get_players(self, side):
        return self.__players.get(side, {})

    def reset_game(self):
        # Players State
        self.__players = {
            'left': {
                'id': self.__left_player,
                'x': 20,  # Closer to edge
                'y': self.__height / 2 - 45,
                'width': 15,
                'height': 90,
                'speed': 3,
                'score': 0
            },
            'right': {
                'id': self.__right_player,
                'x': self.__width - 35,  # Closer to edge
                'y': self.__height / 2 - 45,
                'width': 15,
                'height': 90,
                'speed': 3,
                'score': 0
            }
        }
        # Ball State
        self.__ball = {
            'x': self.__width / 2,
            'y': self.__height / 2,
            'radio': 10,
            'rx': 0,  # Initialize with 0 velocity
            'ry': 0   # Initialize with 0 velocity
        }
        # Game State
        self.__game_active = False

    def move_players(self, side, direction):
        if side not in self.__players:
            return

        player = self.__players[side]
        speed = player['speed']

        if direction == 'up':
            player['y'] = max(0, player['y'] - speed)
        elif direction == 'down':
            player['y'] = min(self.__height - player['height'], player['y'] + speed)

    def update_ball(self):
        if not self.__game_active:
            return

        # Update ball position
        self.__ball['x'] += self.__ball['rx']
        self.__ball['y'] += self.__ball['ry']

        # Ball collision with top and bottom walls
        if self.__ball['y'] <= 0 or self.__ball['y'] >= self.__height:
            self.__ball['ry'] *= -1

        # Collision with paddles
        for side, paddle in self.__players.items():
            if self.check_ball_paddle_collision(paddle):
                # Calculate where on the paddle the ball hit (0 = top edge, 1 = bottom edge)
                hit_position = (self.__ball['y'] - paddle['y']) / paddle['height']
                
                # Detect if we hit very close to the edges
                edge_threshold = 0.1  # 10% from top or bottom
                hit_edge = hit_position < edge_threshold or hit_position > (1 - edge_threshold)
                
                # Calculate reflection angle based on hit position
                reflection_angle = (hit_position - 0.5) * 1.5  # -0.75 to 0.75
                
                # Calculate new velocity
                speed = math.sqrt(self.__ball['rx']**2 + self.__ball['ry']**2)
                
                if hit_edge:
                    # Edge hit - strong vertical component
                    self.__ball['ry'] = reflection_angle * speed
                    self.__ball['rx'] = -self.__ball['rx'] * 0.7
                else:
                    # Normal hit
                    self.__ball['ry'] = reflection_angle * speed
                    self.__ball['rx'] = -self.__ball['rx']
                
                # Reposition ball to prevent sticking
                if side == 'left':
                    self.__ball['x'] = paddle['x'] + paddle['width'] + self.__ball['radio'] + 1
                else:
                    self.__ball['x'] = paddle['x'] - self.__ball['radio'] - 1
                
                # Increase speed by 20% up to max_ball_speed
                current_speed = math.sqrt(self.__ball['rx']**2 + self.__ball['ry']**2)
                if current_speed < self.__max_ball_speed:
                    speed_multiplier = min(1.2, self.__max_ball_speed / current_speed)  # 20% increase
                    self.__ball['rx'] *= speed_multiplier
                    self.__ball['ry'] *= speed_multiplier
                
                break

        # Points
        if self.__ball['x'] <= 0:
            self.__players['right']['score'] += 1
            if self.__players['right']['score'] >= self.__max_score:
                self.__game_active = False
            self.reset_ball('left')
        elif self.__ball['x'] >= self.__width:
            self.__players['left']['score'] += 1
            if self.__players['left']['score'] >= self.__max_score:
                self.__game_active = False
            self.reset_ball('right')

    def check_ball_paddle_collision(self, paddle):
        # Consider the ball's radius in collision detection
        ball_left = self.__ball['x'] - self.__ball['radio']
        ball_right = self.__ball['x'] + self.__ball['radio']
        ball_top = self.__ball['y'] - self.__ball['radio']
        ball_bottom = self.__ball['y'] + self.__ball['radio']
        
        # Add a small buffer zone around the paddle (2 pixels)
        buffer = 2
        paddle_left = paddle['x'] - buffer
        paddle_right = paddle['x'] + paddle['width'] + buffer
        paddle_top = paddle['y'] - buffer
        paddle_bottom = paddle['y'] + paddle['height'] + buffer

        # Simple collision check
        return (
            ball_right >= paddle_left and
            ball_left <= paddle_right and
            ball_bottom >= paddle_top and
            ball_top <= paddle_bottom
        )

    def reset_ball(self, scoring_side):
        self.__ball['x'] = self.__width / 2
        self.__ball['y'] = self.__height / 2
        
        # Set initial velocity based on who scored
        self.__ball['rx'] = self.__initial_ball_speed if scoring_side == 'right' else -self.__initial_ball_speed
        
        # Add a small random vertical component
        self.__ball['ry'] = self.__initial_ball_speed * (random.random() * 1.0 - 0.5)  # -0.5 to 0.5 of base speed

    def get_ball_position(self) -> Dict[str, float]:
        """Get the current ball position"""
        return {
            'x': self.__ball['x'],
            'y': self.__ball['y']
        }

    def get_player_positions(self) -> Dict[str, Dict[str, float]]:
        """Get the current paddle positions"""
        return self.__players.copy()

    def get_scores(self) -> Dict[str, int]:
        """Get the current scores"""
        return {side: player['score'] for side, player in self.__players.items()}

    def is_active(self) -> bool:
        """Check if the game is active"""
        return self.__game_active

    def get_last_update_time(self) -> float:
        """Get the timestamp of the last update"""
        return time.time()

    def get_players(self) -> Tuple[Optional[str], Optional[str]]:
        """Get the players in the game"""
        return (self.__left_player, self.__right_player)

    def get_winner(self) -> Optional[str]:
        """Get the winner of the game"""
        return None  # This method is not applicable in the new implementation

    def get_game_duration(self) -> Optional[float]:
        """Get the duration of the game in seconds"""
        return None  # This method is not applicable in the new implementation

    def get_game_state(self) -> Dict:
        """Get the complete game state"""
        return {
            'active': self.__game_active,
            'scores': self.get_scores(),
            'ball_position': self.get_ball_position(),
            'player_positions': self.get_player_positions(),
            'players': {
                'left': self.__left_player,
                'right': self.__right_player
            },
            'last_update': self.get_last_update_time()
        }
