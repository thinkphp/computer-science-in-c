#include <stdio.h>
 
typedef unsigned int uint;
 
uint fact2(uint n) {
 
     uint r = 1;
 
     for(uint i = 1; i <= n; ++i) {
 
         r *= i;
     }
 
     return r;
}
 
uint fact3(uint n) {
 
     if(n == 1) {
 
       return 1;
 
     } else {
 
       return n * fact3(n - 1);
     }
}
 
uint fact(uint n,uint a) {
    if(n == 1) {
       return a;
    } else {
      return fact(n - 1, a * n);
    }
}
 
int main() {
    uint n;
    scanf("%d", &n);
    printf("%d\n", fact2(n) );
    printf("%d\n", fact3(n) );
    printf("%d\n", fact(n,1) );
}
 
