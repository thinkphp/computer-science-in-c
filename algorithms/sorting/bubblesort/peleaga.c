#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

void __bubble(int *p, int n) {

     int finished = 0, 
 
         changed, 
 
         size = n, 

         it;

     while( !finished ) {

            changed = 0;

            for(it = 0; it < size - 1; ++it) {

                if(p[it] > p[it+1]) {

                   int temp = p[it];

                       p[it] = p[it+1]; 

                       p[it+1] = temp;

                       changed = 1;   
                }
            } 

            if(changed) size--;

               else

                        finished = 1;
     }

}

int main() {

    int n, *p, i;

    //the following example show the usage of freopen
    //freopen(char *filename, char *mode, FILE *stream)
    //so whatever we read at STDIN that goes inside scarface.in
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);

    //read number of elements from FILE
    scanf("%d", &n); 

    //the malloc Stands for Memory allocation
    //reserves a block of memory of the specified number of bytes
    //it returns o pointer of type void which can be casted into pointer any form
    p = (int*)malloc(sizeof(int)*n);

    for(i = 0; i < n; ++i) scanf("%d", p + i); 

    __bubble(p, n);

    for(i = 0; i < n; ++i) printf("%d ", *(p + i));


    //free the space allocated.
    free(p);
 
return(0);
}

