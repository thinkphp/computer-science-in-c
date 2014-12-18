/**
 * Merge Sort in C Language.
 */
#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"


typedef unsigned int uint;

uint *arr,
      size;

void _merge(uint left, uint middle, uint right) {

     uint i,

          j,

          k,

          *temp;

     temp = (uint*)malloc(sizeof(uint) * (right - left + 1));

     for(i = left; i <= right; i++) temp[ i - left ] = arr[ i ]; 

     for(i = k = left, j = middle + 1; i <= middle && j <= right;) {

         if(temp[ i - left ] < temp[ j - left ]) arr[ k++ ] = temp[ i++ - left ];

                             else

                                                 arr[ k++ ] = temp[ j++ - left ];                           
     }

     while( i <= middle ) {

            arr[ k++ ] = temp[ i++ - left ];       
     }

     while( j <= right ) {

            arr[ k++ ] = temp[ j++ - left ];       
     }

     free( temp );
};

void _mergesort(int left, int right) {

    if(right == left) return;

    else {

         uint middle = (left + right) >> 1;

         _mergesort(left, middle); 

         _mergesort(middle + 1, right);

         _merge(left, middle, right);
    } 
};

void sort() {

     _mergesort(0, size - 1); 
};

void read() {

  uint i;

  freopen(FIN, "r", stdin);

  scanf("%d", &size);

  arr = (uint*)malloc(sizeof(uint) * size);

  for(i = 0; i < size; ++i) scanf("%d", arr + i);

  fclose( stdin );
};

void display() {

  int i;

  freopen(FOUT, "w", stdout);

  for(i = 0; i < size; ++i) printf("%d ", *(arr + i));

  free( arr );

  fclose( stdout );
};

int main() {

  read(); 
  sort();
  display();

  return(0);
};