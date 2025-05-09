import React, { useState, useEffect, useRef } from 'react';
import { useNavigate, useLocation } from 'react-router-dom';
import ClientWebSocket from './ClientWebSocket';
import GameOverModal from '../GameOverModal';
import { useGameSetting } from '../contexts/GameContext';
import { PATCHMatchScore } from '../api-consumer/fetch';
import MessageBox from '../MessageBox';

const LocalGame = ({ player1, player2, OnWinnerSelect }) => {
    const navigate = useNavigate();
    const location = useLocation();
    const { opponentUsername, matchId, gameSettings, gameType, TournamentSettings, getUsernameById } = useGameSetting();
    const [gameStartTime, setGameStartTime] = useState(Math.floor(Date.now() / 1000));
    const [showself, setShowSelf] = useState(true);
    const [toggleGameOverModal, setToggleGameOverModal] = useState(false);
    
    const resolvePlayerNames = () => {
        if (gameType === "tournament" && player1 && player2) {
            return {
                left: getUsernameById(player1),
                right: getUsernameById(player2)
            };
        }
        if (gameType === "match") {
            // For local games, use the usernames from TournamentSettings
            const leftUsername = TournamentSettings?.Player1username || "Player 1";
            const rightUsername = TournamentSettings?.Player2username || "Marvin";
            return {
                left: leftUsername,
                right: rightUsername
            };
        }
        return {
            left: "Player 1",
            right: "Marvin"
        };
    };
    
    const [playerNames, setPlayerNames] = useState(resolvePlayerNames());
    const [message, setMessage] = useState(location.state?.message || null);
    const [messageType, setMessageType] = useState(location.state?.type || 'info');
    const [pressedKeys, setPressedKeys] = useState(new Set());
    const canvasRef = useRef(null);
    const wsRef = useRef(null);
    const animationFrameRef = useRef(null);

    // Add connection state tracking
    const [isConnected, setIsConnected] = useState(false);
    const [gameState, setGameState] = useState({
        players: {
            left: {
                x: gameSettings?.PADDLE_MARGIN,
                y: gameSettings?.CANVAS_HEIGHT / 2 - gameSettings?.PADDLE_HEIGHT / 2,
                width: gameSettings?.PADDLE_WIDTH,
                height: gameSettings?.PADDLE_HEIGHT,
                score: 0
            },
            right: {
                x: gameSettings?.CANVAS_WIDTH - gameSettings?.PADDLE_MARGIN - gameSettings?.PADDLE_WIDTH,
                y: gameSettings?.CANVAS_HEIGHT / 2 - gameSettings?.PADDLE_HEIGHT / 2,
                width: gameSettings?.PADDLE_WIDTH,
                height: gameSettings?.PADDLE_HEIGHT,
                score: 0
            }
        },
        ball: {
            x: gameSettings?.CANVAS_WIDTH / 2,
            y: gameSettings?.CANVAS_HEIGHT / 2,
            radio: gameSettings?.BALL_RADIUS,
            rx: gameSettings?.INITIAL_BALL_SPEED,
            ry: gameSettings?.INITIAL_BALL_SPEED
        },
        isPlaying: false,
        gameOver: false,
        winner: null,
        connectionError: null
    });

    useEffect(() => {
        if (!gameType){
            navigate('/')
        }
    }, [gameType])
    
    // Initialize WebSocket connection
    useEffect(() => {
        try {
            wsRef.current = new ClientWebSocket();
            
            // Add connection status handler
            wsRef.current.onConnectionStateChange = (state) => {
                setIsConnected(state === 'connected');
            };

            // Debug state tracking
            let lastState = null;
            const debugStateChanges = (data) => {
                if (data.type === 'error') {
                    setGameState(prevState => ({
                        ...prevState,
                        connectionError: data.message
                    }));
                    return;
                }

                if (data.type === 'game_update') {
                    if (!data.players || !data.ball) {
                        console.error("Missing required game state properties:", data);
                        return;
                    }

                    setGameState(prevState => {
                        // Keep x positions from initial state
                        const leftX = gameSettings?.PADDLE_MARGIN;
                        const rightX = gameSettings?.CANVAS_WIDTH - gameSettings?.PADDLE_MARGIN - gameSettings?.PADDLE_WIDTH;
                        
                        const newState = {
                            ...prevState,
                            players: {
                                left: {
                                    ...prevState.players.left,
                                    ...data.players.left,
                                    x: leftX,
                                    width: gameSettings?.PADDLE_WIDTH,
                                    height: gameSettings?.PADDLE_HEIGHT
                                },
                                right: {
                                    ...prevState.players.right,
                                    ...data.players.right,
                                    x: rightX,
                                    width: gameSettings?.PADDLE_WIDTH,
                                    height: gameSettings?.PADDLE_HEIGHT
                                }
                            },
                            ball: {
                                x: data.ball.x || prevState.ball.x,
                                y: data.ball.y || prevState.ball.y,
                                radio: gameSettings?.BALL_RADIUS,
                                rx: data.ball.rx || 0,
                                ry: data.ball.ry || 0
                            },
                            isPlaying: data.active || false,
                            connectionError: null
                        };
                        
                        // Check for game over
                        if (data.players.left.score >= gameSettings?.WINNING_SCORE || data.players.right.score >= gameSettings?.WINNING_SCORE) {
                            setGameState(prev => ({
                                ...prev,
                                gameOver: true,
                                winner: data.players.left.score >= gameSettings?.WINNING_SCORE ? 'left' : 'right',
                                isPlaying: false
                            }));
                            setToggleGameOverModal(true);
                        }
                        return newState;
                    });
                }
            };

            // Set up the game update callback
            wsRef.current.listenForGameUpdates(debugStateChanges);
        } catch (error) {
            console.error('Failed to connect to WebSocket:', error);
            setGameState(prevState => ({
                ...prevState,
                connectionError: 'Failed to connect to game server'
            }));
        }

        return () => {
            if (wsRef.current) {
                wsRef.current.close();
            }
        };
    }, []);

    const handleKeyDown = (e) => {
        setPressedKeys(prev => new Set([...prev, e.key]));
    };

    const handleKeyUp = (e) => {
        setPressedKeys(prev => {
            const newKeys = new Set(prev);
            newKeys.delete(e.key);
            return newKeys;
        });
    };

    // Send player movements to server
    useEffect(() => {
        if (gameState.isPlaying && !gameState.gameOver) {
            // Left paddle (W/S keys)
            if (pressedKeys.has('w')) {
                wsRef.current.sendPlayerMove('left', 'up');
            }
            if (pressedKeys.has('s')) {
                wsRef.current.sendPlayerMove('left', 'down');
            }

            // Right paddle (Arrow keys)
            if (pressedKeys.has('o')) {
                wsRef.current.sendPlayerMove('right', 'up');
            }
            if (pressedKeys.has('k')) {
                wsRef.current.sendPlayerMove('right', 'down');
            }
        }
    }, [pressedKeys, gameState.isPlaying, gameState.gameOver]);

    const toggleGame = async () => {
        try {
            if (gameState.gameOver) {
                await wsRef.current.sendMessage({
                    type: 'reset_game'
                });
                setGameState(prev => ({
                    ...prev,
                    gameOver: false,
                    winner: null,
                    isPlaying: true,
                    connectionError: null
                }));
            } else {
                const newIsPlaying = !gameState.isPlaying;
                if (newIsPlaying) {
                    await wsRef.current.sendPlayGame();
                } else {
                    await wsRef.current.sendStopGame();
                }
                setGameState(prev => ({
                    ...prev,
                    isPlaying: newIsPlaying,
                    connectionError: null
                }));
            }
        } catch (error) {
            console.error('Failed to toggle game:', error);
            setGameState(prev => ({
                ...prev,
                connectionError: 'Failed to communicate with game server'
            }));
        }
    };

    const handleCloseModal = () => {
        if (wsRef.current) {
            wsRef.current.close();
        }
        if (gameType === 'tournament') {
            OnWinnerSelect(gameState.winner);
        }
        setToggleGameOverModal(false);
        setShowSelf(false);
        if (gameType === 'match') {
            handleReturnToMenu();
        }
    };

    const handleReturnToMenu = () => {
        const winner = gameState.winner === 'left' ? playerNames.left : playerNames.right;
        navigate('/', { 
            state: { 
                message: `Congratulations to ${winner} for winning the match! 🎮`,
                type: 'success'
            }
        });
    };

    useEffect(() => {
        window.addEventListener('keydown', handleKeyDown);
        window.addEventListener('keyup', handleKeyUp);

        return () => {
            window.removeEventListener('keydown', handleKeyDown);
            window.removeEventListener('keyup', handleKeyUp);
        };
    }, []);

    // Add frame counter for debugging
    const frameCounter = useRef(0);
    const lastUpdateTime = useRef(Date.now());

    // Modify the animation frame handler to track frames and ensure smooth updates
    useEffect(() => {
        let animationFrameId;
        
        const render = () => {
            if (wsRef.current && gameState.isPlaying && !gameState.gameOver) {
                frameCounter.current++;
                const currentTime = Date.now();
                
                // Log every second
                if (currentTime - lastUpdateTime.current >= 1000) {
                    frameCounter.current = 0;
                    lastUpdateTime.current = currentTime;
                }
                
                // Handle continuous paddle movement
                if (pressedKeys.size > 0) {
                    if (pressedKeys.has('w')) {
                        wsRef.current.sendPlayerMove('left', 'up');
                    }
                    if (pressedKeys.has('s')) {
                        wsRef.current.sendPlayerMove('left', 'down');
                    }
                    if (pressedKeys.has('o')) {
                        wsRef.current.sendPlayerMove('right', 'up');
                    }
                    if (pressedKeys.has('k')) {
                        wsRef.current.sendPlayerMove('right', 'down');
                    }
                }
            }
            animationFrameId = window.requestAnimationFrame(render);
        };
        
        if (gameState.isPlaying && !gameState.gameOver) {
            animationFrameId = window.requestAnimationFrame(render);
        }
        
        return () => {
            if (animationFrameId) {
                window.cancelAnimationFrame(animationFrameId);
            }
        };
    }, [gameState.isPlaying, gameState.gameOver, pressedKeys, gameState.ball, gameState.players]);

    // Update canvas rendering
    useEffect(() => {
        const canvas = canvasRef.current;
        if (!canvas) return;
        
        const ctx = canvas.getContext('2d');
        
        // Clear canvas
        ctx.fillStyle = 'black';
        ctx.fillRect(0, 0, gameSettings?.CANVAS_WIDTH, gameSettings?.CANVAS_HEIGHT);
        
        // Draw center line
        ctx.strokeStyle = 'white';
        ctx.setLineDash([5, 15]);
        ctx.beginPath();
        ctx.moveTo(gameSettings?.CANVAS_WIDTH / 2, 0);
        ctx.lineTo(gameSettings?.CANVAS_WIDTH / 2, gameSettings?.CANVAS_HEIGHT);
        ctx.stroke();
        ctx.setLineDash([]);
        
        // Draw scores
        ctx.font = '48px Arial';
        ctx.fillStyle = 'white';
        ctx.textAlign = 'center';
        ctx.fillText(gameState.players.left.score.toString(), gameSettings?.CANVAS_WIDTH / 4, 50);
        ctx.fillText(gameState.players.right.score.toString(), (gameSettings?.CANVAS_WIDTH * 3) / 4, 50);
        
        // Draw paddles
        ctx.fillStyle = 'white';
        // Left paddle
        ctx.fillRect(
            gameState.players.left.x,
            gameState.players.left.y,
            gameSettings?.PADDLE_WIDTH,
            gameSettings?.PADDLE_HEIGHT
        );
        // Right paddle
        ctx.fillRect(
            gameState.players.right.x,
            gameState.players.right.y,
            gameSettings?.PADDLE_WIDTH,
            gameSettings?.PADDLE_HEIGHT
        );
        
        // Draw ball
        if (gameState.ball) {
            ctx.beginPath();
            ctx.arc(
                gameState.ball.x,
                gameState.ball.y,
                gameState.ball.radio,
                0,
                Math.PI * 2
            );
            ctx.fillStyle = 'white';
            ctx.fill();
            ctx.closePath();
        }
        
        // Draw game over message
        if (gameState.gameOver) {
            ctx.font = '60px Arial';
            ctx.fillStyle = 'white';
            const winner = gameState.winner === 'left' ? playerNames.left : playerNames.right;
            ctx.textAlign = 'center';
            ctx.fillText(`${winner} Wins!`, gameSettings?.CANVAS_WIDTH / 2, gameSettings?.CANVAS_HEIGHT / 2 - 30);
        }
    }, [gameState]);

    // Remove the duplicate WebSocket message handler
    useEffect(() => {
        if (!wsRef.current) return;
        return () => {
            if (wsRef.current) {
                wsRef.current.listenForGameUpdates(null);
            }
        };
    }, []);

    // Add effect to update player names when needed
    useEffect(() => {
        setPlayerNames(resolvePlayerNames());
    }, [opponentUsername, gameType]);

    // Initialize gameStartTime when the game starts playing
    useEffect(() => {
        if (gameState.isPlaying && !gameStartTime) {
            const currentTime = Math.floor(Date.now() / 1000);
            setGameStartTime(currentTime);
        }
    }, [gameState.isPlaying, gameStartTime]);

    // Add a standalone function to update match scores when a game ends
    const updateMatchScore = () => {
        const currentTime = Date.now();
        const gameStartTimeMs = gameStartTime * 1000;
        const durationMs = currentTime - gameStartTimeMs;
        
        const totalSeconds = Math.floor(durationMs / 1000);
        const minutes = Math.floor(totalSeconds / 60);
        const seconds = totalSeconds % 60;
        const milliseconds = Math.floor((durationMs % 1000) / 10);
        
        const formattedDuration = `${minutes.toString().padStart(2, '0')}:${seconds.toString().padStart(2, '0')}.${milliseconds.toString().padStart(2, '0')}`;
        
        PATCHMatchScore(
            matchId,
            gameState.players.right.score,
            gameState.players.left.score,
            formattedDuration
        ).catch(error => {
            console.error("Error updating match score:", error);
        });
    };

    // Call updateMatchScore when the game ends
    useEffect(() => {
        if (gameState.gameOver && matchId) {
            updateMatchScore();
        }
    }, [gameState.gameOver, matchId]);

    // Extract message from navigation state
    useEffect(() => {
        if (location.state?.message) {
            setMessage(location.state.message);
            setMessageType(location.state.type || 'info');
        }
    }, [location]);

    if (!showself) return null;

    return (
        <div className="gameplay-container" style={{ 
            display: 'flex', 
            flexDirection: 'column', 
            alignItems: 'center', 
            padding: '20px',
            minHeight: '100vh'
        }}>
            {message && (
                <MessageBox
                    message={message}
                    type={messageType}
                    onClose={() => setMessage(null)}
                />
            )}
            <div className="game-return" style = {{display: 'flex', justifyContent: 'center', alignItems: 'center', marginBottom: '20px'}}>
                {!gameState.gameOver && (
                    <button 
                        className="game-return"
                        onClick={toggleGame} 
                        disabled={!!gameState.connectionError}
                    >
                        {gameState.isPlaying ? 'Pause Game' : 'Start Game'}
                    </button>
                )}
            </div>
            {gameState.connectionError && (
                <div className="error-message" style={{ color: 'red', marginBottom: '10px' }}>
                    {gameState.connectionError}
                </div>
            )}
            <div className="controls-paddles">
                <p>{playerNames.left}: W/S keys</p>
                <p>{playerNames.right}: O/K keys</p>
            </div>
            <div style={{ position: 'relative' }}>
                <canvas
                    ref={canvasRef}
                    width={gameSettings?.CANVAS_WIDTH}
                    height={gameSettings?.CANVAS_HEIGHT}
                    style={{
                        border: '2px solid white',
                        backgroundColor: 'black',
                        display: 'block'
                    }}
                />
            </div>
            <div className="game-controls" style={{ 
                marginTop: '20px', 
                color: 'white', 
                textAlign: 'center' 
            }}>
                <div className="game-specs">
                    Ball: ({Math.round(gameState.ball.x)}, {Math.round(gameState.ball.y)})<br/>
                    Velocity: ({Math.round(gameState.ball.rx)}, {Math.round(gameState.ball.ry)})<br/>
                    Left Paddle: {Math.round(gameState.players.left.y)}<br/>
                    Right Paddle: {Math.round(gameState.players.right.y)}<br/>
                    Playing: {gameState.isPlaying ? 'Yes' : 'No'}
                </div>
            </div>
            {gameState.gameOver && toggleGameOverModal && (
                <GameOverModal 
                    showModal={gameState.gameOver} 
                    handleCloseModal={handleCloseModal} 
                    player1={playerNames.left} 
                    player2={playerNames.right} 
                    score1={gameState.players.left.score} 
                    score2={gameState.players.right.score}
                />
            )}
        </div>
    );
};

export default LocalGame;