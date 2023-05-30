#include <bits/stdc++.h>
#define FIN "bila.in"
#define FOUT "bila.out"

using namespace std;

ofstream fout(FOUT);
ifstream fin(FIN);

int a[50][50],
    b[50][50],
    n, m,
    istart,
    jstart,
    maximum;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int isInside(int i, int j) {

  return i == 1 || i == n || j == 1 || j == m;
}

void ball(int i, int j, int level) {

      if(isInside(i,j)) {
         maximum = max(maximum, level-1);
         return;
      } else {
        for(int d = 0; d < 4; ++d) {
          int new_i = i + dx[d];
          int new_j = j + dy[d];
          if(!a[new_i][new_j] && b[new_i][new_j] < b[i][j]) {
            a[new_i][new_j] = level;
            ball(new_i, new_j, level+1);
            a[new_i][new_j] = 0;
          }
        }
      }
}

int main(int argc, char const *argv[]) {

  fin>>n>>m;

  for(int i = 1; i <= n; ++i) {

    for(int j = 1; j <= m; ++j) {

        fin>>b[i][j];
    }
  }
  fin>>istart>>jstart;

  for(int i = 0; i <= n + 1; ++i) {
      a[i][0] = a[i][m+1] = -1;
  }

  for(int i = 0; i <= m + 1; ++i) {
      a[0][i] = a[n+1][i] = -1;
  }

  for(int i = 0; i <= n+1; ++i) {
        for(int j = 0; j <= m+1; ++j)
          cout<<a[i][j]<<" ";
      cout<<endl;
  }

  a[istart][jstart] = 1;
  
  ball(istart, jstart, 2);

  cout<<maximum;

  return 0;
}
