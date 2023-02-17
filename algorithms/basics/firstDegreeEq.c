#include <stdio.h>

double sqrt_babylon(float num) {
      float x, y, EPS;
      x = num;
      y = 1.0;
      EPS = 0.000001;

      while(x - y > EPS) {
         x = (x + y) / 2;
         y = num / x;
      }
      return x;
}

int main(int argc, char const *argv[]) {

  float x, a, b;

  printf("a = ");
  scanf("%f", &a);
  printf("b = ");
  scanf("%f", &b);
  printf("sqrt(%.2f) = %f \nsqrt(%.2f) = %f\n", a, sqrt_babylon(a), b, sqrt_babylon(b));

  if(a != 0) {
     if(b != 0) {
       x = -b/a;
       printf("x = %f\n", x);
     } else {
       //it means a != 0 and b == 0
       printf("x = 0\n");
     }
  } else {
    //it means a == 0 and if b == 0
    if(b == 0) {
      printf("The equation has an infinity solutions.\n");
    } else {
      //that means b != 0 and a == 0
      printf("The equation doen't has solutions.\n");
    }
  }
  return 0;
}
