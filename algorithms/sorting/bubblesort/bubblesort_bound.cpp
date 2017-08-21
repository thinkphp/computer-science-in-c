#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

void bubblesort(vector<int> &arr) {

     int bound = arr.size(),
 
         finished = 0, 

         t;

     while(!finished) {

            t = 0;

            for(int i = 0; i < bound - 1; ++i) {

                if(arr[ i ] > arr[ i + 1 ]){

                   int tmp = arr[ i ];

                       arr[ i ] = arr[ i + 1 ];

                       arr[ i + 1 ] = tmp;

                       t = i;
                }
            } 

            if( t != 0 ) bound = t + 1;

                  else 

                    finished = 1;
     } 
};

void printArray2(vector<int> arr) {

     for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) cout<<*it<<" ";

     cout<<endl; 
};

void printArray(vector<int> arr) {

     ofstream fout( FOUT );     

     for(auto i:arr) fout<<i<<" ";
};

int main() {

 vector<int> arr;
 int n, 
     elem; 

 ifstream fin(FIN);

 fin>>n;
 for(int i = 0; i < n; ++i) fin>>elem, arr.pb(elem);  

 //printArray(arr);
 bubblesort(arr);
 printArray(arr);

 return(0); 
};
