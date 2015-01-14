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
      Container(uint _N): N( _N ) {}

      ~Container(){}

      void add_to_container(uint elem) {

           vec.push_back( elem );
      };

      void sorted() {

           _mergesort(0, N - 1);
      }; 

      friend std::ostream &operator << (std::ostream &stream, const Container &obj) {
                             
             std::vector<uint> sol = obj.vec;

             for(std::vector<uint>::iterator it = sol.begin(); it != sol.end(); ++it) {

                 stream<<*it<<" ";
             }
 
             return stream; 
      };

      private:
      std::vector<uint> vec;
      uint N;

      void _mergesort(uint lo, uint hi) {

           if(lo == hi) return;

           else {

                uint mi = (lo + hi) >> 1;

                _mergesort(lo, mi);

                _mergesort(mi + 1, hi);
      
                uint i = lo,

                     j = mi + 1;

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