#include <stdio.h>
#define sqr(x) ((x)*(x))
#define EPS 0.00001f

/*
Se dau un cerc (centru si raza, tip float) si un punct in plan.
Decideti daca punctul este pe cerc, in interiorul sau in exteriorul cercului.
*/

typedef struct Point {
  float x,
        y;
} TPoint;

typedef struct Circle {
  TPoint O;
  float R;
} TCircle;

float absf(float a) {
  return a < 0 ? -a : a;
}

/* Returneaza: 0 = pe cerc, -1 = in interior, 1 = in exterior.
   Se compara patratul distantei cu patratul razei (fara radical),
   cu toleranta EPS pentru erorile de reprezentare ale tipului float. */
int pozitie(TCircle C, TPoint P) {
  float d2 = sqr(P.x - C.O.x) + sqr(P.y - C.O.y);
  float r2 = sqr(C.R);
  float diff = d2 - r2;
  float prag = EPS * (r2 > 1 ? r2 : 1);

  if (absf(diff) <= prag) return 0;
  return diff < 0 ? -1 : 1;
}

int main(void) {
  TCircle C;
  TPoint P;

  printf("Centrul cercului O(x,y) = ");
  scanf("%f %f", &C.O.x, &C.O.y);

  printf("Raza R = ");
  scanf("%f", &C.R);
  if (C.R <= 0) {
    printf("Raza trebuie sa fie pozitiva.\n");
    return 1;
  }

  printf("Punctul P(x,y) = ");
  scanf("%f %f", &P.x, &P.y);

  printf("\n--------Output:--------\n");
  printf("Cercul C(%.3f, %.3f, %.3f)\n", C.O.x, C.O.y, C.R);
  printf("Punctul P(%.3f, %.3f) este ", P.x, P.y);

  switch (pozitie(C, P)) {
    case 0:  printf("pe cerc.\n");          break;
    case -1: printf("in interiorul cercului.\n"); break;
    default: printf("in exteriorul cercului.\n");
  }

  return 0;
}
