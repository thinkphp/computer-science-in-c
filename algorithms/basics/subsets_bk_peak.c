#include <stdio.h>
#define FIN "submultimi.in"
#define FOUT "submultimi.out"
#define DIM 20
 
int stack[DIM], N;
 
void print(int peak) {
     for(int i = 1; i <= peak; ++i) {
       printf("%d ", stack[i]);
     }
     printf("\n");
}
 
void bk(int peak) {
 
     for(int x = stack[peak - 1] + 1; x <= N; x++) {
         stack[peak] = x;
         print(peak);
         bk(peak + 1);
     }
}
 
 
int main(int argc, char const *argv[]) {
 
  freopen(FIN, "r", stdin);
 
  scanf("%d", &N);
 
  freopen(FOUT, "w", stdout);
 
  bk(1);
 
  return 0;
}
