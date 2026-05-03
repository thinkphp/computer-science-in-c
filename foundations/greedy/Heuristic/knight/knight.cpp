#include <iostream>
#include <vector>
using namespace std;

const int N = 8;

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};

int board[N][N];

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N && board[x][y] == 0;
}

// numără câte mutări are dintr-o poziție
int degree(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny)) cnt++;
    }
    return cnt;
}

bool nextMove(int &x, int &y) {
    int min_deg = 9;
    int next_x = -1, next_y = -1;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (valid(nx, ny)) {
            int d = degree(nx, ny);

            if (d < min_deg) {
                min_deg = d;
                next_x = nx;
                next_y = ny;
            }
        }
    }

    if (next_x == -1) return false;

    x = next_x;
    y = next_y;
    return true;
}

void knightTour(int startX, int startY) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    int x = startX, y = startY;
    board[x][y] = 1;

    for (int step = 2; step <= N*N; step++) {
        if (!nextMove(x, y)) {
            cout << "Esec!\n";
            return;
        }
        board[x][y] = step;
    }

    // afișare soluție
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    knightTour(0, 0);
    return 0;
}
