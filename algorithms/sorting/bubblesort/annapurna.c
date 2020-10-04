#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"

void bubble_sort(int *p, int n) {

     int finished = 0,
         swapped,
         size = n,
         i;

         while(!finished) {
 
               swapped = 0;

               for(i = 0; i < size - 1; ++i) {

                   if(p[i] > p[i+1]) {

                   	  int x = p[i] ^ p[i+1];
                   	      p[i] = x ^ p[i]; 
                   	      p[i+1] = x ^ p[i+1];
                   	      swapped = 1;
                   }
               }  

               if( swapped ) size--; else finished = 1;
         } 
}

int main(int argc, char const *argv[])
{
    int n, 
        *p, 
        i;
        
        freopen(FIN, "r", stdin);

        scanf("%d", &n);

        for(i = 0; i < n; ++i) scanf("%d", p + i);

        	bubble_sort(p, n); 

        	for(i = 0; i < n; ++i) printf("%d ", *(p + i));

	return 0;
}