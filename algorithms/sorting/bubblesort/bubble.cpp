#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

void swap(vector<int> &vec, int a, int b) {

     int x = vec[ a ];

     int y = vec[ b ];

     x = x + y;

     y = x - y;

     x = x - y;

     vec[ a ] = x;

     vec[ b ] = y;   
}

int main() {

    ifstream fin(FIN);
    ofstream fout(FOUT);

    vector<int> vec;

    int n, 

        elem, 

        swapped = 0;

    fin>>n;

    for(int i = 0; i < n; ++i) fin>>elem, vec.push_back( elem );

    do {

       swapped = 0;

       for(int j = 0; j < n - 1; ++j) {

           if(vec[ j ] > vec[ j + 1 ]) {

              swap(vec, j, j + 1);

              swapped = 1;

           }
       }  

    }while( swapped );  
       
    for(int i = 0; i < n; ++i) fout<<vec[ i ]<<" ";

    return(0);  
}