#include <iostream>
#include <fstream>
#define FIN "cartezian.in"
#define FOUT "cartezian.out"

using namespace std;

ifstream fin(FIN);
ofstream fout(FOUT);

int M, stack[100], A[100], cnt =0, total;

int accept(int level) {
  return 1;
}

void solve(int level) {
  if(level == M + 1) {
    fout<<"(";
    for(int i = 1; i <= level-1; ++i) {
        fout<<stack[i];
        if(i != level-1) fout<<",";
    }
    fout<<")";
    cnt++;
    if(cnt != total) fout<<",";
  } else {
     stack[level] = 0;
     while(stack[level] < A[level]) {
           stack[level]++;
           solve(level+1);
     }
  }
}

int main(int argc, char const *argv[]) {
   fin>>A[1]>>A[2]>>A[3];
   M = 3;
   total = A[1]*A[2]*A[3];
   fout<<"{";
   solve(1);
   fout<<"}";
  return 0;
}
