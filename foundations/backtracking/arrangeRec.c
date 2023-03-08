#include <stdio.h>
#define DIM 100

int stack[DIM],
    n,k;

int valid(int level) {

    for(int i = 1; i < level; i++) {

      if(stack[i] == stack[level]) {

        return 0;
      }
    }
    return 1;
}

void display_solution() {

      for(int i = 1; i <= k; ++i) {

          printf("%d ", stack[i]);

      }
      printf("\n");
}

void solve(int level) {

     if(level > k) {

        display_solution();

     } else {

       for(int i = 1; i <= n; ++i) {

           stack[ level ] = i;

           if(valid( level ))

              solve( level + 1 );
       }
     }
}

int main(int argc, char const *argv[]) {

  n = 4;
  k = 2;

  solve( 1 );

  return 0;
}
