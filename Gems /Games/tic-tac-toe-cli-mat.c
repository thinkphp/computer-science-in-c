

#include <stdio.h>
#include <stdbool.h>

char board[3][3];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void displayBoard() {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool isValidMove(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    return board[row][col] == '-';
}

bool hasWon() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == currentPlayer &&
            board[1][j] == currentPlayer &&
            board[2][j] == currentPlayer) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer) {
        return true;
    }

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer) {
        return true;
    }

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    bool gameFinished = false;
    int row, col;

    while (!gameFinished) {
        displayBoard();
        printf("Jucător %c, introdu rândul (0-2) și coloana (0-2): ", currentPlayer);

        scanf("%d %d", &row, &col);

        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;
            displayBoard();
            if (hasWon()) {
                displayBoard();
                printf("Jucătorul %c a câștigat!\n", currentPlayer);
                gameFinished = true;
            } else if (isBoardFull()) {
                displayBoard();
                printf("Joc la egalitate!\n");
                gameFinished = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Mutare invalidă! Încearcă din nou.\n");
        }
    }
}

int main() {
    currentPlayer = 'X';
    initializeBoard();
    playGame();
    return 0;
}
