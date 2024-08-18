#ifndef LOCAL
    #pragma GCC optimize("O3")
    #pragma GCC target("avx2")
#endif

#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
using ll = long long;
using ci = const int;
using cll = const long long;

using namespace std;

const int INF = 1e9 + 7;
/*******************************/
// INPUT / OUTPUT

#ifndef LOCAL
    ifstream in("maxflow.in");
    ofstream out("maxflow.out");
    #define cin in
    #define cout out
#endif
/*******************************/
/// GLOBAL DECLARATIONS

int N, M;

struct Muchie
{
    int from, to, cap;
};

struct Graf
{
    int n, flux_maxim;
    vector <int> pre;
    vector <Muchie> muchii;
    vector <vector <int>> adj;

    Graf(int _n)
    {
        n = _n;
        flux_maxim = 0;
        adj.resize(n);
        pre.resize(n);
    }

    inline void adauga_muchie(int from, int to, int cap)
    {
        adj[from].push_back(muchii.size());
        muchii.push_back({from, to, cap});

        adj[to].push_back(muchii.size());
        muchii.push_back({to, from, 0});
    }
    
    inline void impinge_flux(int sursa, int dest)
    {
        int flux = INF;
        for (int node = dest ; node != sursa ; node = muchii[pre[node]].from)
        {
            flux = min(flux, muchii[pre[node]].cap);
        }

        for (int node = dest ; node != sursa ; node = muchii[pre[node]].from)
        {
            muchii[pre[node]].cap -= flux;
            muchii[pre[node] ^ 1].cap += flux;
        }

        flux_maxim += flux;
    }

    inline bool bfs(int sursa, int dest)
    {
        bool ok = false;
        for (int i = 0 ; i < n ; ++ i)
            pre[i] = -1;

        queue <int> q;
        q.push(sursa);

        int node;
        Muchie u;
        while (!q.empty())
        {
            node = q.front();
            q.pop();

            for (auto i: adj[node])
            {
                u = muchii[i];
                if (u.cap && pre[u.to] == -1)
                {
                    pre[u.to] = i;
                    if (u.to == dest)
                    {
                        ok = true;
                        impinge_flux(sursa, dest);
                        pre[u.to] = -1;
                        continue;
                    }
                    q.push(u.to);
                }
            }
        }

        return ok;
    }

    inline int afla_flux(int sursa, int dest)
    {
        while (bfs(sursa, dest))
            continue;
        return flux_maxim;
    }
};
/*******************************/
/// FUNCTIONS

void ReadInput();
void Solution();
void Output();
/*******************************/
///-------------------------------------
inline void ReadInput()
{
    cin >> N >> M;
}
///-------------------------------------
inline void Solution()
{   
    Graf graf = Graf(N);

    int a, b, cap;
    for (int i = 0 ; i < M ; ++ i)
    {
        cin >> a >> b >> cap;

        a --; b --;
        graf.adauga_muchie(a, b, cap);
    }

    cout << graf.afla_flux(0, N - 1);
}
///-------------------------------------
inline void Output()
{

}
///-------------------------------------
int main()
{
    #ifndef LOCAL
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif
    ReadInput();
    Solution();
    Output();
    return 0;
}
