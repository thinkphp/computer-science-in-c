#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

void _merge(int *p, int lo, int m, int hi) {

     int  i = lo, j = m + 1, k = lo, *aux, it;

     aux = new int[hi - lo + 1];

     for(it = lo; it <= hi; ++it) aux[it-lo] = p[ it ];

     while(i <= m && j <= hi) {

           if(aux[i - lo] <= aux[j - lo]) {

                  p[k++] = aux[i++ - lo];
 
           } else {

                 p[k++] = aux[j++ - lo];
           }
     }      

     while(i<=m) p[k++] = aux[i++ -lo];

     while(j<=hi) p[k++] = aux[j++ -lo];

     delete aux;
}

void divideEtImpera(int *p, int lo, int hi) {

     if(lo == hi) return;

     else {

          int m = (lo + hi)>>1;  

          divideEtImpera(p, lo, m);

          divideEtImpera(p, m + 1, hi);

          _merge(p, lo, m, hi);  
     }      
}

void mergesort(int *p, int n) {

     divideEtImpera(p, 0, n - 1);
}

int main() {

    int *p, 
         n, 
         i;

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    cin>>n;

    p = new int[ n ];

    for(i = 0; i < n; ++i) cin>>*( p + i);

    mergesort(p, n);

    for(i = 0; i < n; ++i)  cout<<*( p + i)<<" ";

    delete p;

return(0);
}
