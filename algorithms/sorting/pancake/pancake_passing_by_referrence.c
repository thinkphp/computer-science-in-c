#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define pb push_back

int* read(int *n) {

     int it, 
         num;

     freopen(FIN, "r", stdin);

     scanf("%d", &num);

     *n = num;
 
     int *v = (int*)malloc(sizeof(int)*num);

     for(it = 0; it < num; ++it) scanf("%d", (v+it));

     return v; 
};

int findMax(int *p, int index) {

    int i, iMax = 0;

    for(i = 1; i < index; ++i) {

        if(p[i] > p[iMax]) iMax = i;
    }

    return iMax; 
};

void flip(int *p, int index) {

     int start = 0;

     while( start < index ) {

            int tmp = p[ start ];
                p[ start++ ] = p[ index ];
                p[ index-- ] = tmp;
     }
};

void pancake(int *p, int n) {
 
     int curr_size, iMax;
     
     for(curr_size = n; curr_size > 1; --curr_size) {

         iMax = findMax( p, curr_size );

         if(iMax != (curr_size-1)) {

            flip( p, iMax );

            flip( p, curr_size - 1 ); 
         }
     }  
};

void print(int *p, int n) {

     int it;

     freopen(FOUT, "w", stdout);

     for(it = 0; it < n; ++it) printf("%d ", *(p+it));
};

int main() {

    int *p,
         n; 

    p = read( &n );

    pancake( p, n );
 
    print( p, n );

    return(0);
};