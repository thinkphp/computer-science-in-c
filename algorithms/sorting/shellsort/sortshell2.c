#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAX 500005

int vec[ MAX ], 
    n;

void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     for(i = 0; i < n; i++) scanf("%d", &vec[ i ]);

     fclose( stdin ); 
};

void sort() {

     int d,
         dis,
         i,
         j,
         aux; 

     int h = 1; 

     do {

        h = 3 * h + 1;

     } while( h <= n );


      do {

         h /= 3;

         for(j = h; j < n; j++) {

             aux = vec[ j ];

             for(i = j - h; i >= 0 && vec[ i ] > aux; i -= h ) {

                 vec[i + h] = vec[ i ];
             }

             vec[i + h] = aux;
         }     

     } while( h > 1);    
}


void write() {

     int i;

     freopen(FOUT, "w", stdout);

     for(i = 0; i < n; i++) printf("%d ", vec[ i ]);

     fclose( stdout ); 
}

int main() {

    read();
    sort();
    write();    
     
    return(0);
}