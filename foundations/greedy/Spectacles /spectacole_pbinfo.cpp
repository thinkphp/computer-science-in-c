#include <iostream>

using namespace std;

int matrix[2][101], ord[101], n, count = 1;

void sort() {
     int finished = 0, size = n, swapped;
     while(!finished) {
       swapped = 0;
       for(int i = 1; i < size; ++i) {
         if(matrix[1][ord[i]] > matrix[1][ord[i+1]]) {
            int temp = ord[i];
            ord[i] = ord[i+1];
            ord[i+1] = temp;
            swapped = 1;
         }
       }
       if(swapped) size--;
       else finished = 1;
     }
}

int main(int argc, char const *argv[]) {

  int start,
      end;

  freopen("spectacole.in", "r", stdin);

  freopen("spectacole.out", "w", stdout);

  cin>>n;

  for(int i = 1; i <= n; ++i) {
      ord[i] = i;
      cin>>start>>end;
      matrix[ 0 ][ i ] = start;
      matrix[ 1 ][ i ] = end;
  }

  sort();

  int curr = matrix[1][ord[1]];

  for(int i = 2; i <= n; ++i) {

      if(matrix[0][ord[i]] >= curr) {

        curr = matrix[ 1 ][ ord[ i ] ];

        count++;
      }
  }

  cout<<count;

  return 0;
}
