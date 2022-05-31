#include <stdio.h>
#define FIN "submultimi.in"
#define FOUT "submultimi.out"

int pow2(int x, int y) {

     int p = 1;
     for(int i = 1; i <= y; ++i) {
         p *= x;
     }
     return p;
}

void generate_subsets(int N) {

  int n;

  freopen(FOUT, "w", stdout);

  n = pow2(2, N);

  for(int i = 1; i <= n; ++i) {
      for(int j = 0; j < N; ++j) {
        if(i&(1<<j)) {
           printf("%d ", (j+1));
        }
      }
      printf("\n");
  }

}
int main(int argc, char const *argv[]) {

  int N;

  freopen(FIN, "r", stdin);

  scanf("%d", &N);

  generate_subsets(N);

  return 0;
}
