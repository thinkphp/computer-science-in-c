#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005

int arr[SIZE],
    n;

void read();
void sort();
void write();

int main() {

    read();
    sort();
    write();
  
    return(0);
};

void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);
      
     for(i = 0; i < n; ++i) scanf("%d", &arr[ i ]);
};

void sort() {

     int i, 
         finished = 0, 
         swapped, 
         last = n;

         while( !finished ) {

              swapped = 0;

              for(i = 0; i < last - 1;++i) {

                  if(arr[ i ] > arr[ i + 1 ]) {

                     int tmp = arr[ i ];
                         arr[ i ] = arr[ i + 1 ];
                         arr[ i + 1 ] = tmp;

                         swapped = 1;
                  } 
              } 

              if( swapped ) last--;

                   else     finished = 1;
         }
};

void write() {

     int i;

     freopen(FOUT, "w", stdout);
      
     for(i = 0; i < n; ++i) printf("%d ", arr[ i ]);

};
