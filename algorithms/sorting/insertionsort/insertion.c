/**
 *  Insertion Sort Algorithm in C Language for 40 points.
 */

#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

typedef unsigned int uint;

//declare an array and number of elements all integers
uint vec[ MAXN ],
     n;

//prototypes function
void read();
void write();
void insertsort();

int main() {

    read();
    insertsort();
    write();
 
    return(0); 
};

void read() {

     uint i;

     freopen(FIN, "r", stdin);

     scanf("%d",&n);

     for(i = 0; i < n; i++) scanf("%d", &vec[ i ]);

     fclose( stdin );
};

void write() {

     uint i;

     freopen(FOUT, "w", stdout);

     for(i = 0; i < n; i++) printf("%d ", vec[ i ]);

     fclose( stdout );
};


void insertsort() {

     uint i,

          j, 

          aux;

     for(i = 1; i < n; i++) {

         if( vec[ i ] > vec[ i - 1 ] ) continue;

         aux = vec[ i ];

         j = i - 1;

         while(j >= 0 && vec[ j ] > aux) {

              vec[ j + 1] = vec[ j ];

              j--; 
         } 

         vec[ j + 1] = aux;
     }         

};