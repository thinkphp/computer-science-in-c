#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int *v, 
    n;

void read() {

     int i; 

     FILE *fin = fopen(FIN, "r");

     fscanf(fin, "%d", &n);     

     v = (int*)malloc(sizeof(int)*n);

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
         it, 
         *aux;

     aux = (int*)malloc(sizeof(int)* (hi - lo + 1) ); 

     for(it = lo; it <= hi; ++it) aux[ it - lo ] = v[ it ];

     while(i <= m && j <= hi ) {

           if(aux[ i - lo ] < aux[ j - lo ]) v[k++] = aux[ i++ - lo]; 

                      else  
                                             v[k++] = aux[ j++ - lo]; 
     }

     while(i<=m) v[k++] = aux[ i++ - lo]; 

     while(j<=hi) v[k++] = aux[ j++ - lo];

     free( aux );
     
}

void write() {

     int i;

     FILE *fout = fopen(FOUT, "w");

     for(i = 0; i < n; ++i) fprintf(fout,"%d ", *(v + i));
}

int main() {

    read();
    divideEtImpera(0, n - 1);
    write();

    return(0);  
}