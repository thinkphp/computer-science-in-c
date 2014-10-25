#include <cstdio>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int heap[ MAXN ],
    sizeHeap,
    n;

//prototypes
void read();
void insert(int);
int removeFromHeap();
void up(int);
void down(int);

int main() {

    FILE *fout = fopen(FOUT, "w");

    read();

    for(int i = 1; i <= n; i++) fprintf(fout, "%d ", removeFromHeap());

    fclose( fout ); 

    return(0);
};

void up(int node) {

     while(node > 1 && heap[ node / 2] > heap[ node ]) {

           int x = heap[ node / 2 ] ^ heap[ node ];

               heap[ node / 2 ] = x ^ heap[ node / 2 ];

               heap[ node ]   = x ^ heap[ node ];         

           node /= 2;
     }
};

void down(int node) {

     while(2 * node <= sizeHeap) {

           int pos = 2 * node;

           if(2 * node + 1 <= sizeHeap && heap[2 * node + 1] < heap[ 2 * node ]) {

               pos = 2 * node + 1; 
           }   

           if(heap[ node ] <= heap[ pos ]) break;

           int x = heap[ node ]^heap[ pos ];

               heap[ node ] = x^heap[ node ];

               heap[ pos ] = x^heap[ pos ];         

            node = pos;
     }
};

void insert(int elem) {

         heap[++sizeHeap] = elem;

         up( sizeHeap );  
};

int removeFromHeap() {
   
     int val;

     val = heap[1];

     heap[1] = heap[sizeHeap--]; 

     down(1);

     return val;
}

void read() {

     FILE *fin = fopen(FIN, "r");

     int elem;

     fscanf(fin, "%d", &n);

     for(int i = 0; i < n; i++ ) {

         fscanf(fin, "%d", &elem);

         insert( elem );
     } 

     fclose( fin );
};
