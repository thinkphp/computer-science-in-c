#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

char buffer[32000];
int ptr = 31999;

void inc() {

     ptr++;

     if( ptr == 32000 )  {

         fread(buffer, 1, 32000, stdin);    

         ptr = 0; 
     }
}

void read(int *x) {

     while(buffer[ptr] < '0' || buffer[ptr] > '9') inc(); 

     *x = 0;

     while(buffer[ptr] >= '0' && buffer[ptr] <= '9' ) {
            
           *x = (*x) * 10 + buffer[ptr] - '0';

           inc();
     }
}

void _comb_s(int *p, int size) {

     float shrinkFactor = 1.3;
     int i, swapped, gap = size;
        
     while(gap > 1 || swapped) {

           swapped = 0;

           if(gap > 1) gap = gap / shrinkFactor;
 
           for(i = 0; i + gap < size ; ++i) {

               if(p[i] > p[i+gap]) {

                  int holder = p[i];

                      p[i] = p[i+gap];

                      p[i+gap] = holder;

                      swapped = 1;   
               } 
           }  
     } 
}

int main() {

    int i, 
        *n, 
        *p;

    int *v,*V;

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    n = (int*)malloc(sizeof(int) + 1); 

    read(n);
 
    v = (int*)malloc(sizeof(int) * (*n));

    V = (int*)malloc(sizeof(int));

    for(i = 0; i < (*n); ++i) { read(V); *(v+i) = *V; }

    _comb_s( v, *n);

    for(i = 0; i < (*n); ++i) { printf("%d ", *(v+i)); }
 
    free(n); 

    free(v);

    free(V);  

    return(0);
}


