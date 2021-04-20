#include <stdio.h>

void factorial_divide_et_impera(int lo, int hi, int* res) {

      int a, b;

      if(lo == hi) *res = lo;
      else {
           int m = (lo + hi) >> 1;
           factorial_divide_et_impera(lo, m, &a);
           factorial_divide_et_impera(m + 1, hi, &b);
           *res = a * b;
      }
}

int main(int argc, char const *argv[]) {

  int n, res;

  n = atoi(argv[1]);
  factorial_divide_et_impera(1, n, &res);
  printf("%d\n", res);

  return 0;
}
