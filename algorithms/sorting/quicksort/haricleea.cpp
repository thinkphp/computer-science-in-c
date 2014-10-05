#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

typedef unsigned int uint;

pair<vector<uint>*, uint> read() {

      uint n;

      ifstream fin( FIN );

      fin>>n;      

      vector<uint>* vec = new vector<uint>(n);

      for(uint i = 0; i < n; i++) fin>>(*vec)[i];

      fin.close();

      return make_pair(vec, n);
};

void _qsort(vector<uint> *p, int li, int ls) {

      int i = li,

          j = ls,

          piv = (*p)[ ( li + ls ) >> 1 ], 

          aux;  

     while( i <= j ) {

           while( (*p)[ i ] < piv ) i++;

           while( (*p)[ j ] > piv ) j--;

           if( i <= j ) aux = (*p)[ i ] xor (*p)[ j ], (*p)[ i ] = aux xor (*p)[ i ], (*p)[ j ] = aux xor (*p)[ j ], i++, j--;           
     } 

     if( li < j ) _qsort(p, li, j);

     if( i < ls) _qsort(p, i, ls);
};

void sort(vector<uint> *p, uint n) {

       _qsort(p, 0, n - 1);    
};


void write(vector<uint> *p) {

     ofstream fout( FOUT );

     for(uint i = 0; i < (*p).size(); ++i) fout<<(*p)[ i ]<<" ";

     fout.close(); 
};

int main() {

    pair<vector<uint>*, int> p;

    p = read();

    sort(p.first, p.second);

    write( p.first );      

    delete p.first;

    return(0);
};

