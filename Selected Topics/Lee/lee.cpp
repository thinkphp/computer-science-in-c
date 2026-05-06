#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100][100];
int dist[100][100];

pair<int,int> parent[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void lee(int sx, int sy, int ex, int ey) {
    queue<pair<int,int>> q;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            dist[i][j] = -1;
            parent[i][j] = {-1, -1};
        }

    q.push({sx, sy});
    dist[sx][sy] = 0;

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(valid(nx, ny) && a[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if(dist[ex][ey] == -1) {
        cout << "Nu exista drum\n";
        return;
    }

    vector<pair<int,int>> path;
    pair<int,int> cur = {ex, ey};

    while(cur.first != -1) {
        path.push_back(cur);
        cur = parent[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());

    cout << "Drumul este:\n";
    for(auto p : path)
        cout << "(" << p.first << "," << p.second << ") ";

    cout << "\nDistanta = " << dist[ex][ey] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lee.in","r",stdin); 
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int sx, sy, ex, ey;
    cin >> sx >> sy;
    cin >> ex >> ey;

    lee(sx, sy, ex, ey);

    return 0;
}
