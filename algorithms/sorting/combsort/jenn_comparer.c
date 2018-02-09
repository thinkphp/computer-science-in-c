#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"

typedef int (*Comparer)(int, int);

typedef void (*fnPtr)(int*, int, Comparer);

int sort_asc(int a, int b) {

     if(a > b) return 1;

        else   return 0; 
}

void swap(int *a, int *b) {

     int tmp;

         tmp = *a;

         *a = *b;

         *b = tmp;    
}

void combsort(int *p, int n, Comparer comp) {

     float shrinkFactor = 1.3;
     int gap = n, swapped, i;

     while( gap > 1 || swapped ) {

            if(gap > 1) gap = gap / shrinkFactor;

            swapped = 0;

            for(i = 0; i + gap < n; ++i) {

                if( comp(p[i], p[i+gap]) > 0 ) {

                    swap(p + i, p + i + gap);

                    swapped = 1;
                }
            }
     }

};

int main() {

    int *v, n, i;

    const char *FOUT = "algsort.out";  

    fnPtr sort = combsort;

    freopen(FIN, "r", stdin); 

    freopen(FOUT, "w", stdout); 

    scanf("%d", &n);

    v = (int*)malloc( sizeof( int ) * n );

    for(i = 0; i < n; ++i) scanf("%d", &v[ i ]);

    sort(v, n, sort_asc);

    for(i = 0; i < n; ++i) printf("%d ", v[ i ]);     

    free( v );

 return(0);
};