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

    int n, elem,

        min, 

        posMin;

    fin>>n;

    for(int i = 0; i < n; ++i) fin>>elem, vec.push_back( elem );

    for(int i = 0; i < n - 1; ++i) {
      
        min = vec[ i ];

        posMin = i; 

        for(int j = i + 1; j < n; ++j) {

            if( vec[ j ] < min ) {

                min = vec[ j ];

                posMin = j; 
            }
        }    

        if(i != posMin) {

           vec[ posMin ] = vec[ i ];

           vec[ i ] = min; 
        }       
    }
       
    for(int i = 0; i < n; ++i) fout<<vec[ i ]<<" ";

    return(0);  
}