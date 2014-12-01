#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIN "sdo.in"
#define FOUT "sdo.out"
#define MAXN 500005

typedef unsigned int uint;

uint arr[ MAXN ],

     n;

void read() {

     uint i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     for(i = 0; i < n; i++) scanf("%d", &arr[ i ]); 

     fclose( stdin );
};

void swap(int i, int j) {

     int aux = arr[ i ] ^ arr[ j ];

         arr[ i ] = aux ^ arr[ i ]; 

         arr[ j ] = aux ^ arr[ j ];
};

int pivot(int li, int ls) {

    int i = 0, j = 1, aux, p = li + rand() % (ls - li);

    swap(li, p);

    while(li < ls) {

          if(arr[li] > arr[ls]) {

             swap(li,ls);
             aux = i;
             i = j; 
             j = aux; 
          }  
       li += i;
       ls -= j;
    }
 
    return li;
};

int _qsort(int li, int ls) {

     int p;

     if(li < ls) {

           p = pivot(li, ls);

           _qsort(li, p - 1);

           _qsort(p + 1, ls);
     }
};

int main() {

    read();

    //freopen(FOUT, "w", stdout);        

    srand(time(NULL));

    _qsort(0, n - 1);

    int i;

    for(i = 0; i < n; i++) printf("%d ", arr[ i ]);

    fclose( stdout );

    return(0);
};