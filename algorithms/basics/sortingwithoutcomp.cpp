#include <iostream>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
 
  int matrix[ 100 ][ 100 ],
 
      vec[] = { 23, 11, 16, 901, 29, 18, 26, 411, 104, 73, 192 },
 
      n, digits = 3,
 
        ten = 1;
 
  n = sizeof( vec ) / sizeof( vec[ 0 ] );
 
  for(int digit = 1; digit <= digits; digit++) {
 
      if(digit > 1) ten *= 10;
 
      for(int i = 0; i < n; ++i) {
 
          int dig = ( vec[i] / ten ) % 10;
 
          matrix[ 0 ][ dig ]++;
 
          matrix[ matrix[0][dig] ][ dig ] = vec[i];
      }
 
      int k = 0;
 
      for(int i = 0; i <= 9; i++) {
 
          if(matrix[0][i]) {
             for(int j = 1; j <= matrix[0][i]; j++) {
               vec[k] = matrix[ j ][ i ];
               k++;
             }
          }
      }
 
      for(int i = 0; i <= 9; i++) matrix[0][i] = 0;
  }
 
 
  for(int i = 0; i < n; ++i) cout<<vec[i]<<" ";
  return 0;
}
