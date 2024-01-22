//programare dinamica - Edit_distance
#include <bits/stdc++.h>

using namespace std;

int min3(int a, int b, int c) {
    return min(a, min(b,c));
}

int edit_distance(string word1, string word2) {

    int n, m;
    n = word1.size();
    m = word2.size();

    /*
    auto min3 = [](int a, int b, int c) { return min(a, min(b,c)); }
    */

    //declarat o matrice
    int table[ n + 1 ][ m + 1 ];

    //umplem cu zero
    memset(table, 0, sizeof( table ) );

    //coloana 1, linia 1,2,3,..,n size word1
    for(int i = 1; i <= n; ++i) {
        table[ i ][ 0 ] = i;
    }

    //prima linie, coloana 1,2,..,m size word2
    for(int i = 1; i <= m; ++i) {

        table[ 0 ][ i ] = i;
    }

    for(int i = 1; i <= n; ++i) {

        for(int j = 1; j <= m; ++j) {

          if(word1[ i - 1 ] == word2[ j - 1 ]) {

               table[ i ][ j ] = table[ i - 1 ][ j - 1 ];

          } else {

               table[ i ][ j ] = 1 + min3( table[ i - 1 ][ j - 1 ], table[ i - 1 ][ j ], table[ i ][ j - 1 ] );
          }
        }
    }

   return table[ n ][ m ];
}

int main(int argc, char const *argv[]) {

  string word1,
         word2;

  word1 = "status";

  word2 = "stage";

/*
  0 1 2 3 4 5
  1 0 0 0 0 0
  2 0 0 0 0 0
  3 0 0 0 0 0
  4 0 0 0 0 0
  5 0 0 0 0 0
  6 0 0 0 0 0

  luam litera 's'
  comparam cu: s, t, a, g, e
  luam litera 't'
  comparam cu: s, t, a, g, e
  luam litera 'a':
  cumparam cum: s, t, a, g, e
  */

  int ans = edit_distance(word1, word2);

  cout<<"\nDistance is = "<<ans;

  return 0;
}
