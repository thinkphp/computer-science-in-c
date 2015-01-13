/**
 *  @author      Adrian Statescu <mergesortv@gmail.com>
 *  @description Merge Sort in Action.
 *  @License     MIT 
 */
#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 500005
#define FIN "algsort.in"
#define FOUT "algsort.out"

typedef unsigned int uint;

class Container {

      public:
      Container(uint _N): N( _N ), contor( 0 ) {}

      ~Container(){}

      void add_to_container(uint elem) {

           vec[ contor++ ] = elem;
      };

      void sorted() {

           _mergesort(0, N - 1);
      }; 

      friend std::ostream &operator << (std::ostream &stream, const Container &obj) {

             for(int i = 0; i < obj.N; i++) {
         
                 stream<<obj.vec[ i ]<<" "; 
             }  

             return stream; 
      };

      private:
      uint vec[ MAXN ],
           N, 
           contor;  

      void _mergesort(uint lo, uint hi) {

           if(lo == hi) return;

           else {

                uint mi = (lo + hi) >> 1;

                _mergesort(lo, mi);

                _mergesort(mi + 1, hi);
      
                uint i = lo,

                     j = mi + 1, 

                     k = 0;

                     std::vector<uint> merged;

                    while(i <= mi && j <= hi) {

                          if(vec[ i ] < vec[ j ]) merged.push_back(vec[ i++ ]);

                                      else

                                                  merged.push_back(vec[ j++ ]);
                    }

                    while(i <= mi) {

                          merged.push_back(vec[ i++ ]);                          
                    }                

                    while(j <= hi) {

                          merged.push_back(vec[ j++ ]);
                    }                


                    for(uint r = lo; r <= hi; r++) vec[ r ] = merged[ r - lo ];
           }
      };
     
};

int main() {

    uint N, 

         elem;

     std::ifstream fin( FIN );

     std::ofstream fout( FOUT );

     fin>>N; 

     Container container( N );

     for(uint i = 0; i < N; ++i) fin>>elem,

                                 container.add_to_container( elem ); 

     container.sorted( );

     fout<<container; 

     fin.close();
     
    return(0);         
};