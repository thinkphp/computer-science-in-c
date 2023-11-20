#include <stdio.h>
#include <math.h>
 
typedef struct Q {
 
        float a, 
              b,
              c; 
 
} E;
 
float computeDelta(float a, float b, float c) {
 
      return b*b - 4*a*c; 
}
 
void displayEq(float a, float b, float c) {
 
     printf("%3.3f*x^2 + %3.3f*x +  %3.3f = 0\n", a, b, c); 
}
 
int main() {
 
    E q;
    float D;
    printf("a,b,c=?");
    scanf("%f %f %f", &q.a, &q.b, &q.c);
 
    D = computeDelta(q.a,q.b,q.c); 
 
    displayEq(q.a, q.b, q.c);
 
    if(D < 0) printf("%s\n", "Equation do not have real solutions.");
 
        else if(D == 0) printf("x1 = x2 = %3.3f\n", -q.b/2*q.a);
 
             else if(D > 0) {
 
                     float x1, x2;
                     x1 = (-q.b + sqrt(D))/(2*q.a);  
                     x2 = (-q.b - sqrt(D))/(2*q.a);
                     printf("x1 = %3.3f x2 =%3.3f\n", x1, x2);  
             } 
 
    return(0);
}
