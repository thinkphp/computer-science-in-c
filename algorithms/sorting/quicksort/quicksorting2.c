/**
 *  Description: Algorithms and Data Structures.
 *               Quick Sort is a fast sorting algoritm, which is used not only for educational purposes,
 *               but widely applied in practice. On the average, it has O(n log n) complexity, making quicksort suitable for sorting big data volumes.
 *               The divide-and-conquer strategy is used. Choose a pivot value. Partition. Rearrange elements in such way, that all elements which is lesser than the pivot
 *               go to the left part of the array and all elements greater than the pivot, to the right part of the array. Values equal to the pivot can stay
 *               in any part of the array.Apply quicksort algoritm recursively to the left and the right parts. 
 *
 *  Author     : Adrian Statescu <mergesortv@gmail.com>
 *
 *  License    : Feel Free to use and distribute as long as this note is kept.
 */
#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

typedef unsigned int uint;

uint n;

uint* read() {

     uint i, 

          *arr;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     arr = (uint*)malloc(n*sizeof(uint)); 

     for(i = 0; i < n; i++) scanf("%d", &arr[ i ]); 

     fclose( stdin );

     return arr;
};

void swap(uint *i, uint *j) {

     uint temp;

     temp = *i;

     *i = *j;

     *j = temp;
};

void write(uint *arr) {

     uint i;

     freopen(FOUT, "w", stdout);

     for(i = 0; i < n; i++) printf("%d ", arr[ i ]); 

     fclose( stdout );
};

void _quicksort(uint *p, uint li, uint ls) {
     
     int i = li,

         j = ls,

         piv = p[ ( li + ls) >> 1 ];

     while(i <= j) {

           while( p[ i ] < piv ) i++; 

           while( p[ j ] > piv ) j--;

           if( i <= j) {

             swap(p + i, p + j);

             i++; j--;
           }  
     }

     if(li < j) _quicksort(p, li, j); 

     if(i < ls) _quicksort(p, i, ls);  
}

void quicksort(uint *p) {

     _quicksort(p, 0, n - 1);            
};

int main() {

    uint *arr;
          
    arr = read();

    quicksort( arr ); 

    write( arr );

    return(0);
};