#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAX 500005

FILE *fin, *fout;

int N,
    arr[ MAX ], 
    x;

void _minHeap(int node, int N) {

     int val = arr[ node ], 
         base = 2 * node,
         ready = 0; 

     while(base <= N && !ready) {

           if(base < N && arr[ base + 1 ] > arr[ base ]) {

                     base++;
           } 

           if(val < arr[ base ]) {

                   x = arr[ node ]^arr[ base ];
                   arr[ node ] = x^arr[ node ];
                   arr[ base ] = x^arr[ base ]; 

                  node = base;
                  base *= 2;   

           } else ready = 1;
     }           
};

void read() {

     int i;

     fin = fopen(FIN, "r");

     fscanf(fin, "%d", &N);

     for(i = 1; i <= N; i++) fscanf(fin, "%d", &arr[i]);

     fclose( fin );
}

void write() {

    int i;

    fout = fopen(FOUT, "w");

    for(i = 1; i <= N; i++) {

        fprintf(fout, "%d ", arr[i]);
    }

    fclose( fout ); 
};

void HeapSort() {

    int i;

    for(i = N/2; i >= 1; i--) {

        _minHeap(i, N);
    }


    for(i = N; i >= 2; i--) {
 
            x = arr[1]^arr[i];
            arr[i] = x^arr[i];
            arr[1] = x^arr[1];    

        _minHeap(1,i-1); 
    } 
} 

int main() {
    
    int i;

    read();
    HeapSort();
    write();
 
    return(0);
};