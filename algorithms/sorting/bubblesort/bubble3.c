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
void swap(uint, uint);

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

     for(i = 0; i < n - 1; i++) {

         for(j = i + 1; j < n; j++) {

             if(arr[ i ] > arr[ j ]) {
              
                swap(i, j);  
             }
         }
     } 

};

void write() {

     uint i;

     freopen(FOUT, "w", stdout); 
 
     for(i = 0; i < n; i++) printf("%d ", arr[ i ]);

     fclose( stdout );
};

void swap(uint x, uint y) {

     uint xo;

     xo = arr[ x ] ^ arr[ y ];    

     arr[ x ] = xo ^ arr[ x ];

     arr[ y ] = xo ^ arr[ y ]; 
}