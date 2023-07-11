#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

typedef bool (*comparer)(const void *a, const void *b);

int* read(int *p, int *n) {

     int i, num;

     freopen(FIN, "r", stdin);

     scanf("%d", &num);

     *n = num;

     p = (int*)malloc(sizeof(int) * num); 

     for(i = 0; i < num; ++i) scanf("%d ", &p[i]); 
     
     return p;
};

void do_bubblesort(int *p, int n, comparer comp) {
 
     int i, finished = 0, swapped, last = n;

     while(!finished) {

            swapped = 0;

            for(i = 0; i < last - 1; ++i) {

                if(comp(&p[i], &p[i+1])) {

                   int tmp =*(p+i);

                       *(p+i) = *(p+i+1);

                       *(p+i+1) = tmp;

                       swapped = 1; 
                }
            }
            if(swapped) last--;

                 else 

                        finished = 1; 
     }
};

bool ascending_order(const void *a,const void *b) {

     return(*(int*)a >*(int*)b);
};

bool descending_order(const void *a,const void *b) {

     return(*(int*)a <*(int*)b);
};

void write(int *p, int n) {

     freopen(FOUT, "w", stdout);

     int i;
     
     for(i = 0; i < (n); ++i) printf("%d ", p[i]); 
};

int main() {

    int *arr, 
         n;

    arr = read(arr, &n);  //passing by reference

    do_bubblesort(arr, n, ascending_order);

    write(arr, n);

    return(0);
};
