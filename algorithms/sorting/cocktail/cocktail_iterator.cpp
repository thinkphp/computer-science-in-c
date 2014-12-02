/**
 *
 *  @Author      Adrian Statescu <mergesortv@gmail.com>
 *  @description Cocktail Sort for 40 points. 
 *  @License     Free to use and distribute as long as this note is kept.  
 *  
 */

#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

typedef unsigned int uint;

using namespace std;

vector<uint> arr;
uint n;

void read() {

     uint i, 

          elem;

     ifstream fin( FIN );

     fin>>n;  
 
     for(i = 0; i < n; i++) fin>>elem, arr.push_back( elem );

     fin.close();
};


void swap(uint a, uint b) {

    uint aux;
 
         aux = arr[ a ] ^ arr[ b ];

         arr[ a ] = aux ^ arr[ a ];

         arr[ b ] = aux ^ arr[ b ];
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

                     swap(j, j - 1);

                     swapped = 1;
                 }
         }

         if( !swapped )  break;
     }
};

void write() {

     uint i;

     ofstream fout( FOUT ); 

     for(vector<uint>::iterator it = arr.begin(); it != arr.end(); ++it) {

         fout<<(*it)<<" ";
     }

     fout.close();
};

int main() {

    read();
    cocktail();
    write(); 

    return(0);
};
