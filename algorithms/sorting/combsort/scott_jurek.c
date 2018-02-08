#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

typedef void (*fnPointer)(int*, int);

void swap(int *a, int *b) {
 
     int tmp;

         tmp = *a;

         *a = *b;

         *b = tmp;    
}

void combsort(int* p, int n) {

     float shrinkFactor = 1.3;

     int swapped = 0, gap = n, i;

     while(gap > 1 || swapped) {

           if(gap > 1) gap = gap / shrinkFactor;

           swapped = 0;

           for(i = 0; i + gap < n; ++i) {

               if(p[ i ] > p[ i + gap]) {

                  swap( p + i, p + i + gap );

                  swapped = 1; 
               } 
           }
     }
};

int main() {

    int *p, n, i;

    fnPointer sort = combsort;

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    scanf("%d", &n);

    p = (int*)malloc(sizeof(int) * n);

    for(i = 0; i < n; ++i) scanf("%d", &p[i]);     

    sort(p, n);

    for(i = 0; i < n; ++i) printf("%d ", p[i]);

 return(0);
};