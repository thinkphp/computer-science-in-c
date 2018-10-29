/**
  Author: Adrian Statescu <http://adrianstatescu.com>

  How does fread really work?!

  The declaration of FREAD is as following:
  size_t fread(void *ptr, size_t size, size_t nmem, FILE *stream)
  There may or may not be any difference in performance. There is a difference in semantics.
        fread(a, 1, 1000, stdin); -> attempts to read 1000 data elements each of which is 1 byte long
        fread(a, 1000, 1, stdin); -> attempts to read 1 data element which is 1000 bytes long         
 */
#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

int p = 31999;
char buff[ 32010 ];

void __b__s(int *p, int n) {

     int finished = 0, swapped, size = n, i;

     while(!finished) {

            swapped = 0;

            for(i = 0; i < size - 1; ++i) {

                if(p[i] > p[i+1]) {

                   int tmp = p[i]; p[i] = p[i+1]; p[i+1] = tmp; swapped = 1; 
                }
            }  

            if(swapped) size--;else finished = 1; 
     } 
      
}


void inc() {

       p++;

       if(p == 32000) {

          p = 0; fread(buff, 1, 32000, stdin); 

       } 
       
}

void read(int *x) {

     while(buff[p] < '0' || buff[p] > '9') inc();

     *x = 0;

     while(buff[p] >= '0' && buff[p]<= '9') {

           *x = 10*(*x) + buff[p] - '0'; 

           inc();   
     } 
}

int main() {

   int *x, *n, i, k = 0 , vec[32000]; 

   freopen(FIN, "r", stdin);

   freopen(FOUT, "w", stdout);

   n = (int*)malloc(sizeof(int));   
   

   read(n);

   x = (int*)malloc(sizeof(int)); 

   for(i = 0; i < *n; i++) {

       read(x);

       vec[k++] = *x; 
          
   }

    __b__s(vec, *n);

    for(i = 0; i < *n; ++i) printf("%d ", vec[i]); 
    
    free(n);

    free(x);

    return(0);
};
