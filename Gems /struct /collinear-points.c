#include <stdio.h>

//Reference: https://mathworld.wolfram.com/Collinear.html

typedef struct Point {
    float x,//abscisa
          y;//ordonata
} TPoint;

//method number#2
/*
Sarrus Rule:
    x1 y1 1
A = x2 y2 1
    x3 y3 1
    x1 y1 1
    x2 y1 1
    x1y2 + x2y3 + x3y1 - x3y2 - x1y3-x2y1 = x1(y2-y3) - y1(x2-x3) + (x2y3-x3y2)
*/
int checkCollinearity(TPoint P1, TPoint P2, TPoint P3) {

    return (P1.x*(P2.y-P3.y) - P1.y*(P2.x-P3.x) + P2.x*P3.y - P2.y*P3.x);
}

int main(int argc, char const *argv[]) {

  TPoint P[3];

  for(int i = 0; i < 3; ++i) {
     printf("Point#%d\n",i+1);
     scanf("%f %f",&P[i].x, &P[i].y);
  }
  if(P[0].x == P[1].x || P[0].x == P[2].x) {

     if(P[2].x == P[0].x) {
        printf("Collinear Points.\n");
     }  else {
        printf("No Collinear Points.\n");
     }
     //compute the slope of the line AB
     //y2-y1/x2-x1
  } else {
     if( (P[1].y - P[0].y)/(P[1].x - P[0].x) == (P[2].y - P[1].y)/(P[2].x - P[1].x)) {
         printf("Collinear Points.\n");
     } else {
         printf("No Collinear Points.\n");
     }
  }

  if(checkCollinearity(P[0],P[1],P[2]) == 0) {
         printf("Collinear Points.\n");
  } else {
         printf("No Collinear Points.\n");
  }
  return 0;
}
