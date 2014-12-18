/**
 * Merge Sort in C++ Language.
 */
#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

typedef unsigned int uint;

uint *arr,
      size;

void read();
void sort();
void display();
void _mergesort(uint, uint);
void _merge(uint, uint, uint); 

int main() {

    read();
    sort();
    display();
     
    return(0);
};

void read() {

     ifstream fin( FIN );

     fin>>size;
 
     arr = new uint[ size ];

     for(int i = 0; i < size; ++i) fin>>arr[i];

     fin.close();
};

void display() {

     ofstream fout( FOUT );

     for(int i = 0; i < size; ++i) fout<<arr[ i ]<<" ";
 
     //free the array
     delete [] arr;
  
     fout.close();
};

void sort() {

     _mergesort(0, size - 1);
};

void _mergesort(uint lo, uint hi) {

    if(lo < hi) {

       uint mi = (lo + hi) >> 1; 
  
            _mergesort(lo , mi);

            _mergesort(mi + 1, hi);

            _merge(lo, mi, hi);
    } 
};

void _merge(uint lo,uint m, uint hi) {

      uint *acopy = new uint[ hi - lo + 1 ],

           i,

           j,

           k;

      //make a copy of the interval
      for(i = lo; i <= hi; i++) acopy[ i - lo ] = arr[ i ];

      for(i = k = lo, j = m + 1; i <= m && j <= hi; ){

          if( acopy[ i - lo ] < acopy[ j - lo ] ) {

              arr[ k++ ] = acopy[i++ - lo];

          } else {

              arr[ k++ ] = acopy[j++ - lo];
          }
      }

      //copy the rest of the array if exists
      while( i <= m ) {

              arr[ k++ ] = acopy[i++ - lo];
      }  

      //copy the rest of the array if exists
      while( j <= hi ) {

              arr[ k++ ] = acopy[j++ - lo];
      }  

       //free the array
      delete [] acopy;       
}