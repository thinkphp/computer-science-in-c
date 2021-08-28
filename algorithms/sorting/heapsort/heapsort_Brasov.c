#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define DIM 500005

int Heap[ DIM ],

    sizeH;

void up( int child ) {

    int parent = child / 2;

    while( parent ) {

          if(Heap[parent] > Heap[child]) {

             int aux = Heap[parent];

                 Heap[parent] = Heap[child];

                 Heap[child] = aux;

                 child = parent;

                 parent = child / 2;

          } else break;
    }
}

void down( int parent ) {

     while(2 * parent <= sizeH) {

           int child = 2 * parent;

           if(2 * parent + 1 <= sizeH && Heap[2 * parent + 1] < Heap[2 * parent]) child++;

           if(Heap[parent]<=Heap[child]) break;

           int aux = Heap[parent];
               Heap[parent] = Heap[child];
               Heap[child] = aux;

          parent = child;
     }

}

void insertHeap(int value) {

     Heap[ ++sizeH ] = value;

     up( sizeH );
}

int removeHeap() {

    int ret = Heap[ 1 ];

    Heap[ 1 ] = Heap[ sizeH-- ];

    down( 1 );

    return ret;
}

int main(int argc, char const *argv[]) {

    int N,
        val;

    freopen(FIN, "r", stdin);
    
    freopen(FOUT, "w", stdout);

    scanf("%d", &N);

    for(int i = 1; i <= N; ++i) {

        scanf("%d", &val);

        insertHeap(val);
    }

    for(int i = 1; i <= N; ++i) printf("%d ", removeHeap());

  return 0;
}
