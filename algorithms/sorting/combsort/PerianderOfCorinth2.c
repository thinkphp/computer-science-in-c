#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

void combsort(int *p, int n) {

     int gap = n, 

         swapped = 0, 

         i; 

     float shrinkFactor = 1.3; 

     while(gap > 1 || swapped) {
       
           if(gap > 1) gap = gap / shrinkFactor;

           swapped = 0;
  
           for(i = 0; i + gap < n; ++i) {

               if(p[ i ] > p[ i + gap ]) {

                  int tmp = p[ i ];

                      p[ i ] = p[ i + gap ];

                      p[ i + gap ] = tmp;

                      swapped = 1;
               }
           }  
     }
};

int main() {

    int *vec, 

        n, 

        i;

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    scanf("%d", &n);

    vec = (int*)malloc(sizeof(int) * n);

    for(i = 0; i < n; ++i) scanf("%d", &vec[i]);

    combsort(vec, n); 

    for(i = 0; i < n; ++i) printf("%d ", vec[i]);

    free( vec );
 
 return(0);
};