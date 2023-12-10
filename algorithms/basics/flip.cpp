#include <iostream>
#define FIN "flip.in"
#define FOUT "flip.out"
#define SZ 17

using namespace std;

int stack[SZ],level,sum_max=0,
    n, m, matrix[SZ][SZ],
         _matrix[SZ][SZ];

void readdata(){
  freopen(FIN, "r", stdin);
  cin>>n>>m;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
        cin>>matrix[i][j];
    }
  }
  fclose(stdin);
}

void writedata() {
  freopen(FOUT, "w", stdout);
  cout<<sum_max;
  fclose(stdout);
}

void init() {
  stack[level] = -1;
}

int succ() {
  if(stack[level] < 1) {
    stack[level]++;
    return 1;
  }
  return 0;
}

int valid() {
  return 1;
}

void print() {
  for(int i = 1; i <= n; ++i) {
      cout<<stack[i]<<" ";
  }
  cout<<endl;
}

int sol(){return level == n;}

void solve_flip() {
  int s, stotal = 0;
  // make a copy of the original matrix
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      _matrix[i][j] = matrix[i][j];
    }
  }

  //make flip on line
  for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j)
      if(stack[i] == 1){
         _matrix[i][j] *= -1;
      }
  }

  for(int j = 1; j <= m; ++j) {
      s = 0;
      for(int i = 1; i <= n; ++i) {
        s += _matrix[i][j];
      }
      if(s<0) s*=-1;
      stotal += s;
  }
  if(sum_max<stotal)sum_max=stotal;
}

void bk() {
int s,v;
level = 1;
init();
while(level>0){
    s = 1;
    v = 0;
    while(s && !v){
      s = succ();
      if(s) {
        v = valid();
      }
    }

    if(s){
      if(sol()){
        solve_flip();
      } else {
        level++;
        init();
      }
    } else level--;
}

}

int main(int argc, char const *argv[]) {
  readdata();
  bk();
  writedata();
  return 0;
}
