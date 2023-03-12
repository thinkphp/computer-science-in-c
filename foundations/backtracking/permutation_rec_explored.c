#include <stdio.h>
#define DIM 100

int n, stack[DIM], explored[DIM];

void print_permutation() {
     for(int i = 1; i <= n; ++i) {
       printf("%d ", stack[i]);
     }
     printf("\n");
}

void perm(int level) {
     if(level > n) {
        print_permutation();
     } else {
       for(int i = 1; i <= n; ++i) {
         if(!explored[i]) {
           stack[level] = i;
           explored[i] = 1;
           perm(level+1);
           explored[i] = 0;
         }
       }
     }
}

int main(int argc, char const *argv[]) {

  n = 3;
  perm(1);

  return 0;
}
