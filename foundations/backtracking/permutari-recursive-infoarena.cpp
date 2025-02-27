#include <fstream>

using namespace std;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

int n, st[10];
bool used[10];

void backtracking(int pos) {


      if(pos == n + 1) {

        for(int i = 1; i <= n; ++i)

            fout<<st[i]<<" ";

        fout<<endl;

      } else {

         for(int val = 1; val <= n; ++val) {

             if( !used[val] ) {
                 st[ pos ] = val;
                 used[ val ] = true;
                 backtracking( pos + 1 );
                 used[ val ] = false;
             }
         }
      }
}


int main(int argc, char const *argv[]) {

  fin>>n;
  backtracking(1);

  return 0;
}
