#include <cstdio>
#include <vector>

using namespace std;

#define MAX_N 1005
#define INF 0x3f3f3f
#define pb push_back

int N, M;
int C[MAX_N][MAX_N], F[MAX_N][MAX_N];
int T[MAX_N];
bool viz[MAX_N];

vector <int> V[MAX_N];

void citire()
{
    scanf("%d %d",&N, &M);

    int x, y, z;
    for(int i = 1; i <= M; ++i)
    {
        scanf("%d %d %d",&x, &y, &z);
        V[x].pb(y);
        V[y].pb(x);
        C[x][y] = z;
    }
}

bool BFS()
{
    int Q[MAX_N], nod;
    Q[0] = Q[1] = 1;
    memset(viz,0, sizeof viz);
    viz[1] = 1;

    for(int i = 1; i <= Q[0]; ++i)
    {
        nod = Q[i];
        if(nod == N) continue;

        for(int i = 0; i < V[nod].size(); ++i)
        {
            int k = V[nod][i];
            if(F[nod][k] == C[nod][k] || viz[k]) continue;
            viz[k] = 1;
            Q[++Q[0]] = k;
            T[k] = nod;
        }
    }
    return viz[N];
}

void flux()
{
    int flow = 0, fmin;
    while(BFS())
        for(int i = 0; i < V[N].size(); ++i)
        {
            int nod = V[N][i];
            if(F[nod][N] == C[nod][N] || viz[nod] == 0) continue;
            T[N] = nod;

            fmin = INF;

            for(int i = N; i != 1; i = T[i])
                fmin = min(fmin, C[T[i]][i] - F[T[i]][i]);

            for(int i = N; i != 1; i = T[i])
            {
                F[T[i]][i] += fmin;
                F[i][T[i]] -= fmin;
            }
            flow += fmin;
        }
    printf("%d\n",flow);
}

int main()
{
    freopen("maxflow.in","rt",stdin);
    freopen("maxflow.out","wt",stdout);

    citire();
    flux();
}

