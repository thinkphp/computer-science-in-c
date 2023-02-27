#include <stdio.h>
#define fin "salesman.in"
#define fout "salesman.out"
#define SIZE 100

int stack[100], level, nodes, startNode;
int matrix[SIZE][SIZE], edges;

void init(level) {
     stack[level] = 0;
}

int succ(level) {

    if(stack[level] < nodes) {
      stack[level]++;
      return 1;
    }else
    return 0;
}

int valid(level) {

    if(!matrix[stack[level-1]][stack[level]]) return 0;

    for( int i = 1; i < level; ++i ) {

        if(stack[i] == stack[level]) return 0;
    }

    return 1;
}

void print() {

     for(int i = 1; i <= nodes; ++i) printf("%d ", stack[i]);

     printf("\n");
}

int sol(level) {

  return level == nodes && matrix[startNode][stack[level]] == 1;
}

void back(level) {

     init(level);

     while(succ(level)==1) {

       if(valid(level)==1)

         if(sol(level)) {

           print();

         } else back(level+1);

     }
}

void readGraph() {

     int x, y;
     freopen(fin,"r", stdin);
     scanf("%d %d", &nodes, &edges);

     while(edges--) {
       scanf("%d %d", &x, &y);
       matrix[x][y] = 1;
       matrix[y][x] = 1;
     }
}

void displayGraph() {
     for(int i = 1; i <= nodes; ++i) {
       for(int j = 1; j <= nodes; ++j) {
         printf("%d ", matrix[i][j]);
       }
       printf("\n");
     }
}

int main(int argc, char const *argv[]) {

  readGraph();
  startNode = 1;
  stack[ 1 ] = startNode;
  back(2);
  return 0;
}
