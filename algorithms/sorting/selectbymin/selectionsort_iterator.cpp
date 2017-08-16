#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

template <class AccessIterator> 
void selectionsort(AccessIterator first, AccessIterator last) {

     AccessIterator i,
                    j,
                    f = first, 
                    n = last,                    
                    min;
 
     for(i = f; i != n - 1; ++i) {

         AccessIterator pos = i; 

         min = i;

         for(j = i + 1; j != n; j++) {
 
             if(*j < *min) {

                 min = j;        
             }
         }

         swap(*min, *pos);
     }
     
};

typedef vector<int>::iterator I;

int main() {   

    int elem, n;
    vector<int> vec;

    ifstream fin(FIN);

    ofstream fout(FOUT);

    fin>>n;

    for(int i = 0; i < n; ++i) fin>>elem, vec.push_back( elem ); 

    selectionsort<I>(vec.begin(), vec.end());
 
    for(int i = 0; i < n; ++i) fout<<vec[i]<<" ";

    return(0);
};