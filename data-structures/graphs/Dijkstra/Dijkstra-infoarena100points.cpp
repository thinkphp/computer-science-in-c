#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");
vector < pair <int, int> > G[50005];
set < pair <int, int> > s;
int d[50005];
bool viz[50005];
void dijkstra(){
    d[1] = 0;
    s.insert({0,1});
    while(!s.empty()){
        set < pair <int, int> > :: iterator it = s.begin();
        int nod = it->second;
        s.erase(it);
        if(viz[nod]) continue;
        viz[nod] = 1;
        for(int i = 0; i < G[nod].size(); ++i){
            int c = G[nod][i].first;
            int x = G[nod][i].second;
            if(!viz[x] && d[nod] + c < d[x]){
                d[x] = d[nod] + c;
                s.insert({d[x],x});
            }
        }
    }
}
int main()
{
    int n,m,i,u,v,c;
    fin >> n >> m;
    for(i = 1; i <= n; i++) d[i] = inf;
    for(i = 1; i <= m; i++){
        fin >> u >> v >> c;
        G[u].push_back({c,v});
    }
    dijkstra();
    for(i = 2; i <= n; i++) fout << (d[i] != inf ? d[i] : 0) << " ";
    fout << "\n";
    return 0;
}
