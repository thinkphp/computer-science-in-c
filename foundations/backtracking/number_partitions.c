#include <stdio.h>
#define DIM 100

int stack[DIM],
    N,
    level,
    s;

void init(){
     if(level == 1) {
       stack[level] = 0;
     } else {
       stack[level] = stack[level-1] - 1;
     }
}

int succ() {
    if(stack[level] < N - s) {
       stack[level]++;
       return 1;
    } else {
       s -= stack[level-1];
       return 0;
    }
}

int valid() {

    if(stack[level] <= N - s) {
       s = s + stack[level];
       return 1;
    }
    return 0;
}

void print() {
     //converted to string
     char out[10];
          int k = 0;
          for(int i = 1; i <= level;i++) {
              out[k++] = stack[i] + '0';
              out[k++] = '+';
          }
          out[--k] = '\0';
          s -= stack[level];
          printf("%s", out);
     printf("\n");
}

int sol() {
    return s == N;
}

void bk() {
     level = 1;
     init();

     while(level > 0) {
          int hs = 1, iv = 0;
          while(hs && !iv) {
                hs = succ();
                if(hs) {
                  iv = valid();
                }
          }
          if(hs) {
            if(sol()) print();
               else {
                 level++;
                 init();
               }
          } else {
            level--;
          }
     }
}

int main(int argc, char const *argv[]) {
  N = 5
  ;
  bk()
  ;
  return 0;
}
