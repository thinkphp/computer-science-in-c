#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 1000

clock_t start, end;

int matrix[DIM][3],
    explored[DIM][DIM];

int x[8] = {-1, 1, 2, 2, 1, -1, -2,-2},
    y[8] = { 2, 2, 1,-1,-2, -2, -1, 1};

int n; //n x n the table of the chess

void solve(int level, int line, int col) {

     int l, c, i;

     if(level == n * n) {

       //the code goes here
       for(int i = 1; i <= level-1; ++i) {

           printf("%d %d\n", matrix[i][0], matrix[i][1]);
       }
       printf("line=%d col=%d\n", line, col);

       end = clock();
       double time_spent = (double)(end-start)/CLOCKS_PER_SEC;

       printf("Time spent running = %lf", time_spent);
      exit(0);

     } else {
       matrix[level][0] = line;
       matrix[level][1] = col;
       explored[line][col] = 1;
       for(i = 0; i < 8; ++i) {
          l = line + x[i];
          c = col + y[i];
          if(l >= 1 && l <= n && c >= 1 && c <= n && explored[l][c] == 0) {
            explored[l][c] = 1;
            solve(level+1, l, c);
            explored[l][c] = 0;
          }
       }
     }
}

int main(int argc, char const *argv[]) {

  n = 5;

  solve(1,1,1);

  return 0;
}
