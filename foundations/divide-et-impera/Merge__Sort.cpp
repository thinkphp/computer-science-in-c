#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

int *vec,
    n;

void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     vec = (int*) malloc( sizeof( int ) * n );

     for(i = 0; i < n; i++) scanf("%d", vec + i);

     fclose( stdin );
};

void write() {

   int i;

   freopen(FOUT, "w", stdout);

   for(i = 0; i < n; i++) printf("%d ", *(vec + i) );

   fclose( stdout );
};

void _mergesort(int lo, int hi) {

    int middle, 

        *temp, 

        k = 0, 

        i, j;


    if( lo < hi ) {

       middle = ( lo + hi ) >> 1;
      _mergesort(lo, middle); 
      _mergesort(middle + 1, hi);

      temp = ( int* ) malloc(sizeof(int) * ( hi - lo + 1 )); 

      int i = lo, 
          j = middle + 1, 
          k = 0;

      while(i <= middle && j <= hi ) {

            if(vec[ i ] < vec[ j ]) temp[ k++ ] = vec[ i++ ];

                           else     temp[ k++ ] = vec[ j++ ];
      }         

      while(i <= middle) {

            temp[ k++ ] = vec[ i++ ];
      }

      while(j <= hi) {

            temp[ k++ ] = vec[ j++ ];
      }

      k = 0;

      for(i = lo; i <= hi; i++) vec[ i ] = temp[ k++ ];

      free(temp); 
    }
}

void MergeSort() {

     _mergesort(0, n - 1);
};

int main() {

  read();
  MergeSort();
  write();

  return(0);
};