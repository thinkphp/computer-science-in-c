#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

typedef unsigned int uint;

uint arr[ MAXN ],
     n;

//functions prototype
void read();
void bubble();
void write();
void swap(int,int);

int main() {

    read();
    bubble();
    write();

  return(0);
};

void read() {

     uint i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n); 
 
     for(i = 0; i < n; i++) scanf("%d", &arr[ i ]);

     fclose( stdin );

};

void bubble() {

     uint i,

          j; 

     int swapped; 

     for(i = n - 1; i > 0; i--) {

         swapped = 0;

         for(j = 0; j < i; j++) {

             if(arr[ j ] > arr[j + 1 ]) {
              
                swap(j, j + 1);  

                swapped = 1;
             }
         }

         if( !swapped ) break;
     } 

};

void write() {

     int i;

     freopen(FOUT, "w", stdout); 
 
     for(i = 0; i < n; i++) printf("%d ", arr[ i ]);

     fclose( stdout );
};

void swap(int x,int y) {

     int xo;

     xo = arr[ x ] ^ arr[ y ];    

     arr[ x ] = xo ^ arr[ x ];

     arr[ y ] = xo ^ arr[ y ]; 
}