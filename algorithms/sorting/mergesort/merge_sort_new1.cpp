/**
 * Merge Sort in C++ Language.
 */
#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

typedef unsigned int uint;

class Container {

      public:
      Container( uint _size )
                : size ( _size ), 
                  arr( new uint[ _size ] ), 
                  _index( 0 )
      {         
      }

      void add_to_container( uint elem ) 
      {    
           arr[ _index++ ] = elem; 
      }

      void sorted() {

           _mergesort(0, size - 1);
      }

      friend ostream &operator << (ostream &stream, const Container &obj) 
      {

             for(int i = 0; i < obj.size; ++i) 
             {
                 stream<<obj.arr[ i ]<<" ";
             }

             return stream; 
      }

      ~Container( )
      {
         delete [] arr;   
      }

      private:
      uint *arr,
            size, 
           _index;

      void _merge(uint lo,uint mi,uint hi) {

           uint *acopy = new uint[ hi - lo + 1 ],

                i,

                j,

                k;

           for(i = lo; i <= hi; i++) acopy[ i - lo ] = arr[ i ];

           for(i = k = lo, j = mi + 1; i <= mi && j <= hi; k++) {

               if(acopy[ i - lo ] < acopy[ j - lo ]) {

                  arr[ k ] = acopy[ i++ - lo ];

               } else {

                  arr[ k ] = acopy[ j++ - lo ];
               }   
           }

           while( i <= mi ) {

                  arr[ k++ ] = acopy[ i++ - lo ];
           }

           while( j <= hi ) {

                  arr[ k++ ] = acopy[ j++ - lo ];
           }

           delete [] acopy;
      };

      void _mergesort(uint lo, uint hi) {

           //or lo == hi with else
           if(hi > lo) {

              uint mi = (lo + hi) >> 1; 

              _mergesort(lo, mi);

              _mergesort(mi + 1, hi);

              _merge(lo, mi, hi);
           }
      } 

};

int main() {

     uint size;

     ifstream fin( FIN );

     ofstream fout( FOUT );

     fin>>size;

     Container obj( size );

     for(int elem, i = 0; i < size; ++i) fin>>elem, obj.add_to_container( elem );

     obj.sorted();

     fout<<obj;

     fin.close();

     fout.close();
     
    return(0);
};