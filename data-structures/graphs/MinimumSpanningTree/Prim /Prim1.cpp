#include <vector>
#include <queue>
#include <fstream>
#define dim 200001
#define inf 100000
using namespace std;
ifstream fin("apm.in");
ofstream fout("apm.out");

struct muchie{
    int nod, cost;
};

struct cmp{
    bool operator () (muchie a, muchie b)
    {
        return a.cost>b.cost;
    }
};

vector <muchie> l[dim];
priority_queue <muchie, vector <muchie>, cmp> pq;
int dp[dim], viz[dim], tata[dim];

int main()
{
    int n, m, x, y, c, i, sol=0;
    fin>>n>>m;
    for(i=1;i<=m;i++)
    {
        fin>>x>>y>>c;
        l[x].push_back({y, c});
        l[y].push_back({x, c});
    }
    for(i=1;i<=n;i++)
    {
        dp[i]=inf;
    }
    dp[1]=0;
    tata[1]=0;
    pq.push({1, 0});
    while(!pq.empty())
    {
        int nod=pq.top().nod;
        pq.pop();
        if(viz[nod]==1)
        {
            continue;
        }
        viz[nod]=1;
        for(i=0;i<l[nod].size();i++)
        {
            int vecin=l[nod][i].nod;
            int costvecin=l[nod][i].cost;
            if(dp[vecin]>costvecin&&viz[vecin]==0)
            {
                dp[vecin]=costvecin;
                tata[vecin]=nod;
                pq.push({vecin, costvecin});
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        sol+=dp[i];
    }
    fout<<sol<<"\n"<<n-1<<"\n";
    for(i=2;i<=n;i++)
    {
        fout<<i<<" "<<tata[i]<<"\n";
    }
    return 0;
}
