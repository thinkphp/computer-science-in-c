#include <bits/stdc++.h>
using namespace std;
const int MOD = 1999999973;

ifstream fin("lgput.in");
ofstream fout("lgput.out");

int lgput(int n, int a){
  if(a == 0){
    return 1;
  }else{
    if(a%2 == 0){
      int val = lgput(n, a/2);
      return (1ll*val*val)%MOD;
    }else{
      return (1ll*n*lgput(n, a-1))%MOD;
    }
  }
}

int main() {
  int n,p;
  fin >> n >> p;
  fout << lgput(n, p);
  return 0;
}
