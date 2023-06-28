#include <iostream>
using namespace std;
 
int n,a[100000], m , b[100000], p, c[200000], o, d[100000], i, j;
 
int main()
{
    cin>>n;
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for (i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    i = 0 , j = 0;
    p = 0;
    while(i < n && j < m)
        if(a[i] < b[j])
            c[p ++] = a[i ++];
        else if(a[i] >b[j])
            c[p ++] = b[j ++];
        else
            d[o++] = a[i++];
    while(i < n)
        c[p ++] = a[i ++];
    while(j < m)
        c[p ++] = b[j ++];
    for (i = 0; i < p; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
    for(i=0; i<o; i++)
    {
        cout<<d[i]<<" ";
    }
    return 0;
}
