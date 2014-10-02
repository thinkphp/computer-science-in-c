#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

typedef unsigned int uint;

pair<uint*, uint> read() {

      uint n;

      ifstream fin( FIN );

      fin>>n;      

      uint* vec = new uint[ n ];

      for(uint i = 0; i < n; i++) fin>>vec[i];

      fin.close();

      return make_pair(vec, n);
};

void _qsort(uint *p, int li, int ls) {

      int i = li,

          j = ls,

          piv = p[ ( li + ls ) >> 1 ], 

          aux;  

     while( i <= j ) {

           while( p[ i ] < piv ) i++;

           while( p[ j ] > piv ) j--;

           if( i <= j ) aux = p[ i ] xor p[ j ], p[ i ] = aux xor p[ i ], p[ j ] = aux xor p[ j ], i++, j--;           
     } 

     if( li < j ) _qsort(p, li, j);

     if( i < ls) _qsort(p, i, ls);
};

void sort(uint *p, uint n) {

     _qsort(p, 0, n - 1);    
};

void write(uint *p, uint n) {

     ofstream fout( FOUT );

     for(uint i = 0; i < n; ++i) fout<<p[ i ]<<" ";

     fout.close();
};

int main() {

    pair<uint*, int> p;

    p = read();

    sort(p.first, p.second);

    write( p.first, p.second);      

    delete p.first;

    return(0);
};

