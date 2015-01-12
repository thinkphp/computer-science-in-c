#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

using namespace std;

int newvec[ MAXN ];

void _merge(int vec[], int left, int middle, int right) {

         int i = left,

             j = middle + 1,

             k = 0;

          while(i <= middle && j <= right) {

                if(vec[ i ] <= vec[ j ]) {

                   newvec[ k++ ] = vec[ i++ ];

                } else {

                   newvec[ k++ ] = vec[ j++ ];
                }
          } 

          while(i <= middle) {

                   newvec[ k++ ] = vec[ i++ ];         
          } 

          while(j <= right) {

                   newvec[ k++ ] = vec[ j++ ];
          } 

          for(i = left; i <= right; i++) {

              vec[ i ] = newvec[ i - left ];
          } 
};

void _mergesort(int vec[], int left, int right) {

     if(left == right) return;

     else {

          int middle = (left + right) >> 1;

          _mergesort(vec, left, middle);    

          _mergesort(vec, middle + 1, right);

          _merge(vec, left, middle, right);
     }   
};

void sort(int vec[], int N) {

     _mergesort(vec, 0, N - 1); 
}; 

void write(int vec[], int N) {
 
     ofstream fout( FOUT );

     for(int i = 0; i < N; i++) fout<<vec[ i ]<<" ";

     fout.close();
};

int main() {

    int vec[ MAXN ],
        N;

     ifstream fin( FIN );

     fin>>N; 

     for(int i = 0; i < N; i++) fin>>vec[ i ];

     fin.close();
     
     sort( vec, N );

     write( vec, N );               
 
    return(0);         
};