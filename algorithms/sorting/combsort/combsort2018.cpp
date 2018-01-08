#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template<class T>
class Sort {

      public:
      typedef vector<T> Vector;
      typedef void (*fnPtr)(Vector &vec);    

      static void Comb(Vector &vec) {

             Sort::Helper::CombSort(vec, vec.size());  
      };

       
      public: 
      class Helper {

            public:
            static void CombSort(Vector &vec, int n) {

                   int gap = n, swapped = 0;

                   float shrinkFactor = 1.3;

                   while(gap > 1 || swapped) {

                         if(gap > 1) gap = gap / shrinkFactor; 

                         swapped = 0;
 
                         for(int i = 0; i + gap < n; ++i) 

                             if(vec[i] > vec[i+gap]) {

                                 int tmp = vec[i];

                                     vec[i] = vec[i+gap];

                                     vec[i+gap] = tmp;

                                     swapped = 1; 
                             }  
                   } 
                     
            };
      };
};

int main() {

    const char *inFile = "algsort.in";
    const char *outFile = "algsort.out";

      
    ifstream fin( inFile ); 
    ofstream fout( outFile ); 

    if(!inFile || !outFile) {
        cerr<<"Error opening one of "<<inFile<<" or "<<outFile<<endl;
        return -1;
    }

    unsigned int n;

    fin>>n;

    Sort<int>::Vector vec(n);

    for(int i = 0; i < n; ++i) fin>>vec[i];

    Sort<int>::fnPtr sorter = Sort<int>::Comb;

    sorter( vec );

    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) fout<<*it<<" "; 
 
 return(0);
};
