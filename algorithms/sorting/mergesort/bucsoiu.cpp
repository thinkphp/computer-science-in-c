#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

//declared a pointer to function 
typedef void (*sorter)(int*,int);

void _merge(int *p, int lo, int m, int hi) {

     int i = lo, j = m + 1, k = 0, *aux;

     aux = new int[hi - lo + 1];

     while(i <= m && j <= hi) {

           if(p[i] <= p[j]) aux[k++] = p[i++];

              else aux[k++] = p[j++];  
     }

     while(i<=m) aux[k++] = p[i++];

     while(j<=hi) aux[k++] = p[j++];

     k = 0;

     for(i = lo; i <= hi; ++i) p[i] = aux[k++];

     delete [] aux;  
}

void _divideEtImpera(int *p, int lo, int hi) {

     if(lo == hi) return;

     else {

          int m = (lo+hi)>>1; 

           _divideEtImpera(p, lo, m);

           _divideEtImpera(p, m + 1, hi);

           _merge(p, lo, m, hi);
     }     
}


void mergesort(int *p, int n) {
 
     _divideEtImpera(p, 0, n - 1);     
}

void bubble(int *p, int n) {
 
     int finished = 0, swapped, size = n, i;

     while(!finished) {

           swapped = 0;

           for(i = 0; i < size - 1; ++i) {

               if(p[i] > p[i+1]) {
 
                  int holder = p[i];

                      p[i] = p[i+1];

                      p[i + 1] = holder;

                      swapped = 1; 
               } 
           }

           if( swapped ) size--; else finished = 1;
     }  
}

int main() {

   int *p, //pointer to integer
        n, //number of elements
        i; //an iterator for loop

   sorter s = mergesort;

   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);

   cin>>n;

   p = new int[n];

   for(i = 0; i < n; ++i) cin>>*(p+i);

   s(p, n); 
 
   for(i = 0; i < n; ++i) cout<<*(p + i)<<" ";

   cout<<endl;

   delete [] p;
  
return(0);
}
