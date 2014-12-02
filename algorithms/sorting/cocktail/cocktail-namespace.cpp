/**
 *
 *  @Author      Adrian Statescu <mergesortv@gmail.com>
 *  @description Cocktail Sort for 40 points.
 *  @License     MIT  
 *
 */

#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

typedef unsigned int uint;

using namespace std;

namespace Cocktail {

          uint arr[ MAXN ],

          n;

void read() {

     uint i;

     ifstream fin( FIN );

     fin>>n;  
 
     for(i = 0; i < n; i++) fin>>arr[ i ];

     fin.close();
};


void swap(uint *a, uint *b) {

     int aux;
 
         aux = *a;

         *a = *b;

         *b = aux; 
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

     ofstream fout( FOUT );
 
     for(i = 0; i < n; i++) fout<<arr[ i ]<<" ";

     fout.close();
};

};//end class

int main() {

    Cocktail::read();  
    Cocktail::sort();
    Cocktail::write();

    return(0);
};
