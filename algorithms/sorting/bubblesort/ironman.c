#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

void bubblesort(int *p, int n) {


     int finished = 0, swapped, size = n, i;

     while(!finished) {

           swapped = 0;

           for(i = 0; i < size - 1; ++i) {

               if(p[i] > p[i+1]) {
 
                  int tmp = p[i];
                      p[i] = p[i+1];
                      p[i+1] = tmp;
                      swapped = 1;      
               }    
           }  

           if(swapped) size--;else finished = 1;  
     }    
}

int main() {

   int *p, i, n; 

   freopen(FIN, "r", stdin); 

   scanf("%d", &n);  

   printf("%d\n", n);

   p = (int*)malloc(sizeof(int)*n); 

   for(i = 0; i < n; ++i) scanf("%d", p + i);

   bubblesort(p, n);

   for(i = 0; i < n; ++i) printf("%d ", *(p + i));

   printf("\n");

   return(0);      
}
