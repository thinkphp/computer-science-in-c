#include <stdio.h>
#define FIN "euclid3.in"
#define FOUT "euclid3.out"

void euclid_extended(int a, int b, int *d, int *x, int *y) {

    if(b == 0) {
      *d = a;
      *x = 1;
      *y = 0;
    }   else {
        int x1, y1;
        euclid_extended(b, a%b, d, &x1, &y1);
        *x = y1;
        *y = x1 - (a/b)*y1;
    }
}

int euclid(int a, int b) {

    if(b == 0) return a;

    else return euclid(b, a % b);
}

int gcd(int a, int b) {
  while(a != b) {
   if(a > b) {
     a -= b;
   } else {
     b -= a;
   }
  }
   return a;
}

int euclid_it(int a, int b) {

  int r;

  while(b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main(int argc, char const *argv[]) {

  int a,
      b,
      c;
  int T;
  freopen(FIN,"r",stdin);
  freopen(FOUT,"w",stdout);
  scanf("%d", &T);

  while(T--){

  scanf("%d %d %d", &a, &b, &c);
  /*
  int ans = euclid(a, b);

  printf("%d\n", ans);

  ans = euclid_it(a, b);

  printf("%d\n", ans);

  ans = gcd(a, b);

  printf("%d\n", ans);
  */

  int d, x, y;

  euclid_extended(a,b,&d,&x,&y);

  if(c%d!=0) printf("%d %d\n", 0, 0);

  else

  printf("%d %d\n",c/d*x, c/d*y);
  }
  return 0;
}
