/**
 *  Bubble Sort Algorithm for 40points
 */
#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int vec[MAXN],
    n;


void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d",&n);

     for(i = 0; i < n; i++) scanf("%d", &vec[ i ]);

     fclose( stdin );
};

void write() {

     int i;

     freopen(FOUT, "w", stdout);

     for(i = 0; i < n; i++) printf("%d ", vec[ i ]);

     fclose( stdout );
};


void bubblesort() {

     int i,
         j, 
         x; 

     for(i = n - 1; i >= 1; i--) {

         for(j = 0; j < i; j++) {

             if(vec[ j ] > vec[ j + 1 ]) {

               x = vec[ j ] ^ vec[ j + 1 ];
 
               vec[ j ] = x ^ vec[ j ];  

               vec[ j + 1 ] = x ^ vec[ j + 1 ];

             }           
         } 
     }
};

int main() {

    read();
    bubblesort();
    write();
 
    return(0); 
}