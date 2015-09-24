#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#define FIN "complex.in"
#define FOUT "complex.out"

using namespace std;

class Complex {

      public:
      int re, 
          im;

      float getModule() {
             
            return sqrt(re * re + im * im);
      } 
};

vector< Complex > vec;

int num;

void read() {

     Complex c;

     ifstream fin( FIN );

     fin>>num;

     for(int i = 0; i < num; ++i) {

         fin>>c.re>>c.im;

         vec.push_back( c );
     }

     fin.close();
}

void swap(int x, int y) {

     Complex temp;

     temp = vec[ x ];

     vec[ x ] = vec[ y ];

     vec[ y ] = temp;     
}

void sort() {

     int swapped;

     for(int i = num - 1; i > 0; i--) {

         swapped = 0;

         for(int j = 0; j < i; ++j) {

             if( vec[ j ].getModule()  > vec[ j + 1].getModule() ) {

                 swap( j, j + 1 );

                 swapped = 1;  
             }
         }  

         if( !swapped ) break;
     }
}

void solve() {

     sort();

     ofstream fout( FOUT );

     for(int j = 0; j < num; ++j) {

         fout<<vec[ j ].re<<" + i"<<vec[ j ].im<<endl; 
     }

     fout.close();
}

int main() {

    read();
    solve();

    return(0);
};