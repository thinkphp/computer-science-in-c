#include <stdio.h>
 
const int SIZE = sizeof(int)*8;
 
int isPrime(int n) {
  int i = 2,
  prime = 1;
  if(n<=1)return 0;
  if(n == 2 || n == 3) return 1;
  while(i*i<=n && prime){
    prime = (n%i)!=0;
    i++;
  }
  return prime;
}
 
void dec2bin(int n) {
    for(int i = SIZE-1; i >= 0; i--) {
        if((n>>i)&1) printf("%s","1");
               else  printf("%s","0");
    }
}
 
int main(int argc, char const *argv[]) {
 
  //int n = atoi(argv[1]);
  int num = 7919;
  for(int i = 2; i <= num; ++i)
  if(isPrime(i))
     dec2bin(i), printf("\n");
  return 0;
}
