/**
 * ShellSort in action.
 */
#include <iostream>
#include <fstream>
#include <vector>
#define push push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

class Container {

      public:
      Container(int _n): n( _n ), k( 0 ) {vec = new int[ n ]; };

      ~Container(){}; 

      void add_to_container(int elem) {

           vec[ ++k ] = elem;
      };

      void sort() {

           _shellsort();  
      };


      friend std::istream &operator >> (std::istream &stream, const Container &ob ) {

             for(int elem, i = 0; i < ob.n; ++i) stream>>elem, ob.vec[ i ] = elem;

             return stream;
      }; 


      friend std::ostream &operator << (std::ostream &stream, const Container &ob ) {
              
             for(int i = 0; i < ob.n; ++i)
             {
                 stream<<ob.vec[i]<<" ";                    
             } 

             return stream;
      }; 

      private:
      int *vec;
      int n, 
          k;

      void _shellsort() {

           int gap = n - 1,

               g,

               i,

               j, temp;

               for(g = gap/2; g > 0; g /= 2 ) {

                   for(i = g; i < n; i++) {

                       temp = vec[ i ];

                       for(j = i; j >= g; j -= g) {

                           if( vec[ j - g ] > temp )

                               vec[ j ] = vec[ j - g ];

                           else 

                               break;
                       } 

                       vec[ j ] = temp;
                   }
               }  
      };
};

int main() {

    int i,

        n;

    std::ifstream fin( FIN );

    std::ofstream fout( FOUT );

    int elem;

    fin>>n; 

    Container cont( n );

    fin>>cont; 

    cont.sort();

    fout<<cont;

    fin.close();

    fout.close();

    return(0);
};
