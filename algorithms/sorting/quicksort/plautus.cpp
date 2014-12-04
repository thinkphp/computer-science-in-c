#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

typedef unsigned long ulong;

template <class T>

class Sort {

      public:

      typedef vector<T> Vector;

      typedef void (*funcPtr)(Vector& vect);

      static void QuickSort(Vector& vect) {

             Sort::Helper::QuickSort(vect, 0, vect.size() - 1); 
      };

      class Helper {

            public:

            static void QuickSort(Vector& vect, int left, int right) {

                     int i = left,

                         aux,

                         j = right,

                         pivot = vect[ (left + right) >> 1 ]; 

                         while( i <= j ) {

                                while(vect[ i ] < pivot) i++;

                                while(vect[ j ] > pivot) j--;

                                if( i <= j ) { 

                                    aux = vect[ i ] ^ vect[ j ];

                                    vect[ i ] = aux ^ vect[ i ];

                                    vect[ j ] = aux ^ vect[ j ];

                                    i++; j--;
                                }
                         }

                         if(left < j) QuickSort(vect, left, j); 

                         if(i < right) QuickSort(vect, i, right);
            };
      };
};

int main() {

    int n;
  
    ifstream fin( FIN );

    ofstream fout( FOUT );

    fin>>n;

    vector<ulong> vect( n );

    for(ulong i = 0; i < n; i++) fin>>vect[i];   

    Sort<ulong>::funcPtr sorter = Sort<ulong>::QuickSort;

    sorter( vect );     

    ostream& target = fout;

    copy(vect.begin(), vect.end(), ostream_iterator<ulong>(target," "));
    
    fin.close(); 

    fout.close();

    return(0);
};

