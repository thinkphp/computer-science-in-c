#include <bits/stdc++.h>

using namespace std;

ifstream f("fractii.in");
ofstream g("fractii.out");

const int N = 1000001;
int n,phi[N];
int64_t sol=1LL;
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        phi[i]=i;
    /// se calculeaza phi[i] pentru orice i de la 2 la n;
    for(int i=2;i<=n;i++)
    {
        if(phi[i]==i)///daca i este prim
            for(int j=i;j<=n;j+=i)
                phi[j]=phi[j]/i*(i-1);
        sol+=2*phi[i];
    }
    g<<sol<<'\n';
    return 0;
}
