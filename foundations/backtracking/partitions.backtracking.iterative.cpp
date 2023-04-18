#include <iostream>

using namespace std;

int n,
    sum,
    stack[ 10 ],
    level;

void solve(int level) {

     if(sum == n) {

       for(int i = 1; i < level; ++i) {

         cout<<stack[i]<<" ";

       }

       cout<<endl;

     } else {

        stack[level] = 0;

        while(stack[level] + sum < n) {

              stack[level]+=1;

              sum += stack[level];

              solve(level+1);

              sum -= stack[level];
        }
     }
}

void init() {
    if(level==1)
     stack[level] = 0;
    else stack[level] = stack[level-1] - 1;
}

int succ() {

    if(stack[level] + sum < n) {
       stack[level]++;
       return 1;
    }  else {
       sum -= stack[level-1];
       return 0;
    }
}

int valid() {

    if( stack[level] + sum <= n ) {

        sum += stack[ level ];

       return 1;
    }

    return 0;
}

int sol() {

  return sum == n;
}

void print() {

    for(int i = 1; i <= level; ++i) {

      cout<<stack[i]<<" ";
    }

    cout<<endl;

    sum -= stack[level];
}

void bk() {

  level = 1;

  init();

  while( level > 0 ) {

      int h,v;

      h = 1;
      v = 0;
      while(h && !v) {
        h = succ();
        if(h) {
          v = valid();
        }
      }

      if(h) {
        if(sol()) {
          print();
        } else {
          level++;
          init();
        }
      } else {
        level--;
      }
  }
}

int main(int argc, char const *argv[]) {

  sum = 0;
  n = 4;
  //solve(1);
  bk();
  return 0;

}
