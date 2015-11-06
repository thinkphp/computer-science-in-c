#include <fstream>
#include <iostream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

ofstream fout( FOUT );

class Container {
     
      public: 
      Container(int _N): N(_N){}

      void added( int elem ) {

           vec.push_back( elem ); 
      }

      void display() {

           for(int i = 0; i < N; ++i) fout<<vec[ i ]<<" "; 
      }     

      void sorted() {

           _quick(0, N - 1); 
      }

      void _quick(int lo, int hi) {

           int piv = vec[ ( lo + hi ) >> 1 ],

               i = lo,

               j = hi;

               while( i <= j ) {

                    while( vec[ i ] < piv) i++; 
                    while( vec[ j ] > piv) j--;

                    if( i <= j ) {

                        _swap(i, j);

                        i++; j--; 
                    }
               }

               if(lo < j) _quick(lo, j); 
               if(hi > i) _quick(i, hi);
               
      } 

      private:
      vector<int> vec;
      int N;

      void _swap(int i, int j) {

           int x = vec[ i ] ^ vec[ j ]; 

               vec[ i ] = vec[ i ] ^ x;

               vec[ j ] = vec[ j ] ^ x;
      }
};

int main() {

     int N, 
         elem;

     ifstream fin( FIN );

     fin>>N;

     Container container( N );

     for(int i = 0; i < N; ++i) fin>>elem, container.added(elem); 

     container.sorted();

     container.display();
 
     return(0);
}