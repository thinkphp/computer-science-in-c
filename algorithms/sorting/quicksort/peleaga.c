#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXSIZE 500050

void quicksort(int lo, int hi, int vec[]) {

     int i, j, p;

     i = lo;
     j = hi;
     p = vec[(lo + hi)>>1];

     while(i <= j) {
          while(p > vec[i]) i++;
          while(p < vec[j]) j--;
          if(i<=j){
            int aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
                i++;j--;
          }
     }

     if(lo < j) quicksort(lo, j, vec);
     if(i < hi) quicksort(i, hi, vec);
}

void sort(int vec[], int n) {

      quicksort(0, n - 1, vec);
}

int main(int argc, char const *argv[]) {

  int n,
      vec[ MAXSIZE ];

  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);

  scanf("%d", &n);

  for(int i = 0; i < n; ++i) {
    scanf("%d", &vec[i]);
  }

  sort(vec, n);

  for(int i = 0; i < n; ++i) {
    printf("%d ", vec[i]);
  }

  return 0;
}
