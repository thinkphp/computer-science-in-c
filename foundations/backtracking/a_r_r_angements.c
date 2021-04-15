#include <stdio.h>
#define DIM 100
int n, k, level,
    stack[ DIM ];

void init() {
     stack[ level ] = 0 ;
}

int sol() {
    return level == k;
}

int valid() {
    int i;

    for(i = 1; i < level; ++i) {
        if(stack[i] == stack[level]) {
          return 0;
        }
    }
    return 1;
}

int succ() {

    if(stack[ level ] < n) {
      stack[level]++;
      return 1;
    }
    return 0;
}

void display() {

     for(int i = 1; i <= k; ++i) {

         printf("%d ", stack[i]);
     }

     printf("\n");
}

void bk() {
     level = 1;
     init();

     while(level > 0) {

           int hs = 1,
               iv = 0;

               while(hs && !iv) {
                     hs = succ();
                     if(hs){
                        iv = valid();
                     }
               }

               if(hs) {
                  if(sol()) display();
                     else {level++;init();}
               } else {
                level--;
               }

     }
}
int main(int argc, char const *argv[]) {
  //A = {1,2,3,4}
  n = 4;
  k = 2;
  bk();

  return 0;
}
