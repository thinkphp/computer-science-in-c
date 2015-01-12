#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int vec[ MAXN ],
    N,
    newvec[ MAXN ];

void read() {

     int i;
 
     freopen(FIN, "r", stdin);

     scanf("%d", &N); 

     for(i = 0; i < N; i++) scanf("%d ", &vec[ i ]);

     fclose( stdin );      
};    

void _merge(int left, int middle, int right) {

         int i = left,

             j = middle + 1, 

             k = 0;

          while(i <= middle && j <= right) {

                if(vec[ i ] <= vec[ j ]) {

                   newvec[ k++ ] = vec[ i++ ];

                } else {

                   newvec[ k++ ] = vec[ j++ ];
                }
          } 

          while(i <= middle) {

                   newvec[ k++ ] = vec[ i++ ];         
          } 

          while(j <= right) {

                   newvec[ k++ ] = vec[ j++ ];
          } 

          k = 0;

          for(i = left; i <= right; i++) {

              vec[ i ] = newvec[ k++ ];
          } 
};

void _mergesort(int left, int right) {

     if(left == right) return;

     else {

          int middle = (left + right) >> 1;

          _mergesort(left, middle);    

          _mergesort(middle + 1, right);

          _merge(left, middle, right);
     }   
};

void sort() {

     _mergesort(0, N - 1); 
}; 

void write() {

     int i;
 
     freopen(FOUT, "w", stdout);

     scanf("%d", &N); 

     for(i = 0; i < N; i++) printf("%d ", vec[ i ]);

     fclose( stdout );      
};

int main() {

    read();
    sort();
    write();               
 
    return(0);         
};