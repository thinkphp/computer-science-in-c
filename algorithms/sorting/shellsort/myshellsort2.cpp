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
      Container(int _n): n( _n ) {};

      ~Container(){}; 

      void add_to_container(int elem) {

           vec.push( elem );            
      };

      void sort() {

           _shellsort();  
      };

      friend std::ostream &operator << (std::ostream &stream, const Container &ob ) {
              
             //compile with g++ -std=c++0x name.cpp -o s
             for(auto el: ob.vec) {

                 stream<<el<<" ";                    
             } 

             return stream;
      } 

      private:
      std::vector<int> vec;
      int n;

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

    for(i = 1; i <= n; i++) fin>>elem, cont.add_to_container( elem );

    cont.sort();

    fout<<cont;

    fin.close();

    fout.close();

    return(0);
};
