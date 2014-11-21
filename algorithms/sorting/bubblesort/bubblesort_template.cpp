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

      static void Bubble(Vector& vect) {

             Sort::Helper::bubble(vect, vect.size());
      };
     
      class Helper {

            public:

            static void bubble(Vector& vect, int n) {

                   int swapped;

                   for(ulong i = 0; i < n - 1; i++) {

                       swapped = 0; 

                       for(ulong j = 0; j < n - 1 - i; j++) {

                                 if(vect[ j ] > vect[ j + 1 ]) {

                                    ulong temp;

                                    temp = vect[ j ] ^ vect[ j + 1 ];

                                    vect[ j ] = temp ^ vect[ j ];

                                    vect[ j + 1 ] = temp ^ vect[ j + 1 ];

                                    swapped = 1;  
                                 }
                       }
 
                       if(!swapped) break; 
                   } 
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

    Sort<ulong>::FuncPtr sorter = Sort<ulong>::Bubble;  

    sorter( vect );

    ostream& target = fout;
 
    copy(vect.begin(), vect.end(), ostream_iterator<ulong>(target," "));
    
    return(0);
};