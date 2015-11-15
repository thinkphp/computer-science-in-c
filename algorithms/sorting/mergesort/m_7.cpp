#include <fstream>
#include <iostream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:
      Container( int _n ): n( _n ){

           vec = new int[ n ];

           k = 0;
      }

      void added(int elem) {

           *( vec + k++ ) = elem;
      }

      void sorted() {
 
           _divide(0, n - 1); 
      }

      void display() {

           ofstream fout( FOUT );

           for(int i = 0; i < n; ++i) fout<<vec[ i ]<<" ";
      }

      private:
      int *vec;
      int n, k;

      void _divide(int lo,int hi) {

           if(lo == hi) return;

           int m;

               m = (lo + hi) >> 1;  

               _divide(lo, m);

               _divide(m + 1, hi);

           int i = lo,

               j = m + 1,

               k = lo;

           int *aux; 
  
               aux = new int[ hi - lo + 1 ];

               for(int it = lo; it <= hi; ++it) aux[ it - lo ] = vec[ it ];

               while(i <= m && j <= hi) {

                     if( aux[ i - lo ] <= aux[ j - lo ]) vec[ k++ ] = aux[ i++ - lo];

                          else 

                                              vec[ k++ ] = aux[ j++ - lo];
               }

               while(i <= m) vec[ k++ ] = aux[ i++ - lo];

               while(j <= hi) vec[ k++ ] = aux[ j++ - lo];

               delete [] aux; 
      } 


};

int main() {

    int n, 
        elem;

    ifstream fin( FIN );    
 
    fin>>n;

    Container container( n );

    for(int i = 0; i < n; ++i) fin>>elem, container.added( elem );

    container.sorted();

    container.display(); 

    return(0);
};