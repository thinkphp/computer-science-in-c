#include <iostream>

using namespace std;

int n, sum, stack[10];

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
int main(int argc, char const *argv[]) {

  sum = 0;
  n = 5;
  solve(1);
  return 0;
}
