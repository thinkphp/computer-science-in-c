#include <fstream>
#include <iostream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

class Container {

      public:
      //constructor of the class
      Container( int _n ): n( _n ){ }

      //destructor of the class
      ~Container() { }

      void sorted() {
 
           _quicksort(0, n - 1); 
      }

      void display() {

           std::ofstream fout( FOUT );

           for(int i = 0; i < n; ++i) fout<<vec[ i ]<<" ";
      }

      friend std::istream &operator >> (std::istream &stream, Container &obj) {

             int elem;
  
             for(int i = 0; i < obj.n; ++i) stream>>elem, obj.vec.push_back( elem );

             return stream;
      };     

      friend std::ostream &operator << (std::ostream &stream, const Container &obj) {

             for(int i = 0; i < obj.n; ++i) stream<<obj.vec[ i ]<<" ";

             return stream;
      };     

      private:
      std::vector<int> vec;
      int n;

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

                        int a = vec[ i ]; 
                        int b = vec[ j ];
                        a = a + b;
                        b = a - b;
                        a = a - b;
                        vec[ i ] = a;
                        vec[ j ] = b;
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