#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int *v, 
    n, 
    aux[MAXN];

void read() {

     int i; 

     FILE *fin = fopen(FIN, "r");

     fscanf(fin, "%d", &n);     

     v = (int*)malloc(sizeof(int) * (n));

     for(i = 0; i < n; ++i) fscanf(fin, "%d", v + i);
}

void divideEtImpera(int lo, int hi) {
    
     if(lo == hi) return;

     int m = (lo + hi) >> 1;

     divideEtImpera(lo, m);

     divideEtImpera(m+1, hi);
     
     int i = lo, 
         j = m + 1, 
         k = lo, 
         it;

     for(it = lo; it <= m; ++it) aux[ it ] = v[ it ];

     while(i <= m && j <= hi ) {

           if(aux[ i ] < v[ j ]) v[k++] = aux[ i++ ]; 

                      else     v[k++] = v[ j++ ]; 
     }

     while(i<=m) v[k++] = aux[ i++ ]; 

     while(j<=hi) v[k++] = v[ j++ ];
}

void write() {

     int i;

     FILE *fout = fopen(FOUT, "w");

     for(i = 0; i < n; ++i) fprintf(fout, "%d ", *(v + i));
}

int main() {

    read();
    divideEtImpera(0, n - 1);
    write();

    return(0);  
}