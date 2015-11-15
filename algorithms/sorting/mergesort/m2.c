#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int v[MAXN], 
    n, 
    aux[MAXN];

void read() {

     int i; 

     FILE *fin = fopen(FIN, "r");

     fscanf(fin, "%d", &n);


     for(i = 0; i < n; ++i) fscanf(fin, "%d", v + i);
}

void divideEtImpera(int lo, int hi) {
    
     if(lo == hi) return;

     int m = (lo + hi) >> 1;

     divideEtImpera(lo, m);
     divideEtImpera(m+1, hi);
     
     int i = lo, 
         j = m + 1, 
         k = lo;

     while(i <= m && j <= hi ) {

           if(v[ i ] < v[ j ]) aux[k++] = v[ i++ ]; 
                      else     aux[k++] = v[ j++ ]; 
     }

     while(i<=m) aux[k++] = v[ i++ ]; 
     while(j<=hi) aux[k++] = v[ j++ ]; 

     for(i = lo; i <= hi; i++) v[ i ] = aux[ i ];

      
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