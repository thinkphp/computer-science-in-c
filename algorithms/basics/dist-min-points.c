#include <stdio.h>
#include <math.h>
//gcc dist-min-points.c -lm

typedef struct Point {
  double x,
         y;
} TPoint;

double sqrt2(double n) {

    double x = n,
           y = 1,
           e = 0.000001;
    while(x-y>e) {
      x = (x + y) / 2;
      y = n / x;
    }
    return x;
}

void readPoint(TPoint*p) {
     printf("Abs = ");
     scanf("%lf", &p->x);
     printf("Ord = ");
     scanf("%lf", &p->y);
}

double computeDist(TPoint p, TPoint q) {
   return sqrt((q.x - p.x)*(q.x - p.x) + (q.y-p.y)*(q.y-p.y));
}

int main(int argc, char const *argv[]) {
  int n;//number of points
  TPoint P0,P1,P;
  double dist, d;

  printf("%s#0\n", "Point");
  readPoint(&P0);

  printf("%s\n", "Number of points from Set A");
  scanf("%d", &n);

  printf("%s\n", "Point#1");
  readPoint(&P1);

  dist = computeDist(P0, P1);

  for(int i = 2; i <= n; ++i) {

    printf("%s#%d\n", "Point",i);
    readPoint(&P);
    d = computeDist(P0, P);

    if(d < dist) {
      P1 = P;
      dist = d;
    }
  }

  printf("min dist = %.3lf\n", dist);
  printf("The closest Point is P(%.2lf,%.2lf)\n", P1.x, P1.y);

  return 0;
}
