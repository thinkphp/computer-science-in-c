#include <stdio.h>
#include <stdlib.h>
#define VOID 0

double sqrt(double n) {

  double x = n, y = 1.0, e = 0.000001;

  while(x - y > e) {

    x = (x + y) / 2;

    y = n / x;

  }
  return x;
}

void NatureRootsQuadraticEquation(double a, double b, double c) {

    double S = -b/a,
            P = c/a,
            discriminant = b*b - 4*a*c,
            x1, x2;
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);
    printf("S=%.2lf P=%.2lf\n",S,P);
    printf("Delta = %.2lf\n\tx1=%lf\n\tx2=%lf\n", discriminant, x1, x2);

    if(discriminant >= 0) {

      if(S >= 0) {

         if(P > 0) {

            printf("%s","x1>0; x2>0");

         } else if(P < 0) {

            printf("%s","x1>0; x2<0; |x1| < |x2|");

         } else {

            printf("%s","x1=0; x2 >0");
         }
      //it means S < 0
      } else {

        if(P > 0) {

           printf("%s","x1<0; x2<0");

        } else if(P < 0) {

           printf("%s","x1>0; x2<0");

        } else {

           printf("%s","x1=0; x2 <0");
        }
      }
    } else {
      printf("Imaginary");
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
  //declare three variable of double
  double a, b, c;
  a = 1;
  b = 3;
  c = -2;
  //if the number of the arguments is greater than one
  if(argc > 1){
    //convert string to double
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);
  }

  //tests
  if(b < 0 && c < 0) {
       printf("%.3lfx^2 - %.3lfx - %.3lf = 0\n", a, -b, -c);
  } else if(b < 0) {
       printf("%.3lfx^2 - %.3lfx + %.3lf = 0\n", a, -b, c);
  } else if(c < 0) {
       printf("%.3lfx^2 + %.3lfx - %.3lf = 0\n", a, b, -c);
  } else if(a > 0 && b > 0 && c > 0){
       printf("%.3lfx^2 + %.3lfx + %.3lf = 0\n", a, b, c);
  }
  //solve
  printf("%s\n", "Output:");
  NatureRootsQuadraticEquation(a, b, c);

  return VOID;
}
