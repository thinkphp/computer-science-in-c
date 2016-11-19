#include <stdio.h>

long sum(long n) {

     if(n == 0) return 0;

     return n % 10 + sum(n / 10);
}

int main() {

    printf("%d",sum(1234567));

  return(0);
}