/**
 *
 *  @Author      Adrian Statescu <mergesortv@gmail.com>
 *  @description Cocktail Sort for 40 points.
 *  @License     MIT  
 *
 */

#include <cstdio>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

typedef unsigned int uint;

class Cocktail {

public:

uint arr[ MAXN ],

     n;

void read() {

     uint i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n); 
 
     for(i = 0; i < n; i++) scanf("%d", &arr[ i ]);

     fclose( stdin );

};

void sort() {

     uint i,

          j, 

          swapped;
     
     for(i = 0; i < n / 2; i++) {

         swapped = 0;

         for(j = i; j < n - 1 - i; j++) {

                 if( arr[ j ] > arr[j + 1] ) {

                     swap(arr + j, arr + j + 1);

                     swapped = 1;
                 }
         }

         for(j = n - 2 - i; j > i; j--) {

                 if( arr[ j ] < arr[j - 1] ) {

                     swap(arr + j, arr + j - 1);

                     swapped = 1;
                 }
         }

         if( !swapped )  break;
     }
};


void write() {

     uint i;

     freopen(FOUT, "w", stdout);
 
     for(i = 0; i < n; i++) printf("%d ", arr[ i ]);

     fclose( stdout );
};

private:

void swap(uint *a, uint *b) {

     int aux;
 
         aux = *a;

         *a = *b;

         *b = aux; 
};

};

int main() {

    Cocktail cocktail;

    cocktail.read();

    cocktail.sort();

    cocktail.write(); 

    return(0);
};
