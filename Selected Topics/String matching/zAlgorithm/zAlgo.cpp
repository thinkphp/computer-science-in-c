#include <bits/stdc++.h>
#define FIN "strmatch.in"
#define FOUT "strmatch.out"
#define SIZE 2000005
#define LL long long int

using namespace std;

ifstream fin(FIN);
ofstream fout(FOUT);

int n, m, k;
char a[2*SIZE], b[2*SIZE];
int lps[2*SIZE];
vector<int> ans;
LL counter;
int i,j;

int main(int argc, char const *argv[]) {

  fin>>a>>b;

  n = strlen( a );

  m = strlen( b );

  a[n] = '$';

  strcat( a, b );

  k = 0;

  for(i = 1; a[i]; i++) {

    while(k>0 && a[i]!=a[k]) k = lps[k-1];
    if(a[i]==a[k])k++;
    lps[i] = k;
  }

  for(i = 2 * n; a[i]; ++i) {

    if(lps[i] == n) {
      counter++;

      if(counter <= 1000) {

        ans.push_back( i - 2 * n );

      }
    }
  }

  fout<<counter<<endl;

  for(auto el:ans) {

    fout<<el<<" ";
  }

  return 0;
}
