
# Tic Tac Toe Game

A simple command-line implementation of the classic Tic Tac Toe game written in C.

## Description

This project is a straightforward implementation of Tic Tac Toe that runs in the terminal. The game allows two players to take turns marking spaces on a 3x3 grid. The first player to place three of their marks in a horizontal, vertical, or diagonal row wins the game.

## Features

- Clean, console-based user interface
- Input validation to prevent illegal moves
- Automatic win detection
- Draw detection when the board is full
- Turn-based gameplay with clear player indicators

## How to Play

1. The game starts with an empty 3x3 grid
2. Players take turns placing their mark ('X' or '0') on the board
3. Input a number between 1-9 to place your mark in the corresponding position:
   ```
   1 | 2 | 3
   ----------
   4 | 5 | 6
   ----------
   7 | 8 | 9
   ```
4. The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins
5. If all positions are filled and no player has won, the game ends in a draw

## Technical Implementation

The game is built with the following components:

- Board representation using a character array
- Display function to render the current state of the board
- Win-checking logic for horizontal, vertical, and diagonal lines
- Input validation to ensure moves are legal
- Turn alternation between players

## Compilation and Execution

To compile the game, use a C compiler such as GCC:

```bash
gcc -o tic_tac_toe tic_tac_toe.c
```

To run the game:

```bash
./tic_tac_toe
```

## Code Structure

- `display()`: Renders the current state of the game board
- `check_winner()`: Checks if a player has won
- `checkFullBoard()`: Determines if the board is full (draw condition)
- `main()`: Main game loop and player interaction

## Future Enhancements

Potential improvements for the future:

- Implement a computer player with different difficulty levels
- Add a score tracking system for multiple games
- Create a graphical user interface
- Add network play capability for remote opponents

## Author

[Your Name]

## License

[Your Choice of License]
