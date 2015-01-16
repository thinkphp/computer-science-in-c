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
nothing _mergesort(uint, uint);

uint *arr,
      size;

int main() {

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

nothing _mergesort(uint left, uint right) {

    if(right == left) return;

    else {

         uint middle = (left + right) >> 1;

         _mergesort(left, middle); 

         _mergesort(middle + 1, right);

          uint i,

               j,

               k,

               //I Get Time limit exceeded!!!
               *temp;

               //No Time limit exceeded!!!
               //temp[ right + 1 ];

          temp = ( uint* ) malloc(sizeof( uint ) * ( right + 1 ));

          for(i = left; i <= right; i++) temp[ i ] = arr[ i ];           

          for(i = k = left, j = middle + 1; i <= middle && j <= right;) {

              if(temp[ i ] < temp[ j ]) arr[ k++ ] = temp[ i++ ];

                                    else

                                         arr[ k++ ] = temp[ j++ ];
         }

          while( i <= middle )

            arr[ k++ ] = temp[ i++ ];       
          
          while( j <= right )

            arr[ k++ ] = temp[ j++ ];

          free( temp );  
    } 
};

nothing sort() {

     _mergesort(0, size - 1); 
};
