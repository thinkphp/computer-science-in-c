#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#include <malloc.h>

int *arr,
     n; 

void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     arr = (int*)malloc(sizeof(int) * n);

     for(i = 0; i < n; ++i) scanf("%d", &arr[ i ]);

     fclose( stdin );
}

void shellsort() {

     int gaps,gap,i,j,temp;  
      
     for(gaps = n/2; gaps > 0; gaps /=2) {

         gap = gaps;

         for(j = gap; j < n; j++) {

             temp = arr[ j ];

             for(i = j - gap;(i>=0 && arr[i] > temp ); i -= gap) {

                 arr[ i + gap ] = arr[ i ];
             } 

                 arr[ i + gap ] = temp;
         } 
 
     }
}

void write() {

     int i;

     freopen(FOUT, "w", stdout);

     for(i = 0; i < n; ++i) printf("%d ", arr[ i ]);       

     fclose( stdout ); 
}

int main() {

    read();
    shellsort();
    write();

    return(0); 
}