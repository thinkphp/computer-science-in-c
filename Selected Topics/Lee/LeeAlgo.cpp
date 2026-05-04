#include <iostream>
#include <queue>
using namespace std;

int n = 3, m = 3;
int a[3][3] = {
    {0,0,0},
    {0,1,0},
    {0,0,0}
};

int dist[3][3];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void lee(int sx, int sy) {
    queue<pair<int,int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 1;

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m &&
               a[nx][ny] == 0 && dist[nx][ny] == 0) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}
