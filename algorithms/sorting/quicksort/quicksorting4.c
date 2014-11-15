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
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

typedef unsigned int uint;

uint arr[ MAXN ],

     n;

void read() {

     uint i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     for(i = 0; i < n; i++) scanf("%d", &arr[ i ]); 

     fclose( stdin );

};

void swap(uint *i, uint *j) {

     uint temp;

     temp = *i;

     *i = *j;

     *j = temp;
};

void _qsort(int low, int high) {

      int i = low,

          j = high,

          p = arr[ ( low + high ) >> 1 ];

          while(i <= j) {

                while(arr[ i ] < p) i++;

                while(arr[ j ] > p) j--;

                if( i <= j ) swap( &arr[ i++ ], &arr[ j-- ]);
          } 

          if(low < j) _qsort(low, j);

          if(i < high) _qsort(i, high);
};

void qsort() {

     _qsort(0, n - 1);
};

void write() {

   uint i;

   freopen(FOUT, "w", stdout);

   for(i = 0; i < n; i++) printf("%d ", arr[ i ]); 

   fclose( stdout );
};

int main() {

    read();

    qsort();

    write();

    return(0);
};