#include <stdio.h>
#include <math.h>
#include <time.h>
#define sqr(x) ((x)*(x))

double monte_carlo() {

       srand(time(NULL));

       int count = 0, countSquare = 0;

       int repeats = 1<<20;

       double x, y;

       for (size_t i = 0; i < repeats; i++) {

           x = (double)(rand() % (1000 + 1)) / 1000;

           y = (double)(rand() % (1000 + 1)) / 1000;

           if(sqr(x) + sqr(y) <= 1) {

              count++;
           }
           countSquare++;
       }

       return 4 * (double) count / countSquare;
}

double PI() {
  double t1 = 1,
         t2 = 1 - (double)1/3,
         eps = 0.00001;
  int sign = 1;
  int i = 5;
  while(4 * (t1 > t2 ? t1 - t2 : t2 - t1) >= eps) {
       t1 = t2;
       t2 += sign * (double)1/i;
       sign *= -1;
       i+=2;
  }
  return 4*t2;
}

float pow2(int a, int b) {
   int res = 1;
   if(b==0) return 1;
   else {
     for(int i = 1; i <= b; i++)
        res *= a;
   }
   return res;
}

float leibniz(int terms) {

      float sum = 0, term;
      for(int i = 0; i <= terms; ++i) {
          term = pow2(-1,i) / (2 * i + 1);
          sum += term;
      }
      return 4 * sum;
}
int main(int argc, char const *argv[]) {
  int terms;
  float pi;
  printf("%s", "Number of terms = ");
  scanf("%d",&terms);
  pi = leibniz(terms);
  printf("(Leibniz) PI ~ %f\n", pi);
  printf("(Leibniz) PI ~ %f\n", PI());
  printf("(Monte Carlo) PI ~ %f\n", monte_carlo());
  return 0;
}
