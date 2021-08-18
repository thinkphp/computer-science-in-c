#include <stdio.h>
 
void readPolynom(int *p, int *n) {
 
      printf("Give the degree of the polynom -> ");
      scanf("%d", n);
      for(int i = 0; i <= *n; i++) {
          printf("P[%d] = ", i);
          scanf("%d", (p + i));
      }
}
 
void writePolynom(int *p, int *n) {
 
     printf("p(x) = %dx^0", p[0]);
     for(int i = 1; i <= *n; i++) {
        printf(" + %dx^%d", p[i], i);
     }
}
 
float valuePolynom(int *p, int *n, float x) {
 
      float value = p[0],
            aux = 1;
 
      for(int i = 1; i <= *n; ++i) {
           aux = aux * x;
           value += aux * p[i];
      }
 
      return value;
 
}
 
void derivatePolynom(int *p, int *n) {
 
      for(int i = 0; i < *n; i++) {
         p[ i ] = p[i + 1] * (i + 1);
      }
      (*n)--;
}
 
int main(int argc, char const *argv[]) {
 
    int coef[100], //coefficients
        n;//degrees
 
    readPolynom(coef, &n);
    writePolynom(coef, &n);
    derivatePolynom(coef, &n);
    printf("\n");("\n");
    writePolynom(coef, &n);
    float x = 1.450;
    float ans = valuePolynom(coef, &n, x);
    printf("\np(%.3f) = %.3f", x, ans);
    printf("\n");
  return 0;
}
