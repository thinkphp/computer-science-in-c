#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int arr[ MAXN ],
    n; 

//prototypes
void read();
void bubble();
void write();

int main() {

    read();

    bubble();

    write();

    return(0);
};

void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     for(i = 0; i < n; i++) scanf("%d", &arr[ i ]); 

     fclose( stdin ); 
};

void write() {

     int i;

     freopen(FOUT, "w", stdout);

     for(i = 0; i < n; i++) printf("%d ", arr[ i ]); 

     fclose( stdout ); 
};

void bubble() {

     int swap, 

         i,
 
         size = n, 

         x;

     do {
 
        swap = 1;

        for(i = 0; i < size - 1; i++) {

            if(arr[ i ] > arr[i + 1]) {
 
               x = arr[ i ] ^ arr[ i + 1 ];

               arr[ i ] = x ^ arr[ i ];

               arr[ i + 1 ] = x ^ arr[ i + 1 ];

               swap = 0; 
            }  
        }

     }while( !swap );   
};

