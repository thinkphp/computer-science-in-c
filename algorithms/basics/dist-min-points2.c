#include <stdio.h>

double x_0,y_0,
       x_1,y_1,
       x,y,
       dist, d;

int n;//number of points

double sqrt2(double n) {

    double e = 0.000001,
           x = n,
           y = 1;

    while(x-y>e) {
      x = (x+y)/2;
      y = n/x;
    }
    return x;
}

int main(int argc, char const *argv[]) {

  printf("Point#0:\n");
  printf("abs=");
  scanf("%lf",&x_0);
  printf("ord=");
  scanf("%lf",&y_0);

  printf("Number of points:");
  scanf("%d",&n);

  printf("Point#1:\n");
  printf("abs=");
  scanf("%lf",&x);
  x_1 = x;
  printf("ord=");
  scanf("%lf",&y);
  y_1 = y;
  dist = sqrt2((x-x_0)*(x-x_0) + (y-y_0)*(y-y_0));

  for(int i = 2; i <= n; i++) {

    printf("Point#%d:\n",i);
    printf("abs=");
    scanf("%lf",&x);
    printf("ord=");
    scanf("%lf",&y);
    d = sqrt2((x-x_0)*(x-x_0) + (y-y_0)*(y-y_0));

    if(d<dist) {
      x_1 = x;
      y_1 = y;
      dist = d;
    } //end if

  }//end for
  printf("dist = %lf; Point(%.2lf,%.2lf)", dist, x_1, y_1);

  return 0;
}
