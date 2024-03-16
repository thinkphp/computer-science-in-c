#include <iostream>
#define FIN "mouse.in"
#define FOUT "mouse.out"

using namespace std;

int n,m,k,x,y,z,t,
mat[11][11],//the matrix holds the table
sol[2][100];//simutate the stack on which we hold the roads.

const int dx[] = {-1,0,1,0};//to identify the index x
const int dy[] = {0,1,0,-1};//to identify the index y

void read() {
     freopen(FIN, "r", stdin);
     cin>>n>>m>>x>>y>>z>>t;
     for(int i = 1; i <= n; ++i)
         for(int j = 1; j <= m; ++j)
             cin>>mat[i][j];
}

void display() {
  int i,j;
  cout<<n<<" "<<m<<endl<<x<<" "<<y<<endl<<z<<" "<<t<<endl;
  for(i = 0; i <= n+1; ++i) {
      for(j = 0; j <= m+1; ++j) {
          cout<<mat[i][j]<<" ";
      }
      cout<<"\n";
  }
}

void border() {
     int c;
     for(c = 0; c <= n + 1; c++) mat[c][0] = mat[c][m+1] = 1;
     for(c = 0; c <= m + 1; c++) mat[0][c] = mat[n+1][c] = 1;
}

void bkt(int x, int y) {

     int i;
     if(x == z && y == t) {
       for(int s = 1; s<=k; ++s) cout<<"("<<sol[0][s]<<","<<sol[1][s]<<")";
       cout<<"("<<z<<","<<t<<")";
       cout<<endl;
       return;
     }

     if(mat[x][y] == 0) {
         mat[x][y] = 2;
         k++;
         sol[0][k] = x;
         sol[1][k] = y;
         for(i = 0; i < 4; ++i)
             bkt(x + dx[i], y + dy[i]);
             mat[x][y] = 0;
             k--;
      }
}

int main(int argc, char const *argv[]) {

  read();
  border();
  //display();
  bkt(x,y);
  return 0;
}
