#include <fstream>
#include <iostream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

class Container {

      public:
      //constructor of the class
      Container( int _n ): n( _n ){

           vec = new int[ n ];

           k = 0;
      }
      //destructor of the class
      ~Container() { delete [] vec; }

      void added(int elem) {

           *( vec + k++ ) = elem;
      }

      void sorted() {
 
           _divide(0, n - 1); 
      }

      void display() {

           std::ofstream fout( FOUT );

           for(int i = 0; i < n; ++i) fout<<vec[ i ]<<" ";
      }

      friend std::istream &operator >> (std::istream &stream, const Container &obj) {

             int elem;
  
             for(int i = 0; i < obj.n; ++i) stream>>elem, *(obj.vec + i) = elem;

             return stream;
      };     

      friend std::ostream &operator << (std::ostream &stream, const Container &obj) {

             for(int i = 0; i < obj.n; ++i) stream<<obj.vec[ i ]<<" ";

             return stream;
      };     

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

               k = lo,

               *aux = new int[ hi - lo + 1 ];

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

    int n;

    std::ifstream fin( FIN );

    std::ofstream fout( FOUT );
 
    fin>>n;

    Container container( n );

    fin>>container;

    container.sorted();

    fout<<container;
 
    return(0);
};