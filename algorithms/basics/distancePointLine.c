#include <stdio.h>

typedef struct point {

    float x,  //abscise
          y;  //ordonate
} Point;

Point A, B, //line
P;//point
//coefs
float a, b, c;

float module(float n) {
      if(n<0){
        return -n;
      } else{
        return n;
      }
}

float sqrt2(float n) {
      float x = n,
            y = 1,
            e = 0.000001;
      while(x - y > e) {
        x = (x + y) / 2;
        y = n / x;
      }
      return x;
}

float computeCoefs(void) {

   a = A.y - B.y;
   b = B.x - A.x;
   c = (B.x * A.y) - (A.x * B.y);
}

void readPoint(Point*a) {

     printf("Abs=");
     scanf("%f", &a->x);
     printf("Ord=");
     scanf("%f", &a->y);
}

float distance(void) {

  return module((a*P.x+b*P.y+c)/sqrt2(a*a+b*b));
}

int main(int argc, char const *argv[]) {

  readPoint(&A);
  readPoint(&B);
  readPoint(&P);
  printf("A(%.2f,%.2f)\n",A.x,A.y);
  printf("B(%.2f,%.2f)\n",B.x,B.y);
  printf("Point(%.2f,%.2f)\n",P.x,P.y);
  computeCoefs();
  printf("a=%.2f b=%.2f c=%.2f\n", a, b, c);
  float dist = distance();
  printf("d(line, Point) = %.2f", dist);
  return 0;
}
