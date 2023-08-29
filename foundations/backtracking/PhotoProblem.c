#include <stdio.h>
#define fin "colorphoto.in"

int matrix[ 100 ][ 100 ],
      n, m;

void chooseColor( int i, int j, int color ) {

     if(1 == matrix[ i ][ j ] && i < n && j < m && i >= 0 && j >= 0) {
          matrix[ i ][ j ] = color;
          chooseColor(i, j + 1, color);
          chooseColor(i, j - 1, color);
          chooseColor(i + 1, j, color);
          chooseColor(i - 1, j, color);

     }
}

int main(int argc, char const *argv[]) {

  int i,j;

  freopen(fin, "r", stdin);

  scanf("%d %d", &n, &m);

  printf("%d %d\n", n, m);

  for(i = 0; i < n; i++) {

      for(j = 0; j < m; j++) {

          scanf("%d", &matrix[i][j]);
       }
  }

  for(i = 0; i < n; i++) {
      for(j = 0; j < m; j++) {
        printf("%d ", matrix[i][j]);
       }
       printf("\n");
  }
  int color = 2;

  for(i = 0; i < n; i++) {

      for(j = 0; j < m; j++)

          if(1 == matrix[i][j]) {

             chooseColor(i, j, ++color);
          }
  }

  printf("\n");

  for(i = 0; i < n; i++) {
      for(j = 0; j < m; j++) {
        printf("%d ", matrix[i][j]);
       }
       printf("\n");
  }
  return 0;
}
