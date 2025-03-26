#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

const int NMAX = 100002;

bitset <NMAX> vis;
vector <int> T[NMAX];
int max_depth, final_node;

void DFS (const int node, const int &depth) {

    vis[node] = 1;
    if (max_depth < depth) {
        final_node = node;
        max_depth = depth;
    }
    for (vector <int> :: iterator i = T[node].begin (); i != T[node].end (); ++i)
        if (!vis[*i])
            DFS (*i, depth + 1);

}

int main () {

    freopen ("darb.in", "r", stdin);
    freopen ("darb.out", "w", stdout);
    int N, i, a, b;
    scanf ("%d", &N);
    for (i = 1; i < N; ++i) {
        scanf ("%d%d", &a, &b);
        T[a].push_back (b);
        T[b].push_back (a);
    }
    DFS (1, 1);
    vis.reset ();
    DFS (final_node, 1);
    printf ("%d", max_depth);

}
© 2004-2025 Asociatia infoarenaPrima pagina
