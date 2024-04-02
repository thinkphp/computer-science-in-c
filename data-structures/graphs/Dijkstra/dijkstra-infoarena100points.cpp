#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
const int INF = 999999999;

int N, M, D[50001];

struct muchie
{
    int y, cost;
    bool operator<(const muchie &m) const
    {
        return cost > m.cost;
    }
};

priority_queue<muchie> Q;
vector<muchie> G[50001];

void Dijkstra(int nod)
{
    int cost;
    D[nod] = 0;
    Q.push({nod, 0});
    while (!Q.empty())
    {
        muchie crt = Q.top();
        Q.pop();
        if (crt.cost > D[crt.y])
            continue;
        for (muchie m : G[crt.y])
        {
            cost = D[crt.y] + m.cost;
            if (D[m.y] > cost)
            {
                D[m.y] = cost;
                Q.push({m.y, cost});
            }
        }
    }
}
int main()
{
    int x, y, w, i;
    f >> N >> M;
    for (i = 1; i <= M; i++)
    {
        f >> x >> y >> w;
        G[x].push_back({y, w});
    }
    for (i = 1; i <= N; i++)
        D[i] = INF;
    Dijkstra(1);
    for (i = 2; i <= N; i++)
        if (D[i] != INF)
            g << D[i] << ' ';
        else
            g << 0 << ' ';
}
