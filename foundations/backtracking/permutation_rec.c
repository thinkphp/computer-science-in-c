 #include <stdio.h>
#define DIM 100

int stack[DIM],
    n;

int valid(int level) {

    for(int i = 1; i < level; i++) {

      if(stack[i] == stack[level]) {

        return 0;
      }
    }
    return 1;
}

void display_solution() {

      for(int i = 1; i <= n; ++i) {

          printf("%d ", stack[i]);

      }
      printf("\n");
}

void solve(int level) {

     if(level > n) {

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

  n = 5;

  solve( 1 );

  return 0;
}
