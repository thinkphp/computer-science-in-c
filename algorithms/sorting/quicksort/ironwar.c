#include <stdio.h>
#include <malloc.h>

typedef void (*fnPTR)(int*,int);

void _quicksort(int *p, int lo, int hi) {

     int piv = p[(lo+hi)>>1], 
         i = lo, 
         j = hi;     

         while(i <= j) {

               while(p[i]<piv) i++;               
               while(p[j]>piv) j--;

               if(i<=j) {
                  int x = p[i]^p[j];
                      p[i] = x^p[i];    
                      p[j] = x^p[j];
                      i++;j--;
               } 
         }  

         if(i < hi) _quicksort(p, i, hi);
         if(lo < j) _quicksort(p, lo, j);
}

void quicksort(int *v, int n) {

     _quicksort(v, 0, n - 1); 
}

int main() {
 
    int n, //number of elements
        *v, //vector
        i; //iterator for loop

    const char *fin = "algsort.in";
    const char *fout = "algsort.out";

    fnPTR sort = quicksort;

    freopen(fin, "r", stdin);

    freopen(fout, "w", stdout);
  
    scanf("%d", &n);

    v = (int*)malloc( sizeof(int) * n );

    for(i = 0; i < n; ++i) scanf("%d", v + i);

    sort(v, n); 

    for(i = 0; i < n; ++i) printf("%d ", *(v + i));

 return(0);
};