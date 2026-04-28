#include <bits/stdc++.h>
using namespace std ;
ifstream f("hashuri.in");
ofstream g("hashuri.out");
#define mod 666013
int ind,n,cer,x;
std::vector <int> h[mod];
std::vector <int> :: iterator it;
std::vector <int> ::iterator gaseste(int x)
{
    for(it=h[ind].begin();it!=h[ind].end();it++)
        if(*it==x)return it;
    return it;
}
void adauga(int x)
{
    if(it==h[ind].end())h[ind].push_back(x);
}
void stergex()
{
    if(it!=h[ind].end())h[ind].erase(it);
}
bool afis(int x)
{
    if(it!=h[ind].end())return 1;
    return 0;
}
int main ()
{
    f>>n;
    while(n){
        f>>cer>>x;
        ind=x%mod;
        it=gaseste(x);
        if(cer==1)adauga(x);
        else if (cer==2)stergex();
        else g<<afis(x)<<'\n';
        n--;}
    return 0 ;
}
© 2004-2026 Asociatia infoarenaPrima pagina
