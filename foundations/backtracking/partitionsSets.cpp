#include <iostream>
#include <fstream>
#define filein "partitiimultime.in"
#define fileout "partitiimultime.out"

using namespace std;

int n, stack[100];
ifstream fin(filein);
ofstream fout(fileout);

int maxim(int level) {
  int max;
  max = 0;
  for(int i = 1; i < level; ++i) {
    if(stack[i] > max) max = stack[i];
  }
  return max;
}

void display_partition() {
     int max = maxim(n+1);
     for (size_t i = 1; i <= max; i++) {
          for(int j = 1; j <= n; ++j) {
            if(stack[j] == i) fout<<j<<"";
          }
          fout<<"*";
     }
     fout<<endl;
}

void solve(int level) {
    for(int i = 1; i <= maxim(level)+1; ++i) {
        stack[level] = i;
        if(level == n) {
          display_partition();
        } else solve(level+1);
    }
}

int main(int argc, char const *argv[]) {
  fin>>n;
  stack[1] = 1;
  solve(2);
  return 0;
}
