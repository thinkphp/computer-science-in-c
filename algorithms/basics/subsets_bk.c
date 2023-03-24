#include <stdio.h>
#define DIM 100

int n, stack[DIM];

void subset(int level) {

     for(int i = 1; i <= level;++i) {

       printf("%d ", stack[i]);

     }
     
     printf("\n");
}

void solve(int level){
  
     if(level<=n) {      
       for(int i = stack[level-1]+1; i <= n; ++i) {
         stack[level] = i;
         subset(level);
         solve(level+1);
       }
     }
}

int main(int argc, char const *argv[]) {

  scanf("%d", &n);
  solve(1);

  return 0;
}
