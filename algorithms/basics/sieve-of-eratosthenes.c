#include <stdio.h>
#include <memory.h>
#define DIM 50000
 
int main ()
{
  int sieve[DIM],i,j,n;
  n = 10000;
  memset(sieve, 1, sizeof(sieve));
 
  i = 2;
  while(i*i<=n) {
    if(sieve[i]) {
      j = 2;
      while(i*j<=n){
        sieve[i*j] = 0;
        j++;
      }
    }
    i++;
  }
  for(i = 2; i <= n; ++i) {
    if(sieve[i]) printf("%d ", i);
  }
  return 0;
}
