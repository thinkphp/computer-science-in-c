#include <iostream>
int stack[100], level, n;

void init() {
  stack[level] = -1;
}

void print() {

  for(int i = 1; i <= n; ++i) {

    if(stack[i] == 1) {

      printf("%d ", i);
    }
  }
  printf("\n");
}

int succ() {
  if(stack[level]<1){
    stack[level]++;
    return 1;
  }
  return 0;
}

int valid() {
  return 1;
}

int sol() {
  return level == n;
}

void bk() {
int s,v;
level = 1;
init();

 while(level>0) {
      s = 1;
      v = 0;
      while(s && !v) {
         s = succ();
         if(s) v = valid();
      }
      if(s){
        if( sol() ) print();
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

  n = 3;
  bk();

  return 0;
}
