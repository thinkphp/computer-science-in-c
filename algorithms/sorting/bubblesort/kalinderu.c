#include <stdio.h>
#include <malloc.h>
#define FIN "scarface.in"
#define FOUT "scarface.out"

void _bubble_sort(int *p, int n) {

     int finished = 0, swapped, size = n, i;

     while(!finished) {

           swapped = 0;

           for(i = 0; i < size - 1; ++i) {

               if(p[i] > p[i+1]) {

                  int holder = p[i];

                      p[i] = p[i+1];

                      p[i+1] = holder;

                      swapped = 1;  
               }
           }

           if( swapped ) size--; else finished = 1;
     }  

}

int main() {

    int n, 
        *p, 
        i;

    freopen(FIN, "r", stdin);  

    scanf("%d", &n);

    p = (int*)malloc(sizeof(int)*n);

    for(i = 0; i < n; ++i) scanf("%d", p + i);

    _bubble_sort(p, n);

    for(i = 0; i < n; i++) printf("%d ", *(p + i));      

    free(p);

return(0);

}
