#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

//globals
int heap[ MAXN ], //heap vector

    sizeHeap, //the length of the heap

    n;//number of elements

//function prototypes
void heapsort();
void swap();
void up( int );
void down( int );
void insertHeap( int );
int removeHeap(  );

int main() {

    heapsort(); 

    return(0);
};

void heapsort() {

    int i, 

        elem;

    freopen(FIN, "r", stdin);

    scanf("%d", &n); 

    for(i = 1; i <= n; i++) {
 
        scanf("%d", &elem);

        insertHeap( elem ); 
    }

    fclose( stdin ); 

    freopen(FOUT, "w", stdout);

    for(i = 1; i <= n; i++) {

        printf("%d ", removeHeap());
    }    

    fclose( stdout ); 

}

void swap(int a, int b){

     int x;

     x = heap[ a ] ^ heap[ b ];

         heap[ a ] = x ^ heap[ a ];

         heap[ b ] = x ^ heap[ b ];
}

void up(int c) {

     int p = c / 2;

     while( p ) {

            if(heap[ p ] > heap[ c ]) {

               swap(p, c);

               c = p;

               p = c / 2;
                
            } else break;
     }
};

void down(int p) {

     while( 2 * p <= sizeHeap ) {

            int c = 2 * p;

            if( 2 * p + 1 <= sizeHeap && heap[ 2 * p + 1] < heap[ 2 * p] ) c++;

            if( heap[ p ] <= heap[ c ]) break;

            swap(p, c);

            p = c;
     }   
}

void insertHeap(int elem) {

     heap[ ++sizeHeap ] = elem;

     up( sizeHeap ); 
};

int removeHeap() {
 
     int val;

     val = heap[ 1 ];

     heap[ 1 ] = heap[ sizeHeap-- ];

     down( 1 );

     return val; 
};