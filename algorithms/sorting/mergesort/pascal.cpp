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
      typedef typename Vector::difference_type Index;
      typedef typename Vector::size_type Size;

      static void MergeSort(Vector& vect) {

             Sort::Helper::MergeSort(vect, 0, vect.size() - 1); 
      };

      static void QuickSort(Vector& vect) {

             Sort::Helper::QuickSort(vect, 0, vect.size() - 1); 
      };

      static void ShellSort(Vector& vect) {

             int i,

                 j,

                 n = vect.size() - 1,

                 h = 1;  

             T aux;

                 do {

                    h = 3 * h + 1;

                 } while(h <= n);

                 do {

                    h /= 3;

                    for(j = h; j <= n; j++) {

                        aux = vect[ j ];

                        for(i = j - h; i >= 0 && vect[ i ] > aux; i -= h) {

                            vect[i + h ] = vect[ i ];
                        }       

                        vect[i + h ] = aux;
                    }  

                 } while( h > 0);
            
      };

      class Helper {

            public:

            static void MergeSort(Vector& vect, int left, int right) {

                   if(left == right) return;

                      else {

                           int halfSize = (left + right) >> 1;                          

                           MergeSort(vect, left, halfSize);  

                           MergeSort(vect, halfSize + 1, right);

                           Vector merged;

                           int firstPos = left,

                               secondPos = halfSize + 1;
                            
                           while(firstPos <= halfSize && secondPos <= right) {

                                 if(vect[firstPos] < vect[secondPos]) merged.push_back(vect[firstPos++]);

                                                   else               merged.push_back(vect[secondPos++]);
                           }
                             
                           while(firstPos <= halfSize)  merged.push_back(vect[firstPos++]);

                           while(secondPos <= right)  merged.push_back(vect[secondPos++]);                     

                           for(int i = left; i <= right; i++) 

                               vect[ i ] = merged[ i - left ];
                      }   

            };

            static void QuickSort(Vector& vect, Index left, Index right) {

                        Index i = left,

                              j = right, 

                              p = vect[( left + right ) >>1 ]; 

                        T aux;

                        while( i <= j ) {

                               while( vect[ i ] < p ) i++;

                               while( vect[ j ] > p) j--;

                               if( i <= j ) {

                                  swap(vect, i, j); 

                                  i++; j--;
                               }
                        } 

                        if( left < j ) QuickSort(vect, left, j);

                        if( i < right ) QuickSort(vect, i, right);
            };

            static void swap(Vector &vect, Index i, Index j) {

                 T aux;

                 aux = vect[i]^vect[j]; vect[i] = aux^vect[i];  vect[j] = aux^vect[j];
            }
      };

};//end class Sort

int main() {

    int n;
  
    ifstream fin( FIN );

    ofstream fout( FOUT );

    fin>>n;

    vector<ulong> vect( n );

    for(ulong i = 0; i < n; i++) fin>>vect[i];   

    Sort<ulong>::funcPtr sorter = Sort<ulong>::ShellSort;

    sorter( vect );     

    ostream& target = fout;

    copy(vect.begin(), vect.end(), ostream_iterator<ulong>(target," "));
    
    fin.close(); 

    fout.close();

    return(0);
};

