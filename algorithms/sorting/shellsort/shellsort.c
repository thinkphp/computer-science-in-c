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
      
     int dist[ 8 ] = {15, 13, 11, 9, 7, 5, 3, 1};

     for(d = 0; d < 8; d++) {

         dis = dist[ d ];

         for(j = dis; j < n; j++) {

             aux = vec[ j ];

             for(i = j - dis; i >= 0 && vec[ i ] > aux; i -= dis ) {

                 vec[i + dis] = vec[ i ];
             }

             vec[i + dis] = aux;
         }     
     }     
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