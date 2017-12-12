#include <iostream>
#include <vector>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

void CombSortAlgorithm(vector<int> &arr) {

     int n = arr.size(), 

         gap = n;

     float shrinkFactor = 1.3;

     bool swapped = false;

     while(gap > 1 || swapped) {

           if(gap > 1) gap = (gap / shrinkFactor);

           swapped = false;

           for(int i = 0; i + gap < n; ++i) {

               if(arr[ i ] > arr[ i + gap ]) {

                  int tmp = arr[ i ];  
                      arr[ i ] = arr[ i + gap];
                      arr[ i + gap] = tmp;
                      swapped = true;
               }
           }   
     }

};

//pointer to Function
typedef void (*ptrFn)(vector<int> &vec);

int main() {

    ifstream fin(FIN);
    ofstream fout(FOUT);

    vector<int> arr;
    int n, 
        item;

    fin>>n;

    for(int i = 0; i < n; ++i) fin>>item, 
                               arr.push_back( item );
     
    ptrFn sort = CombSortAlgorithm;

    sort( arr );

    for(vector<int>::iterator it = arr.begin(); it!=arr.end(); ++it) fout<<*it<<" ";

    return(0);
}