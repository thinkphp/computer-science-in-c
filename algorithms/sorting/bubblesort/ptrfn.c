#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

void bubblesort(int *vec, int n) {

     int i, 

         changed, 

         aux;
    
     do {

         changed = 1;

         for(i = 0; i < n - 1; ++i) {

             if( *( vec + i ) > *(vec + i + 1)) {
                 
                aux = vec[ i ];

                vec[ i ] = vec[ i + 1 ];

                vec[ i + 1] = aux;
   
                changed = 0;  
             }             
         }

         if( !changed ) --n;

     } while( !changed );   

}


void selectionbymin(int *vec, int n) {

     int i,

         j, 

         pos, 

         min; 

     for(i = 0; i < n - 1; ++i) {


         min = vec[ i ];

         pos = i;

         for(j = i + 1; j < n; ++j) {

             if( vec[ j ] < min ) {


                 min = vec[ j ];

                 pos = j;
             }
         }

        vec[ pos ] = vec[ i ];

        vec[ i ] = min;    
     }  
}

typedef void (*fnPtr)(int *v, int n);

int main() {

    int i, n;

    fnPtr sort[ 2 ] = { bubblesort, selectionbymin };

    int *arr;

    arr = malloc( sizeof ( int ) ); 

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    scanf("%d", &n);

    for(i = 0; i < n; ++i) scanf("%d", arr + i);

    //for(i = 0; i < 2; ++i) sort[ i ]( arr, n ); 

    sort[ 1 ]( arr, n );

    for(i = 0; i < n; ++i) printf("%d ", *( arr + i ));

    free( arr );
    
    return(0); 
}