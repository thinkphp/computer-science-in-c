#include <iostream>

using namespace std;
int n,m,i,j,k,a[101][101];
int main()
{
    cin>>n>>m;
    for(k=1;k<=m;k++)
    {
        cin>>i>>j;
        a[i][j]=1;
    }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][j]==0) a[i][j]=a[i][k]*a[k][j];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    return 0;

}
