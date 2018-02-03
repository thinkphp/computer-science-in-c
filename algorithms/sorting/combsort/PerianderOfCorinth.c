#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005
 
typedef int (*Compare)(int a, int b);
 
void CombSortAlgo(int p[], int n, Compare comp) {
 
     float shrinkFactor = 1.3;

     int gap = n, 

         swapped = 1,

         i;
 
     while(gap > 1 || swapped) {
 
           if(gap > 1) gap = (gap / shrinkFactor);
 
           swapped = 0; 

           for(i = 0; i + gap < n; ++i) {

               if(comp(p[i] , p[i+gap]) > 0) {

                  int tmp = p[ i ];  

                      p[i] = p[i+gap];

                      p[i+gap] = tmp;
 
                      swapped = 1;   
               }
           } 
     } 
 
     for(i = 0; i < n; ++i) printf("%d ", p[i]);
};
 
int asc_ord(int a, int b) {
    
     if(a > b) return 1;
 
          else return 0;  
};
 
int main() {
 
    int n, arr[SIZE];
 
    freopen(FIN, "r", stdin);
 
    freopen(FOUT, "w", stdout);
 
    scanf("%d", &n);
   
    int i;
  
    for(i = 0; i < n; ++i) scanf("%d", &arr[i]);
 
    CombSortAlgo(arr, n, asc_ord) ;
  
 return( 0 );
};