#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define integer int

using namespace std;

typedef unsigned long ulong;

template <class T>

class Sort 
{

      public:
      typedef vector<T> Vector;
      typedef void (*funcPtr)(Vector& vect);
      typedef typename Vector::difference_type Index;
      typedef typename Vector::size_type Size;

      static void MergeSort(Vector& vect) 
      {
             Sort::Helper::MergeSort(vect, 0, vect.size() - 1); 
      };

      class Helper 
      {
            public:

            static void MergeSort(Vector& vect, integer left, integer right) 
            {

                      if(left < right) 
                      {
                           int halfSize = (left + right) >> 1;                          

                           MergeSort(vect, left, halfSize);  

                           MergeSort(vect, halfSize + 1, right);

                           ulong merged[ right - left + 1 ];

                           int firstPos = left, 

                               k = left,

                               secondPos = halfSize + 1;

                           for(int i = left; i <= right; i++) merged[i - left] = vect[ i ];
                            
                           while(firstPos <= halfSize && secondPos <= right) {

                                 if(merged[firstPos - left] < merged[secondPos - left]) vect[k++] = merged[firstPos++ - left];

                                                   else               vect[k++] = merged[secondPos++ - left];
                           }
                             
                           while(firstPos <= halfSize)  vect[k++] = merged[firstPos++ - left];

                           while(secondPos <= right)  vect[k++] = merged[secondPos++ - left];                
                      }
            };
      };
};//end class Sort

integer main() 
{
    ulong n;
  
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

