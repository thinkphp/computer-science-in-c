#include <cstdio>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define DIM 500005

using namespace std;

int Heap[ DIM ];
int     sizeHeap;

void _swap(int a, int b) {

     int x = Heap[ a ] ^ Heap[ b ];

         Heap[ a ] = x ^ Heap[ a ]; 
 
         Heap[ b ] = x ^ Heap[ b ];
};

void up(int child) {

     int parrent = child / 2;

     while( parrent ) {

          if( Heap[ parrent ] > Heap[ child ]) {

              _swap(parrent, child);

              child = parrent;

              parrent = child / 2;   

          } else break;
     }  
};

void insertHeap(int val) {

     Heap[ ++sizeHeap ] = val;

     up( sizeHeap );
};

void down(int parrent) {

     while( 2 * parrent  <= sizeHeap ) {

            int child = 2 * parrent;

            if(2 * parrent + 1 <= sizeHeap && Heap[ 2 * parrent + 1 ] < Heap[ 2 * parrent ]) child++;   

            if( Heap[ parrent ] <= Heap[ child ]) break;

            _swap(parrent, child);

            parrent = child;
     }
};

int removeHeap() {

     int ret = Heap[ 1 ];

     Heap[ 1 ] = Heap[ sizeHeap-- ];  

     down( 1 );

     return ret; 
};

int main() {

    int N, val;

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {

        scanf("%d", &val); 
       
        insertHeap( val );
    }

    for(int i = 1; i <= N; ++i) printf("%d ", removeHeap());

 return(0);
};