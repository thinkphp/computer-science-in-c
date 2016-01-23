/**
 * ShellSort in action.
 */
#include <iostream>
#include <fstream>
#include <vector>
#define push push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:
      Container(int _n, vector<int> v): n( _n ), vec( v ){};

      ~Container(){}; 


      void sort() {

           _shellsort();  
      };

      friend ostream &operator << (ostream &stream, const Container &ob ) {

             vector<int> vec = ob.vec; 

             for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)                
            
                 stream<<*it<<" ";

             return stream;
      }; 

      private:
      vector<int> vec;
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

    int n, _n;

    std::ifstream fin( FIN );

    std::ofstream fout( FOUT );

    int elem;

    vector<int> vec;

    vector<int>::iterator it;

    fin>>n;
 
    _n = n; 

    it = vec.begin();

    while( n-- ) {

           fin>>elem;

           it = vec.insert(it, elem);
    } 

    Container cont( _n, vec);

    cont.sort();

    fout<<cont;

    fin.close();

    fout.close();

    return(0);
};

