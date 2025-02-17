Developed for the ChipKIT uC32 and Basic I/O Shield
KTH - IS1200 Course

1. Project Overview
This project implements a Pong Game on the ChipKIT uC32 development board with a Basic I/O Shield. 
The game is displayed on the built-in OLED graphical display, featuring a two-player mode and AI-controlled opponent mode. 
The project involves real-time graphics rendering, game physics, and user input handling.

Game Logic:

Ball Mechanics:
The ball moves pixel-by-pixel in both X and Y directions.
The ball bounces off the paddles and screen edges.
The bounce angle is calculated based on the collision position.

Paddle Controls:
Player 1 controls the left paddle using BTN1 & BTN2.
Player 2 (or AI) controls the right paddle using BTN3 & BTN4.
The AI opponent moves based on the ball’s Y position.

Game Modes:
Single-Player Mode: Player vs AI (Easy, Medium, Hard difficulty levels).
Two-Player Mode: Player vs Player.

Scoring System:
When a player misses the ball, the opponent scores a point.
The game ends when a player reaches a set score (5 points).

Graphics Rendering:
The game objects (ball & paddles) are drawn and updated on the OLED screen.
Pixel-by-pixel updates ensure smooth movement.

Compiling the Code:
Install the MCB32 Toolchain or MPLAB X IDE.
Open the project folder in your preferred development environment.
Connect the ChipKIT uC32 board to your computer via USB.
Compile and upload the code to the board.

Playing the Game:
Power on the ChipKIT board.
Select Game Mode: Use switches to choose 1-player or 2-player mode.
Score Points: Hit the ball back to the opponent and avoid missing it.
Win Condition: First to 5 points wins!