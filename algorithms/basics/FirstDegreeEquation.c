#include <stdio.h>

int main(int argc, char const *argv[]) {

  float x, a, b;

  printf("Linear Equation Resolver\n");
  printf("Given a equation as 'a * x + b = 0', please enter constants:\n");
  
  printf("a = ");
  scanf("%f", &a);
  
  printf("b = ");
  scanf("%f", &b);

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
