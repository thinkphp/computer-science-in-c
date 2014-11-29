/**
 *
 *  Selection By min in C++ Language for 40 cents.
 *
 */

#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

using namespace std;

typedef unsigned int uint;

uint arr[ MAXN ],

     n;

class SelectionByMin {

     public:

     uint *p,

           N;
           
     SelectionByMin(uint arr[], uint n) {

           p = arr;

           N = n;  

           selectbymin();             

           write();  
     }

     void selectbymin() {

          uint i,

               j, 

               min;
  
          for(i = 0; i < N - 1; i++) {

              min = i;

              for(j = i + 1; j < N; j++) {

                  if(p[ j ] < p[ min ]) min = j;
              } 

              if(min != i) swap(min, i);
          }   
     }; 

     private:

     void swap(int x,int y) {

          uint xo;

               xo = arr[ x ] ^ arr[ y ];    

               arr[ x ] = xo ^ arr[ x ];

               arr[ y ] = xo ^ arr[ y ]; 
     };

     void write() {

          ofstream fout( FOUT );
 
          for(uint i = 0; i < n; i++) fout<<p[ i ]<<" ";

          fout.close();
     };
};

void read() {

     ifstream fin( FIN );

     fin>>n;
 
     for(uint i = 0; i < n; i++) fin>>arr[ i ];

     fin.close();
};

int main() {

    read();

    SelectionByMin sort(arr, n);    

  return(0);
};
