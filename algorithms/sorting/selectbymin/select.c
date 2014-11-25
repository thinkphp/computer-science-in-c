#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

typedef unsigned int uint;

uint arr[ MAXN ],
     n;

//functions prototype
void read();
void selectbymin();
void write();
void swap(int,int);

int main() {

    read();
    selectbymin();
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

void selectbymin() {

     uint i,

          j,

          min; 

          for(i = 0; i < n - 1; i++) {

              min = i;

              for(j = i + 1; j < n; j++) {

                  if(arr[ j ] < arr[ min ]) {

                     min = j;
                  }
              }

              if (min != i) swap(min, i);
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