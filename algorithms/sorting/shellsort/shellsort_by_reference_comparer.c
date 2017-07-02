#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define pb push_back

typedef bool (*comparer)(const void *a, const void *b);

bool ascending_order(const void *a, const void *b) {         

     return (*(int*)a) > (*(int*)b);
};

bool descending_order(const void *a, const void *b) {         

     return (*(int*)a) < (*(int*)b);
};

int* read(int *num) {

     int i, n, *v;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     *num = n;

     v = (int*)malloc(sizeof(int)*n);  

     for(i = 0; i < n; ++i) scanf("%d", (v + i));
 
     return v;
};

void sort(int *p, int n, comparer comp) {

     int gaps, gap, aux, i, j;
  
     for(gaps = n/2; gaps > 0; gaps /=2) {

         gap = gaps;

         for(i = gap; i < n; ++i) {

             aux = p[i];

             for(j = i - gap; j>=0 && comp(&p[j], &aux); j-=gap) {

                 p[j + gap] = p[j];
             }
                 p[j + gap] = aux;
         }
     }  
};

void print(int *v, int n) {

     int i;

     freopen(FOUT, "w", stdout);

     for(i = 0; i < n; ++i) printf("%d ", *(v+i));
};

int main() {

    int *vec, 
         num;

    vec = read( &num );

     sort( vec, num, ascending_order);

    print( vec, num );

 return(0);
};