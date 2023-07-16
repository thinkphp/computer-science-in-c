#include <stdio.h>
#define LLI long long int
#define SZ 2000

LLI n, k, C[SZ][SZ],i, j;

int main(int argc, char const *argv[]) {

  n = 7;
  k = 4;

  C[0][0] = 1;

  for(i = 1; i <= n; ++i) {

    for(j = 0; j <= i; ++j) {

        if(0 == j || i == j) C[i][j] = 1;
        else
        C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }

  for(i = 0; i <= n; ++i) {

    for(j = 0; j <= i; ++j) {

       printf("%lld ",C[i][j]);
    }

    printf("\n");
  }

  printf("%lld ",C[n][k]);

  return 0;
}
