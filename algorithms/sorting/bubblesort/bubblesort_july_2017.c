#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005

void _swap(int *p, int *q) {

     int temp = *p;

           *p = *q;

           *q = temp;  
};

void bubblesort(int arr[], int n) {

     int i,j;

     for(i = 0; i < n - 1; ++i) {
     
         for(j = 0; j < n - i - 1; ++j) {

             if(arr[ j ] > arr[j + 1]) _swap(&arr[j], &arr[j+1]);
         }  
     }     
};

void write(int arr[], int n) {

    int i;

    freopen(FOUT, "w", stdout);

    for(i = 0; i < n; ++i) {

        printf("%d ", arr[ i ]); 
    }  

}

int main() {

    int arr[ SIZE ], //my array static data structure
        i, //iterator
        n; //number of elements

    freopen(FIN, "r", stdin);

    scanf("%d", &n);

    for(i = 0; i < n; ++i) {

        scanf("%d", &arr[ i ]); 
    }  

    bubblesort(arr, n);

    write(arr, n);

    return(0);
};