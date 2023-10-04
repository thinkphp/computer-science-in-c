#include <stdio.h>

double sqrt2(int n) {

  double x = n,
         y = 1,
         e = 0.0000001;

  while(x-y>e) {
    x = (x + y) / 2;
    y = n / x;
  }
  return x;
}

int isPrime(int n) {

    int prime = 2,
    i = 2;

    if(n<=1) return 0;

    if(n == 2 || n == 3) return 1;

    for(int i = 2; i <= sqrt2(n) && prime; ++i) {

        prime = (n % i) != 0;
    }

    return prime;
}

int main(int argc, char const *argv[]) {
  int count = 0,
  how_many = 10,
  i = 2,
  n = 2;

  printf("%s", "How many prime numbers? N = ");
  scanf("%d", &how_many);

  while(count!=how_many) {
     if(isPrime(n)) {
        if(count==how_many-1) printf("%d", n);
              else printf("%d, ", n);
        count++;
     }
     n++;
  }

  return 0;
}
