#include <stdio.h>
#include <memory.h>
#define SIZE 30000
 
char sieve[SIZE/8+1];
 
int isOne(int n, int pos) {
  return (n>>pos)&1;
}
 
int isPrime(int n) {
  if(n<=0) return 0;
  return !isOne(sieve[n/8],n%8);
}
int main()
{
  int i,j,n,aux;
  n = 1000;
  memset(sieve, 0, sizeof(sieve));
  for(i = 2; i*i<=n; ++i) {
      if(isOne(sieve[i/8],i%8) == 0) {
        j = 2;
        while(i*j<=n) {
          aux = 1; aux <<= (i*j)%8;
          sieve[(i*j)/8] |= aux;
          j++;
        }
      }
  }
  for(int i = 2; i <= 100; ++i) {
      printf("%d: ", i);
      if(isPrime(i)) {
        printf("%s\n", "Prime.");
      } else {
        printf("%s\n", "Compound.");
      }
  }
  return(0);
}
