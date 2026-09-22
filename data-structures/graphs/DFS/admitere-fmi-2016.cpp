#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("admitere-fmi-2016.in");
ofstream g("admitere-fmi-2016.out");

const int M=100005;
int n,m,x,y,viz[M],prieteni[M],k,ok;
vector < int > v[M];

void DFS(int nod)
{
    viz[nod]=1;
    for(auto vec : v[nod])
    {
        prieteni[vec]--;
        if(!viz[vec] && prieteni[vec]<k)
            DFS(vec);
    }
}

int main()
{
    f>> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
        f>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        prieteni[i]=v[i].size();
        g<< prieteni[i] << " ";
    }
    for(int i=1;i<=n;i++)
        if(!viz[i] && prieteni[i]<k)
            DFS(i);
    g<< '\n';
    for(int i=1;i<=n;i++)
        if(!viz[i])
        {
            ok=1;
            g<< i << " ";
        }
    if(!ok)
        g<< "NU";
    return 0;
}
