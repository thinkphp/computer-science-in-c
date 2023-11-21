#include <iostream>
#include <cmath>
#define LL long long

using namespace std;
LL a, b, c;

int main(int argc, char const *argv[]) {
  scanf("%lld%lld%lld",&a, &b, &c);
  LL delta = b*b-4*a*c;
  if(!a && !b && !c) puts("-1");
  else if(!a && !b) puts("0");
  else if(!a) printf("1\n%.8lf\n",-1.0*c/b);
  else if(delta<0) puts("0");
  else if(delta==0) printf("1\n%.8lf\n",-b/2.0/a);
  else {
    puts("2");
    double x1 = (-b+sqrt(delta))/2.0/a, x2 = (-b-sqrt(delta))/2.0/a;
    if(x1>x2) swap(x1,x2);
    printf("%.8lf\n%.8lf",x1,x2);
  }
  return 0;
}
