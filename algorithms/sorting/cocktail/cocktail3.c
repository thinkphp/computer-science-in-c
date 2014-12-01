/**
 *
 *  @Author      Adrian Statescu <mergesortv@gmail.com>
 *  @description Cocktail Sort for 40 points.
 *  @License     MIT  
 *
 */

#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

typedef unsigned int uint;

uint arr[ MAXN ],

     n;

void read();
void write();
void cocktail();
void swap(int,int);
void swap2(uint*, uint*);

int main() {

    read();
   
    cocktail(); 

    write();
 
    return(0);
};

void read() {

     uint i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n); 
 
     for(i = 0; i < n; i++) scanf("%d", &arr[ i ]);

     fclose( stdin );

};

void cocktail() {

     uint i,

          j, 

          swapped;
     
     for(i = 0; i < n / 2; i++) {

         swapped = 0;

         for(j = i; j < n - 1 - i; j++) {

                 if( arr[ j ] > arr[j + 1] ) {

                     swap(j, j + 1);

                     swapped = 1;
                 }
         }

         for(j = n - 2 - i; j > i; j--) {

                 if( arr[ j ] < arr[j - 1] ) {

                     swap2(arr + j, arr + j - 1);

                     swapped = 1;
                 }
         }

         if( !swapped )  break;
     }
};

void swap(a, b) {

    uint aux;

         aux = arr[ a ] ^ arr[ b ]; 

         arr[ a ] = aux ^ arr[ a ];

         arr[ b ] = aux ^ arr[ b ];
};


void swap2(uint *a, uint *b) {

    uint aux;
 
         aux = *a;

         *a = *b;

         *b = aux; 
};

void write() {

     uint i;

     freopen(FOUT, "w", stdout);
 
     for(i = 0; i < n; i++) printf("%d ", arr[ i ]);

     fclose( stdout );
};