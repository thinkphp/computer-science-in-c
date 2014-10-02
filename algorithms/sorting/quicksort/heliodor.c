/**
 *  Author      : Adrian Statescu <mergesortv@gmail.com>
 *  Description : QuickSort in C Language.
 *  License     : MIT
 *  Feel free to use and distribute as long as this note is kept.
 */
#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

typedef unsigned int uint;

//function prototypes
uint* read();
void _qsort(uint*,int,int);
void sort(uint*);
void write();

int main() {

    uint* p;

    p = read( );

    sort( p );

    write( p );

    free( p );

    return( 0 );
};

uint* read() {

      uint i, 

           n, 

           *vec;      

      FILE *fin = fopen(FIN, "r");

      fscanf(fin, "%d", &n);

      vec = (uint*) malloc(n * sizeof(uint));

      for(i = 1; i <= n; i++) fscanf(fin, "%d", &vec[i]);

      vec[ 0 ] = n;

      fclose( fin );

      return vec;
};

void _qsort(uint *p, int li, int ls) {

      int i = li,

          j = ls,

          piv = p[ ( li + ls ) >> 1 ], 

          aux;  

     while( i <= j ) {

           while( p[ i ] < piv ) i++;

           while( p[ j ] > piv ) j--;

           if( i <= j ) aux = p[ i ] ^ p[ j ], p[ i ] = aux ^ p[ i ], p[ j ] = aux ^ p[ j ], i++, j--;           
     } 

     if( li < j ) _qsort(p, li, j);

     if( i < ls) _qsort(p, i, ls);
};

void sort(uint *p) {

     _qsort(p, 1, p[ 0 ]);    
};

void write(uint *p) {

     uint i;

     FILE *fout = fopen(FOUT, "w");

     for(i = 1; i <= p[ 0 ]; ++i) fprintf(fout, "%d ", p[ i ]);

     fclose( fout );
};


