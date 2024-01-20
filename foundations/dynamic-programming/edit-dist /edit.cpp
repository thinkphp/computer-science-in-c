#include <bits/stdc++.h>

using namespace std;

int edit_distance(string word1, string word2) {

    int n = word1.size(),
        m = word2.size();
        auto min3 = [](int a, int b, int c) {
             return min(a, min(b,c));
        };

    int table[n+1][m+1];
    memset(table, 0, sizeof(table));

    for(int i = 1; i <= n; ++i) {
        table[i][0] = i;
    }
    for(int i = 1; i <= m; ++i) {
        table[0][i] = i;
    }
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <=m; ++j) {
        if(word1[i-1] == word2[j-1]) {
          table[i][j] = table[i-1][j-1];
        } else{
          table[i][j] = 1 + min3(table[i-1][j-1], table[i-1][j],table[i][j-1]);
        }
      }
    }
    return table[n][m];
}

int main(int argc, char const *argv[]) {
  string word1, word2;
  word1 = "dana";
  word2 = "ioana";
  int ans = edit_distance(word1, word2);
  cout<<ans;
  return 0;
}
