#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

void _swap(vector<int> &vec, int a, int b) {

     int aux, x, y;

     x = vec[ a ];

     y = vec[ b ];

     aux = x ^ y;

     x = aux ^ x;

     y = aux ^ y;

     vec[ a ] = x;

     vec[ b ] = y;          
}

void bubblesort(vector<int> &vec, int n) {

     int aux, 
         swapped;


     do {

     swapped = 0;

     for(int i = 0; i < n - 1; ++i) {

         if(vec[ i ] > vec[ i + 1 ]) {

            _swap(vec, i, i + 1);  

            swapped = 1; 
         }
     }  

    }while( swapped );   
}

int main() {

    int i, 
        n, 
        elem;

    ifstream fin( FIN );
    ofstream fout( FOUT );

    vector<int> vec;

    fin>>n;

    for(i = 0; i < n; ++i) {
                            fin>>elem; 

                            vec.push_back( elem );
                           }

    bubblesort(vec, n); 

    for(i = 0; i < n; ++i) fout<<vec[ i ]<<" ";
          
};