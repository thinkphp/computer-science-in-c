#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

typedef unsigned int uint;

uint arr[ MAXN ],
     n;

//functions prototype
void read();
void shell();
void write();

int main() {

    read();
    shell();
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

void shell() {

     int gap = n - 1,
         g,
         i, 
         j,
         temp;

         for(g = gap/2; g > 0; g /= 2) {

             for(i = g; i < n; i++) {

                 temp = arr[ i ];

                 for(j = i; j >= g; j -=g) {

                     if(arr[j - g] > temp) {

                       arr[ j ] =  arr[j - g];

                     } else {

                       break; 
                     }
                 }

                 arr[ j ] = temp;
             } 
         }
  
};

void write() {

     int i;

     freopen(FOUT, "w", stdout); 
 
     for(i = 0; i < n; i++) printf("%d ", arr[ i ]);

     fclose( stdout );
};