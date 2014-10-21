#include <cstdio>
#define MAXN 500005
#define FIN "myquicksort.in"
#define FOUT "myquicksort.out"

using namespace std;

int arr[MAXN],
    n,
    *x;

class QUICKSORT {

      public: 
      int *p, 
           n;
  
      QUICKSORT(int arr[], int num) {
 
          p = arr;  
          n = num;
          sort();
      }
      
      void sort() {
 
           _quicksort(0, n - 1);
      } 

      int* get() {

           return p;
      }
 
      private:
      void _quicksort(int li, int ls) {

           int i,
               j,
               x,piv;

               i = li;
               j = ls; 
               piv = p[ (li + ls)>>1 ];

               while(i<=j) {

                     while(p[i]<piv) {
                             i++;
                     }

                     while(p[j]>piv) {
                             j--;
                     }

                     if( i<=j ) {
                         x = p[i]^p[j]; p[i] = x^p[i]; p[j] = x^p[j];
                         i++;j--;  
                     }
               }

               if(li<j) _quicksort(li,j);
               if(i<ls) _quicksort(i,ls);
      }
};

//function prototypes
void read();
void write();

int main() {

    read(); 
     
    QUICKSORT quick( arr, n ); 

    x = quick.get();

    write();

    return(0);
};

void read() {

    freopen(FIN, "r", stdin);

    scanf("%d", &n); 

    for(int i = 0; i < n; i++ ) scanf("%d ", &arr[ i ]);

    fclose( stdin );
};

void write() {

    freopen(FOUT, "w", stdout);

    for(int i = 0; i < n; i++ ) printf("%d ", x[ i ]);

    fclose( stdout );
}
