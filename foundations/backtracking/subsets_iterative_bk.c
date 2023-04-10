#include <stdio.h>
#define FIN "submultimi.in"
#define FOUT "submultimi.out"

int stack[100], n, level;

void init2(int level) {
     stack[level] = -1;
};

void init() {
     stack[level] = -1;
};

int succ2(int level) {
     if(stack[level] < 1) {
       stack[level] += 1;
       return 1;
     }
     return 0;
};


int succ() {
     if(stack[level] < 1) {
       stack[level] += 1;
       return 1;
     }
     return 0;
};

int sol2(int level) {
  return level == n;
}

int sol() {
  return level == n;
}

int valid() {
     return 1;
};

void print() {
     int flag = 0;
     for(int i = 1; i <= n; ++i) {
       if(stack[i] == 1) {
         printf("%d ", i);
         flag = 1;
       }
     }
     if(flag == 1) printf("\n");
}

void solve2(int level) {
     init2(level);
     while(succ2(level)) {
       if(valid()){
         if(sol2(level)) {
           print();
         } else {
           solve2(level+1);
         }
       }
     }
}

void solve() {
     int s, v;
     level = 1;
     init();
     while(level>0) {
          s = 1;
          v = 0;
          while(s && !v) {
            s = succ();
            if(s) v = valid();
          }
          if(s) {
            if(sol()) {
              print();
            }
            else {
              level++;
              init();
            }
          } else level--;
     }
}

int main(int argc, char const *argv[]) {

  freopen(FIN,"r",stdin);
  freopen(FOUT,"w",stdout);
  scanf("%d", &n);
  //solve();
  solve2(1);
  return 0;
}
