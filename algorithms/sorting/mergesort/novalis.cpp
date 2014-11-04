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
      };
};//end class Sort

int main() {

    int n;
  
    ifstream fin( FIN );

    ofstream fout( FOUT );

    fin>>n;

    vector<ulong> vect( n );

    for(ulong i = 0; i < n; i++) fin>>vect[i];   

    Sort<ulong>::funcPtr sorter = Sort<ulong>::MergeSort;

    sorter( vect );     

    ostream& target = fout;

    copy(vect.begin(), vect.end(), ostream_iterator<ulong>(target," "));
    
    fin.close(); 

    fout.close();

    return(0);
};

