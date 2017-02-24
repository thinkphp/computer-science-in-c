#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

int* read(int* arr, int* n) {

     int i, 
         num;

     freopen(FIN, "r", stdin);     

     scanf("%d",&num);

     arr = (int*)malloc(sizeof(int)*num);

      *n = num;  

     for(i = 0; i < num; ++i) scanf("%d", (arr+i));

     fclose(stdin);

     
return arr;
};


void write(int *arr, int num) {

     freopen(FOUT, "w", stdout);     

     int i;

     for(i = 0; i < num; ++i) printf("%d ", *(arr+i));

     free( arr );

     fclose( stdout );
};

void shellsort(int *arr, int n) {

     int i,
         j,
         gaps,
         gap,
         temp; 

     for(gaps = n/2; gaps > 0; gaps/=2) {

         gap = gaps;

         for(i = gap; i < n; ++i) {

             temp = arr[ i ];

             for(j = i - gap; ( j >= 0 && arr[j] > temp); j -= gap) {

                 arr[ j + gap ] = arr[ j ];
             }

                 arr[ j + gap ] = temp;
         } 
     }
};

int main() {

    int i,
        n, 
        *arr;  

    //call by reference
    arr = read( arr, &n ); 
    shellsort(arr, n);
    write( arr, n);

return(0);
}