#include <bits/stdc++.h>
#define DIM 1024
#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"

using namespace std;

ifstream fin(FIN);
ofstream fout(FOUT);


void lcs(int *str1, int *str2, int n, int m) {
    
    int table[n+1][m+1];

    for(int i = 0; i <= n; ++i) {

        for(int j = 0; j <= m; ++j) {

            if(i == 0 || j == 0) table[i][j] = 0;

            else if(str1[i-1] == str2[j-1]) {

                 table[i][j] = 1 + table[i-1][j-1];

            } else {
                
                 table[i][j] = max(table[i][j-1], table[i-1][j]);
            }
        }
    }

    fout<<table[n][m]<<endl;

    int i = n, j = m, index = table[n][m];    

    int lcs[index+1];    

    while(i > 0 && j > 0) {

          if(str1[i-1] == str2[j-1]) {

              lcs[index-1] = str1[i-1];

              i--;j--;index--;

          } else if(table[i-1][j] > table[i][j-1]) {

              i--;
          } else {
              j--;
          }
    }
    for(int i = 0; i < table[n][m]; ++i) fout<<lcs[i]<<" ";    

}

int main() {
    int n,m;
    fin>>n>>m;    
    int arr1[DIM], arr2[DIM];
    for(int i = 0; i < n; ++i) fin>>arr1[i];
    for(int i = 0; i < m; ++i) fin>>arr2[i];
    lcs(arr1,arr2,n,m);
}
