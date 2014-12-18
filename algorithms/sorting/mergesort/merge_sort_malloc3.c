/**
 * Merge Sort in C Language.
 */
#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define nothing void

typedef unsigned int uint;

nothing read();
nothing display();
nothing sort();
nothing _mergesort(int, int);

uint *arr,
      size;

integer main() {

  read(); 
  sort();
  display();

  return(0);
};

nothing read() {

  uint i;

  freopen(FIN, "r", stdin);

  scanf("%d", &size);

  arr = (uint*)malloc(sizeof(uint) * size);

  for(i = 0; i < size; ++i) scanf("%d", arr + i);

  fclose( stdin );
};

nothing display() {

  uint i;

  freopen(FOUT, "w", stdout);

  for(i = 0; i < size; ++i) printf("%d ", *(arr + i));

  free( arr );

  fclose( stdout );

};

nothing _mergesort(int left, int right) {

    if(right == left) return;

    else {

         uint middle = (left + right) >> 1;

         _mergesort(left, middle); 

         _mergesort(middle + 1, right);

          uint i,

               j,

               k,

               *temp;

          temp = (uint*)malloc(sizeof(uint) * (right - left + 1));

          for(i = left; i <= right; i++) temp[ i - left ] = arr[ i ]; 

          for(i = k = left, j = middle + 1; i <= middle && j <= right;) 

              if(temp[ i - left ] < temp[ j - left ]) arr[ k++ ] = temp[ i++ - left ];

                                                 else

                                                       arr[ k++ ] = temp[ j++ - left ];
          while( i <= middle )

            arr[ k++ ] = temp[ i++ - left ];       
          

          while( j <= right )

            arr[ k++ ] = temp[ j++ - left ];

          free( temp );
    } 
};

nothing sort() {

     _mergesort(0, size - 1); 
};
