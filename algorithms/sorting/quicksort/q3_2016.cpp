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
 
           _quicksort(0, n - 1); 
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

      void _quicksort(int lo, int hi) {

           int i = lo,
               j = hi,
               piv = vec[(i + j) >> 1];

               while( i <= j ) {

                     while(vec[i] < piv) i++;

                     while(vec[j] > piv) j--;

                     if( i <= j ) {

                        _swap(i, j);

                        i++;
                        j--;   
                     }                      
               } 
                
               if(lo < j) _quicksort(lo, j);

               if(i < hi) _quicksort(i, hi);
      } 

      void _swap(int i, int j) {

           int x;

           x = vec[ i ]; 
           vec[ i ] = vec[ j ];
           vec[ j ] = x;
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