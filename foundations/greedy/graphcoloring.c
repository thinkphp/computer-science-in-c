#include <stdio.h>
#define fin "graphcoloring.in"
#define SIZE 50

int main(int argc, char const *argv[]) {

  int i, j, n, ok;
  int matrix[SIZE][SIZE];
  freopen(fin, "r", stdin);

  //read the number of the countries
  scanf("%d", &n);
  int arr_colors[n+1],
      color;

  //read the relation between countries
  for(i = 0; i < n; ++i) {

    for(j = 0; j < n; ++j) {

      scanf("%d", &matrix[i][j]);

    }
  }

   //display the relation between countries
  for(i = 0; i < n; ++i) {

    for(j = 0; j < n; ++j) {

      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  arr_colors[ 0 ] = 0;

  for( i = 1; i < n; ++i ) {

      color = -1;

        do {
         ok = 1;
         color++;
         for(j = 0; j < i; ++j)
             if(matrix[j][i] == 1 && arr_colors[j] == color)
                ok = 0;
        }

        while(!ok);

        arr_colors[i] = color;
  }

  printf("colors:\n");

  for(i = 0; i < n; ++i) printf("%d ", arr_colors[i]+1);

  printf("\n");

  return 0;
}
