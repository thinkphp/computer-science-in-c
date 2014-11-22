#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

typedef unsigned int  uint;
typedef unsigned long ulong;

template<class T>

class Sort {

      public:

      typedef vector<T> Vector; 

      typedef void (*FuncPtr)(Vector& vect);

      typedef typename Vector::size_type Size; 

      static void ShellSort(Vector& vect) {

             Sort::Helper::shellsort(vect, vect.size());
      };
     
      class Helper {

            public:

            static void shellsort(Vector& vect, int n) {

                   ulong i,

                         j,

                         aux, 

                         h;

                         do {

                           h = 3 * h + 1;
                        
                         } while( h <= n);

                         do {

                            h /= 3;

                            for(j = h; j < n; j++) {

                                aux = vect[ j ];

                                for(i = j; i >= h; i -= h) {

                                        if(vect[ i - h ] > aux) {

                                           vect[ i ] = vect[ i - h ];   

                                        } else break;
                                } 

                                vect[ i ] = aux; 
                            }  

                         } while( h > 1); 
            }  
      };
};

int main() {

    ifstream fin( FIN ); 

    ofstream fout( FOUT ); 
    
    ulong n, 

          elem; 

    fin>>n;

    vector<ulong> vect(n);

    for(ulong i = 0; i < n; i++) fin>>vect[i];

    if(!fin || !fout) {

           cerr<<"Error opening one of";
    }

    Sort<ulong>::FuncPtr sorter = Sort<ulong>::ShellSort;  

    sorter( vect );

    ostream& target = fout;
 
    copy(vect.begin(), vect.end(), ostream_iterator<ulong>(target," "));
    
    return(0);
};