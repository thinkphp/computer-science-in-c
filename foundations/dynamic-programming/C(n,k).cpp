/*
 * Description: Finding Comb(n,k)
 * Dynamic Programming Technique
 *
 * DP Based on recursive formula.
 * C(n,k) = 1 if k == 0 or n == k
 * C(n,k) = C(n-1,k-1) + C(n-1,k)
 *
 */

#include <bits/stdc++.h>
#define LLI long long int
#define SIZE 101

using namespace std;

LLI C[SIZE][SIZE], i, j, n, k;

int main(int argc, char const *argv[]) {

  n = 6;
  k = 4;

  C[ 0 ][ 0 ] = 1;

  for(i = 1; i <= n; ++i) {

      for(j = 0; j <= i; ++j) {

        if(0 == j || i == j) C[i][j] = 1;

        C[i][j] = C[i-1][j-1] + C[i-1][j];

      }
  }

  for(i = 0; i <= n; ++i) {

      for(j = 0; j <= i; ++j) {

        cout<<C[i][j]<<" ";
      }
      cout<<endl;
  }

  cout<<C[n][k];

  return 0;
}
