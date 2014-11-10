/**
 *  Insertion Sort Algorithm for 40 points.
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
void insertsort();


int main() {

    read();
    insertsort();
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


void insertsort() {

     int i,

         j, 

         aux;

     for(i = 1; i < n; i++) {

         aux = vec[ i ];

         j = i - 1;

         while(j >= 0 && vec[ j ] > aux) {

              vec[ j + 1] = vec[ j ];

              j--; 
         } 

         vec[ j + 1] = aux;
     }         

};

