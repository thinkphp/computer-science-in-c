#include <cstdio>
#include <algorithm>
#define MAXN 500005
#define FIN "mysort.in"
#define FOUT "mysort.out"

using namespace std;

int arr[MAXN],
    n,
    *x;

class SORT {

      public: 
      int *p, 
           n;
  
      SORT(int arr[], int num) {
 
          p = arr;  
          n = num;
      }
      
      void sorte() {
 
          sort(p + 1, p + 1 + n);
      } 

      int* get() {

           return p;
      }
};

//function prototypes
void read();
void write();

int main() {

    read(); 
     
    SORT s( arr, n ); 

    s.sorte();

    x = s.get();

    write();

    return(0);
};

void read() {

    freopen(FIN, "r", stdin);

    scanf("%d", &n); 

    for(int i = 1; i <= n; i++ ) scanf("%d ", &arr[ i ]);

    fclose( stdin );
};

void write() {

    freopen(FOUT, "w", stdout);

    for(int i = 1; i <= n; i++ ) printf("%d ", x[ i ]);

    fclose( stdout );
}
