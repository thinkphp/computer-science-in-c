#include<iostream>
using namespace std;
int main()
{
    int m,n,r,q,sum;
    cin>>m;
    for(int i = 1; i <= m; ++i) {
        cin>>n;
        sum = 0;
        q = n;
    while(n)
    {
        r=n%10;
        sum += r*r*r;
        n=n/10;
    }
    if(sum==q)cout<<"Yes\n";
    else cout<<"No\n";
    }
    return 0;
}
