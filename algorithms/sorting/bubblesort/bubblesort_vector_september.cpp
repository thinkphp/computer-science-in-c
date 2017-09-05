#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

typedef vector<int>::iterator I;

void sort(vector<int> arr) {

     ofstream fout(FOUT);

     I last = arr.end() - 1;

     bool finished = false,
          swapped;    
 
     while(!finished) {

            swapped = false;

            for(I it = arr.begin(); it != last; ++it) 

                if((*it) > *(it+1)) {

                   swap(*it, *(it+1));

                   swapped = true;  
                }

            if(swapped) last--;

               else     finished = true;
     }

     for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) fout<<*it<<" ";
};

int main() {

    int n;

    ifstream fin(FIN);

    fin>>n;

    int arr[ n ];

    for(int i = 0; i < n; ++i) fin>>arr[i];

    sort(vector<int>(arr, arr + sizeof(arr)/sizeof(int))); 

 return(0);
};