#include <stdio.h>
#define DIM 10

int maze[DIM][DIM], stack[DIM*DIM][3],
    n, m,
    i, j,
    line, col;

int explored(int level, int r, int c) {

    for(int i = 1; i <= level-1; i++) {
      if(stack[i][0] && stack[i][1] == c)
      return 0;
    }
    return 1;
}

void print_solution(int level) {
  
     for(int i = 1; i <= level - 1; ++i) {
       
       printf("[%d,%d]\n", stack[i][0], stack[i][1]);
     }
}

void solve(int Level,int Row, int Column) {

  if(maze[Row][Column] == 16) {
    print_solution(Level);
  } else {
    stack[Level][0] = Row;
    stack[Level][1] = Column;
  }

  for(int i = 1; i <= 4; ++i) {
    switch (i) {
      case 1:
      if(maze[Row][Column] & 8 && !explored(Level, Row-1, Column) == 0) {
         solve(Level+1, Row - 1, Column);
      }
      break;
      case 2:
      if(maze[Row][Column] & 4 && !explored(Level, Row, Column+1) == 0) {
         solve(Level+1, Row, Column + 1);
      }
      break;
      case 3:
      if(maze[Row][Column] & 2 && !explored(Level, Row+1, Column) == 0) {
         solve(Level+1, Row+1, Column);
      }
      break;
      case 4:
      if(maze[Row][Column] & 1 && !explored(Level, Row, Column - 1) == 0) {
         solve(Level+1, Row, Column - 1);
      }
      break;
    }
  }

}

int main(int argc, char const *argv[]) {

    scanf("n,m = ?");
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; ++i) {
      for(j = 1; j <= m; ++j) {
        printf("maze[%d][%d] = ", i, j);
        scanf("%d", &maze[i][j]);
      }
    }

    //draw the borders with 0
    for(i = 1; i <= m; ++i) {
      maze[0][i] = 16;
      maze[n+1][i] = 16;
    }

    for(i = 1; i <= n; ++i) {
      maze[i][0] = 16;
      maze[i][m+1] = 16;
    }

    //the corners
    maze[0][0] = 16;
    maze[n+1][0] = 16;
    maze[0][m+1] = 16;
    maze[n+1][m+1] = 16;

    //display the maze
    for(i = 0; i <= n+1; ++i) {
      for(j = 0; j <= m+1; ++j) {
        printf("%d ", maze[i][j]);
      }
      printf("\n");
    }

  line = 1;
  col = 1;
  solve(1, line, col);
  return 0;
}
