#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

void combsort(int *p, int n) {

     float shrinkFactor = 1.3;

     int gap = n, i, swapped;

     while(gap > 1 || swapped) {

           if(gap > 1) gap = gap / shrinkFactor;

           swapped = 0;

           for(i = 0; i + gap < n; ++i) {

               if(*(p + i) > *(p + i + gap)) {

                    int tmp; 

                        tmp = *(p + i);

                        *(p + i) = *(p + i + gap);

                        *(p + i + gap) = tmp; 

                    swapped = 1;
               }
           }
     }
       
};

typedef void (*fnPTR)(int* p,int n);

int main() {

    int n, 
        *v, 
        i;

    fnPTR sort = combsort;

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    scanf("%d", &n);

    v = ( int* ) malloc ( sizeof( int ) * n );

    for(i = 0; i < n; ++i) scanf("%d", v + i);  

    sort(v, n);

    for(i = 0; i < n; ++i) printf("%d ", *(v + i));  

 return( 0 );
};