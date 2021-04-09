#include <stdio.h>
#include <malloc.h>
#define repeat do {
#define until(COND) } while(!(COND));
#define FIN "algsort.in"
#define FOUT "algsort.out"

struct CArr {

       int size;
       int *data;
};

typedef struct CArr Arr;

Arr* vector(int n) {

    Arr* vec = ( Arr* )malloc(sizeof(struct CArr) * n);

          vec->size = n;

          vec->data = ( int* )malloc(sizeof(int) * n);

          for (size_t i = 0; i < n; i++) {

               vec->data[ i ] = 0;
          }

     return vec;
}

int insert(Arr* arr,int pos, int n) {

     arr->data[ pos ] = n;

     return arr->data[ pos ];
}

void display(Arr* arr) {

     for (int i = 0; i < arr->size; i++) {

          printf("%d ", arr->data[ i ]);
     }
}

void bubblesort( Arr* arr ) {

     int finished = 0,
         swapped,
         size = arr->size,
         i;

     repeat
           swapped = 0;

           for (size_t i = 0; i < size - 1; i++) {

                 if (arr->data[ i ] > arr->data[ i + 1 ]) {

                     int aux = arr->data[i]^arr->data[i+1];

                         arr->data[i] = aux ^ arr->data[i];

                         arr->data[i+1] = aux ^ arr->data[i+1];

                        swapped = 1;
                 }
           }

           if( swapped ) size--;

                 else
                         finished = 1;

     until( finished == 1 )
}

void merge(Arr* arr, int left, int m, int right) {

     int i = left,
         j = m + 1,
         *aux = (int*)malloc(sizeof(int) * (right - left + 1)),
         index = 0;

     while(i <= m && j <= right) {

           if(arr->data[ i ] < arr->data[ j ]) {

            aux[index++] = arr->data[i++];

           } else {

              aux[index++] = arr->data[j++];
           }
     }

     while( i <= m ) aux[index++] = arr->data[i++];

     while(j <= right) aux[index++] = arr->data[j++];

     for (size_t i = left; i <= right; i++) {

          arr->data[ i ] = aux[ i - left ];
     }

     free(aux);
}

void divideEtConquer(Arr* arr, int lo, int hi) {

     if(lo < hi) {

        int m = (lo + hi) >> 1;

        divideEtConquer(arr, lo, m);

        divideEtConquer(arr, m + 1, hi);

        merge(arr, lo, m, hi);
     }
}

void mergesort( Arr* arr ) {

      divideEtConquer(arr, 0, arr->size - 1);
}

int main(int argc, char const *argv[]) {
    int n, elem;
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);

    scanf("%d", &n);
    Arr* arr = vector( n );

    for (size_t i = 0; i < n; i++) {

            scanf("%d ", &elem);
            insert( arr, i, elem );
    }

    mergesort( arr );
    display( arr );

  return 0;
}
