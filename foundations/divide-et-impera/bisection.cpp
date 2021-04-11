/*
 * Bisection Method.
 * x^2 - a = 0
 */
#include <iostream>

using namespace std;

double EPS = 0.00001;

double f(double x, int a) {

       return x * x - a;
}

double divideEtImpera(double lo, double hi, int a) {

    if(hi - lo <= EPS) return (lo + hi) / 2;

    else {

         double m = (lo + hi) / 2;
         //cout<<m<<endl;
         if(f(lo,a) * f(m,a) < 0) {

            return divideEtImpera(lo, m, a);

         } else {

            return divideEtImpera(m, hi, a);
         }
    }
}

//Bisection method using iteration
void bisection(double lo, double hi, double a) {

     double m;

     while((hi - lo) >= EPS) {

          m = (lo + hi) / 2;

          if(f(lo, a) * f(m, a) < 0) {

               hi = m;

          } else {

               lo = m;
          }

          cout<<m<<endl;
     }

     cout<<m<<endl;
}


//Bisection method using iteration - version 2
void bisection2(double lo, double hi, double a) {

     double m, y_x, y_m;

     while((hi - lo) >= EPS) {

          m = (lo + hi) / 2;

          y_x = lo * lo - a;
          y_m = m * m - a;

          if( (y_x > 0 && y_m < 0) || (y_x < 0 && y_m > 0)) {

               hi = m;

          } else {

               lo = m;
          }

          cout<<m<<endl;
     }

     cout<<m<<endl;
}

int main(int argc, char const *argv[]) {
  int a;
  a = 4;
  cout<<divideEtImpera(0, a + 5, a)<<endl;
  bisection(0, a + 5, a);
  bisection2(0, a + 5, a);
  return 0;
}
