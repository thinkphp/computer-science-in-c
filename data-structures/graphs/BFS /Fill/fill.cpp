#include <queue>
using namespace std;

void fillBFS(int startX, int startY, int oldColor, int newColor) {
    if (oldColor == newColor) return;

    queue<pair<int,int>> q;
    q.push({startX, startY});
    mat[startX][startY] = newColor;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                mat[nx][ny] == oldColor) {
                mat[nx][ny] = newColor;
                q.push({nx, ny});
            }
        }
    }
}
