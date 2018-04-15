#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

typedef void (*PTRfn)(int *p, int);

void merge(int *p, int lo, int m, int hi) {

     int i = lo, 
         j = m + 1, 
         index = 0, 
         aux[hi - lo + 1];

     while(i <= m && j <= hi) {

           if(p[i] < p[j]) aux[index++] = p[i++];
           else  
           aux[index++] = p[j++];
     }

     while(i<=m) aux[index++] = p[i++];

     while(j<=hi) aux[index++] = p[j++];

     index = 0;  

     for(i = lo; i <= hi; ++i) p[i] = aux[index++]; 
};

void divideetimpera(int *p, int lo, int hi) {

     if(lo < hi) {
        int m = (lo+hi)>>1;
        divideetimpera(p, lo, m);
        divideetimpera(p, m + 1, hi);
        merge(p, lo, m, hi);
     }  
}

void mergesort(int *p, int n) {

     divideetimpera(p, 0, n - 1 );
}

int main() {

    int *p, n, i;

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    PTRfn s = mergesort; 

    scanf("%d", &n);

    p = (int*)malloc(sizeof(int) * n); 

    for(i = 0; i < n; ++i) scanf("%d ", (p + i));

    s(p, n); 

    for(i = 0; i < n; ++i) printf("%d ", *(p + i));

    free( p );

 return( 0 );
};