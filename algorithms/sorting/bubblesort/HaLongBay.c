#include <stdio.h>
#include <malloc.h>

typedef void (*fnPtr)(int*,int);

void bubblesort(int *p, int n) {

     int finished = 0, 
         swapped, 
         i, 
         last = n;

         while( !finished ) {

                 swapped = 0;

                 for(i = 0; i < last - 1; ++i) {

                     if( p[ i ] > p[i + 1] ) {

                         int tmp = p[i];

                             p[i] = p[i+1];

                             p[i+1] = tmp;

                             swapped = 1;
                     }
                 }

                 if( swapped ) last--;

                     else finished = 1;  
         }
}

int main() {

    int *v, 
         i, 
         n;   

    const char* FIN = "algsort.in";
    const char* FOUT = "algsort.out";

    fnPtr sort = bubblesort;
 
    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);


    scanf("%d", &n);

    v = (int*)malloc(sizeof( int ) * n);

    for(i = 0; i < n; ++i) scanf("%d", v + i); 

    sort(v, n); 

    for(i = 0; i < n; ++i) printf("%d ", *(v + i)); 

 return(0);
};