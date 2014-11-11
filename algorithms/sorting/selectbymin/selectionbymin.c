/**
 *  Selection by Minim Algorithm for 40 points.
 */
#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

//declare an array and number of elements all integers
int vec[ MAXN ],
    n;

//prototypes function
void read();
void write();
void selectionbymin();


int main() {

    read();
    selectionbymin();
    write();
 
    return(0); 
};

void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d",&n);

     for(i = 0; i < n; i++) scanf("%d", &vec[ i ]);

     fclose( stdin );
};

void write() {

     int i;

     freopen(FOUT, "w", stdout);

     for(i = 0; i < n; i++) printf("%d ", vec[ i ]);

     fclose( stdout );
};


void selectionbymin() {

     int i,

         j, 

         min,

         indMin;  

     for(i = 0; i < n - 1; i++) {

         min = vec[ i ];

         indMin = i; 

         for(j = i + 1; j < n; j++) {

             if(vec[ j ] < min) {

                min = vec[ j ];

                indMin = j; 
             }
         }

         vec[ indMin ] = vec[ i ];

         vec[ i ] = min;         
     }
};

