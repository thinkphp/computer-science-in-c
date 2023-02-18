#include <stdio.h>
#define SIZE 100

int vec[] = {-11,-131,-3,141,-5,-72,77};

int best[SIZE];

int main(int argc, char const *argv[]) {

    int n, k, max ;

    n = sizeof(vec)/sizeof(vec[0]);

    best[n-1] = 1;

    for(int i = n - 2; i >= 0; i--) {

        max = 0;

        int temp = vec[ i ];

        for(int k = i+1; k < n; k++) {

            if(vec[ k ] > temp && best[ k ] > max){

              max = best[ k ];
            }
        }
        best[ i ] = 1 + max;
    }
    int maxEl = best[ 0 ], posEl = 0;

    for(int i = 1; i < n; ++i ){
      if(best[ i ] > maxEl) {
        maxEl = best[ i ];
        posEl = i;
      }
    }

    printf("%d ", vec[posEl]);

    int pos = maxEl;

    pos--;

    for(int k = posEl + 1; k < n; ++k) {
      if(pos == best[k] && vec[k] > vec[posEl]) {
         printf("%d ", vec[k]);
         pos--;
      }
    }

  return 0;
}
