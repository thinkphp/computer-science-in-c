#include <stdio.h>
#include <string.h>

int val(char c) {

    if(c >= '0' && c <= '9') {

       return c - '0';

    } else if(c >= 'A' && c <= 'Z') {

       return c - 'A' + 10;
    }
}
int pw(int a, int b) {

    int p = 1;

    for(int i = 1; i <= b; ++i) {
       p *= a;
    }
    return p;
}

int conv(char s[ 100 ]) {

    int n = strlen( s );

    int num = 0,

        p = 0;

    for(int i = n - 1; i >= 0; --i) {

       num += val(s[i]) * pw(16, p);

       p += 1;
    }
    return num;
}

int gcd( int a, int b ) {

      while( a != b ) {

        if(a > b) {

          a = a - b;

        } else {

          b = b - a;
        }
      }
      return a;
}

int main(int argc, char const *argv[]) {

  char* s[] = {"AA", "BB", "CC", "DD","EE","FF"};

  int n = sizeof(s)/sizeof(s[0]);

  int sol = gcd(conv(s[0]), conv(s[1]));

  for(int i = 2; i < n; ++i) {
          int b = conv(s[i]);
          sol = gcd(sol, b);
  }
  printf("%d", sol);

  return 0;
}
