/**
 *  Pancake Method Sorting 
 *  
 */
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define pb push_back

typedef bool (*comparer)(const void *a, const void *b);

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

bool ascending_order(const void *a, const void *b) {

     return (*(int*)a > *(int*)b);
};

bool descending_order(const void *a, const void *b) {

     return (*(int*)a < *(int*)b);
};


int find(int *p, int index, comparer comp) {

    int i, iMax = 0;

    for(i = 1; i < index; ++i) {

        if(comp(&p[i], &p[iMax])) iMax = i;
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

         iMax = find( p, curr_size, ascending_order);

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

    int *p,//declare a pointer to integer
         n;//the number of elements 

    p = read( &n );//n passing by reference

    pancake( p, n );
 
    print( p, n );

    return(0);
};