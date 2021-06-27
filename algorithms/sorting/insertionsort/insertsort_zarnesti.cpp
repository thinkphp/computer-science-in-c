#include <iostream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
 
using namespace std;
 
void insertsort(int *p, int n) {
     int lo, hi, m;
     for(int i = 1; i < n; ++i) {
         lo = 0;
         hi = i - 1;
         int holder = p[i];
         while(lo <= hi) {
               m = (lo + hi) >> 1;
               if(holder > p[m]) {
                  lo = m + 1;
               } else {
                  hi = m - 1;
               }
         }
         for(int j = i - 1 ; j >= lo - 1; j--)
 
            p[j+1] = p[j];
 
         p[lo] = holder;
     }
}
 
int main(int argc, char const *argv[]) {
 
  int n;
 
  freopen(FIN, "r", stdin);
 
  freopen(FOUT, "w", stdout);
 
  cin>>n;
 
  int *v;
 
  v = new int[n+1];
 
  for(int i = 0; i < n; ++i) cin>>v[i];
 
  insertsort(v, n);
 
  for(int i = 0; i < n; ++i) cout<<v[i]<<" ";
 
  free(v);
 
  return 0;
}
