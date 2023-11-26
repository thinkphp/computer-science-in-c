#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 510
#define inf 1e6

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pff(n,m) printf("%d %d",n,m)
#define pffl(n,m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int, int>

using namespace std;

int main() {
    int n;
    sf(n);
    int arr[n], a, b, k[n+1], j=0;
    for(int i = 0; i < n; i++)
        sf(arr[i]);
    a = *max_element(arr, arr + n);
    for(int i = 0; i < n; ++i) {
      if((a%arr[i])!=0 || count(arr, arr + n, arr[i]) == 2){
        k[j++] = arr[i];
      }
    }
    b = *max_element(k, k + j);
    pff(a,b);
    return(0);
}
