#include <stdio.h>
#include <malloc.h>

typedef void (*fnptr)(int*,int);

void combsort(int *p, int n) {

     int swapped, i, gap = n;

     float shrinkFactor = 1.3;
   
     while(gap > 1 || swapped) {

           if( gap > 1 ) gap = gap / shrinkFactor;

           swapped = 0;

           for(i = 0; i + gap < n; ++i) {

               if( *(p + i) > *(p + i + gap)) {

                     int tmp = *(p + i); 

                     *(p + i) = *(p + i + gap);

                     *(p + i + gap) = tmp;

                     swapped = 1;
               }
           }
     } 
};

int main() {

   int *v,

        i,

        n;

   const char *FIN = "algsort.in"; 
   const char *FOUT = "algsort.out"; 

   fnptr sort = combsort;

   if( !FIN ) printf("Error of opening!");

   freopen(FIN, "r", stdin);

   freopen(FOUT, "w", stdout);

   scanf("%d", &n);

   v = (int*)malloc(sizeof(int) * n);

   for(i = 0; i < n; ++i) scanf("%d", v + i);

   sort(v, n); 

   for(i = 0; i < n; ++i) printf("%d ", *(v + i));

 return(0);
};