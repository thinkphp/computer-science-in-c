#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005


void CombSortAlgorithm(int p[], int n) {

     float shrinkFactor = 1.3;
     int gap = n, swapped = 1,
         i;

     while(gap > 1 || swapped) {

           if(gap > 1) gap = (gap / shrinkFactor);

           swapped = 0; 
           for(i = 0; i + gap < n; ++i) {
               if(p[i] > p[i+gap]) {
                  int tmp = p[ i ];  
                      p[i] = p[i+gap];
                      p[i+gap] = tmp; 
                      swapped = 1;   
               }
           } 
     } 

     for(i = 0; i < n; ++i) printf("%d ", p[i]);
};

typedef void (*ptrFn)(int arr[], int n);

int main() {

    int n, arr[SIZE];

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    scanf("%d", &n);
  
    int i;
 
    for(i = 0; i < n; ++i) scanf("%d", &arr[i]);

    ptrFn sort = CombSortAlgorithm;

    sort(arr, n); 
 
 return( 0 );
};