#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll c=0;
vector<pair<char,char>> v;
 
void towerhonoi(ll n,char from,char to,char aux)
{
    if(n==1)
    {
       // cout<<from<<" "<<to<<"\n";
       v.push_back(make_pair(from,to));
        c++;
    }
    else
    {
        towerhonoi(n-1,from,aux,to);
        //cout<<from<<" "<<to<<"\n";
        v.push_back(make_pair(from,to));
        c++;
        towerhonoi(n-1,aux,to,from);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n,i;
    cin>>n;
 
    towerhonoi(n,'1','3','2');
    cout<<c<<"\n";
    for(i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
 
    return 0;

}
