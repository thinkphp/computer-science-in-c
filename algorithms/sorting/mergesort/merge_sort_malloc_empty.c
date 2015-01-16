/**
 * Filename    : mergesort.c
 * Description : Merge Sort in C Language.
 * License     : MIT
 * Compile     : gcc mergesort.c -o merge
 */

#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define integer int
#define empty_set void

typedef unsigned int uint;

empty_set read();
empty_set display();
empty_set sort();
empty_set _mergesort(int, int);

uint *arr,
      size;

integer main() {

  read(); 
  sort();
  display();

  return(0);
};

empty_set read() {

  uint i;

  freopen(FIN, "r", stdin);

  scanf("%d", &size);

  arr = (uint*)malloc(sizeof(uint) * size);

  for(i = 0; i < size; ++i) scanf("%d", arr + i);

  fclose( stdin );
};

empty_set display() {

  uint i;

  freopen(FOUT, "w", stdout);

  for(i = 0; i < size; ++i) printf("%d ", *(arr + i));

  free( arr );

  fclose( stdout );

};

empty_set _mergesort(int left, int right) {

     if(right > left) {

         uint middle = (left + right) >> 1;

         _mergesort(left, middle); 

         _mergesort(middle + 1, right);

          uint i,

               j,

               k,

               *temp;

          temp = ( uint* ) malloc( sizeof( uint ) * ( right - left + 1 ) );

          for(i = left; i <= right; i++) temp[ i - left ] = arr[ i ]; 

          for( i = k = left, j = middle + 1; i <= middle && j <= right; k++ ) 

              if(temp[ i - left ] < temp[ j - left ]) arr[ k ] = temp[ i++ - left ];

                                                 else

                                                       arr[ k ] = temp[ j++ - left ];
          while( i <= middle )

            arr[ k++ ] = temp[ i++ - left ];       
          

          while( j <= right )

            arr[ k++ ] = temp[ j++ - left ];

          free( temp );
    } 
};

empty_set sort() {

     _mergesort(0, size - 1); 
};
