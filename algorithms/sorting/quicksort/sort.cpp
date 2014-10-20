#include <cstdio>
#include <algorithm>
#define FIN "sort.in"
#define FOUT "sort.out"
#define MAXN 500005

using namespace std;

class SORT {

      public:

      int *p, 
          n;

      //constructor of class
      SORT() {
                     
      }

      //setter
      void set(int arr[], int num) {

           p = arr; 

           n = num;
      } 

      //sorting
      void sorting() {
        
           sort(p, p + n); 
      } 

      //getter
      int* get() {

           return p; 
      } 

};

int arr[ MAXN ], 
    n,
   *p;

    
int main() {

    SORT q;

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    scanf("%d", &n);

    for(int i=0;i<n;i++) scanf("%d", &arr[i]); 
     
    q.set(arr, n);

    q.sorting();
   
    p = q.get();

    for(int i=0;i<n;i++) {

        printf("%d ",p[i]); 
    }    

    fclose( stdin );

    return(0);
}