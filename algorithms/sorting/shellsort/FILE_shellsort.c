#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

 int *arr, 
      *n;

void read(){

     FILE *fin;
     int i;

     fin = fopen(FIN, "r"); 

     fscanf(fin, "%d\n", &n);

     arr = (int*)malloc(sizeof(int) * (int)n); 

     for(i = 0; i < (int)n; ++i) fscanf(fin, "%d ", &arr[i]);

     fclose( fin ); 
}

void shellsort(){

     int gaps,gap,i,j,temp;

     for(gaps = (int)n/2; gaps > 0; gaps/=2) {

         gap = gaps;

         for(i = gap; i < (int)n; ++i) {

             temp = arr[ i ];

             for(j = i - gap; (j >= 0 && arr[ j ] > temp); j-=gap) {

                 arr[ j + gap ] = arr[ j ];

             }

                 arr[ j + gap ] = temp;
         }  
     } 
}


void write(){

     int i;

     FILE *fout;

     fout = fopen(FOUT, "w");

     for(i = 0; i < (int)n; ++i) fprintf(fout, "%d ", arr[i]);

     fclose( fout ); 
}

int main() {

 read();
 shellsort();
 write();

 return(0);
};