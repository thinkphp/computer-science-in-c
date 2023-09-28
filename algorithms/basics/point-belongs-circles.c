#include <stdio.h>
#define sqr(x) ((x)*(x))
/*
Se dau la intrare N cercuri, date fiecare prin coordonatele centrului si raza (numere reale)
ce se incadreaza in tipul standard float si un punct in plan. Decideti caruia dintre discurile cercurilor ii apartine punctul dat.
*/

typedef struct Point {
  float x,
        y;
} TPoint;

typedef struct Circle {
  TPoint O;
  float R;
} TCircle;

float sqrt2(float n) {
  float x = n, y = 1, e = 0.000001;
  while(x-y>e){
    x = (x+y) / 2;
    y = n/x;
  }
  return x;
}

float computeDistance(TPoint p1, TPoint p2) {
      return sqrt2(sqr(p2.x-p1.x) + sqr(p2.y-p1.y));
}

int belongTo(TCircle C, TPoint P) {
  if(computeDistance(P, C.O) < C.R) {
    return 1;
  } else {
    return 0;
  }
}
int main(int argc, char const *argv[]) {
  int n;
  TCircle C[100];
  TPoint P;

  printf("%s","Dati numarul de cercuri N = ");
  scanf("%d", &n);

  printf("%s","Introduceti cercurile:\n");

  for(int i = 0; i < n; ++i) {
    printf("Cercul#%d:\n", i + 1);
    printf("Centrul O(x,y) = ");
    scanf("%f %f", &C[i].O.x, &C[i].O.y);
    printf("R = ");
    scanf("%f", &C[i].R);
  }

  printf("%s","Introduceti punctul P(x,y):");
  scanf("%f %f", &P.x, &P.y);

  printf("\n--------%s--------\n","Output:");

  printf("Punctul P(%3.3f,%3.3f) apartine cercurilor: \n", P.x, P.y);

  for(int i = 0; i < n; ++i) {
    if(belongTo(C[i], P)) {
      printf("%d. C(%3.3f, %3.3f, %3.3f)\n", i+1, C[i].O.x, C[i].O.y, C[i].R);
    }
  }

  return 0;
}
