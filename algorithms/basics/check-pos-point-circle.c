#include <stdio.h>

typedef struct Point {
    float x,//abscice
          y;//ordonate
} TPoint;

typedef struct Circle {
    TPoint O;
    float R;
} TCircle;

float sqrt2(float n) {
    float x = n,
          y = 1.0,
          eps = 0.0000001;

    while(x-y>eps) {
      x = (x+y)/2;
      y = n / x;
    }
    return x;
}

float sqr(float x) {return x*x;}

int main(int argc, char const *argv[]) {

  float x,y,R,//the circle
        x0,y0;//the point
  printf("Introduceti Cercul: C(O,R)\n");
  scanf("%f %f %f", &x,&y,&R);
  printf("Introduceti Point: P(x,y)\n");
  scanf("%f %f", &x0,&y0);

  float dist = sqrt2(sqr(x-x0)+sqr(y-y0));
  printf("Distance from the center of the circle to the Point = %f\n",dist);
  dist -= R;

  if(dist < 0) {
     printf("%s\n", "The point is inside the Circle.");
  } else if(dist == 0) {
     printf("%s\n", "The point is on the Circle.");
  } else {
     printf("%s\n", "The point is outside the Circle.");
  }

  return 0;
}
