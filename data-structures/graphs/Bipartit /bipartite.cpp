#include <iostream>
#define FIN "bipartit.in"
#define SIZE 100

using namespace std;

int mat[SIZE][SIZE],used[SIZE],
    n,
    bipartit = 1,
    marc[SIZE];

void dfs(int node, int v) {

     int k;
     marc[node] = v;
     used[node] = 1;
     v *= -1;

     for(k = 1; k <= n; ++k) {
       if(mat[node][k] == 1) {
           if(used[k] == 0) dfs(k, v);
           else
             if(marc[k]!=v) bipartit = 0;
       }
     }
}

void read_graph() {
  int i,j;
  freopen(FIN, "r", stdin);
  cin>>n;
  while(cin>>i>>j) {
    mat[i][j] = mat[j][i] = 1;
  }
}

void display_graph() {
  int i, j;
  for(i = 1; i <= n; ++i) {
     for(j = 1; j <= n; ++j) {
       cout<<mat[i][j]<<" ";
     }
     cout<<endl;
  }
}

int main(int argc, char const *argv[]) {
  read_graph();
  display_graph();

  dfs(1,1);

  if(bipartit) {

    cout<<"Set A = " ;

    for(int i = 1; i <= n; ++i)

        if(marc[i] == 1) cout<<i<<" ";

        cout<<endl;

    cout<<"Set B = " ;

    for(int i = 1; i <= n; ++i)

        if(marc[i] == -1) cout<<i<<" ";
  }


  return 0;
}
