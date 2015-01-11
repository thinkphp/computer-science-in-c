/**
 *  @author      Adrian Statescu <mergesortv@gmail.com>
 *  @description Merge Sort in Action.
 *  @License     MIT 
 */
#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define push push_back

class Container {

      public:
      Container(int _N): N( _N ) {}

      ~Container(){}

      void add_to_container(int elem) {

           vec.push( elem );
      };

      void sorted() {

           _mergesort(0, N - 1);
      }; 

      friend std::ostream &operator << (std::ostream &stream, const Container &obj) {

             for(auto &el : obj.vec) {
         
                 stream<<el<<" "; 
             }  

             return stream; 
      };

      private:
      std::vector<int> vec;
      int N;  

      void _mergesort(int lo, int hi) {

           if(lo == hi) return;

           else {

                int mi = (lo + hi) >> 1;

                _mergesort(lo, mi);

                _mergesort(mi + 1, hi);
      
                int i = lo,

                    j = mi + 1;

                    std::vector<int> merged;

                    while(i <= mi && j <= hi) {

                          if(vec[ i ] < vec[ j ]) merged.push( vec[ i++ ] );

                                      else
                                                  merged.push( vec[ j++ ] );  
                    }

                    while(i <= mi) {

                          merged.push( vec[ i++ ] );
                    }                

                    while(j <= hi) {

                          merged.push( vec[ j++ ] );
                    }                

                    for(int r = lo; r <= hi; r++) vec[ r ] = merged[ r - lo ];
           }
      };
     
};

int main() {

    int N, 

        elem;

     std::ifstream fin( FIN );

     std::ofstream fout( FOUT );

     fin>>N; 

     Container container( N );

     for(int i = 0; i < N; ++i) fin>>elem, 

                                container.add_to_container( elem ); 

     container.sorted( );

     fout<<container; 

     fin.close();
     
    return(0);         
};