/*n = 5
perm = 4 5 2 3 1
The formula is the following:
kth(perm) = (n-1)!(first-1) + kth(perm-1)
*/
#include <iostream>

using namespace std;

int p[] = {4,5,2,3,1},
    n = sizeof(p) / sizeof(p[0]);

int findKTh() {

  int fact = 1, kth = 0, m = n, k = 0;

  for(int i = 1; i <= n; ++i) fact *= i;

  while(n > 1) {

      fact /= n;

      kth += fact * ( p[ k ] - 1 );

      for(int j = k + 1; j < m; ++j)

          if( p[ j ] > p[ k ] ) p[ j ]--;

      n--;
      k++;
  }

  kth++;

  return kth;
}

int main(int argc, char const *argv[]) {

  int kthP;

  kthP = findKTh();

  cout<<kthP;

  return 0;
}
