//Depth First Search Traversal
#include <stdio.h>
#include <memory.h>
#define FIN "graph.in"
#define FOUT "bfs.out"
#define DIM 30

int matrix[DIM][DIM], nodes,
    i, j,
    explored[DIM];

void dfs(int node) {

     printf("%d ", node + 1);

     explored[node] = 1;

     for(int i = 0; i <nodes;++i) {

         if(matrix[node][i] == 1 && explored[i] == 0) {

           dfs(i);
         }
     }
}

int main(int argc, char const *argv[]) {

  freopen(FIN, "r", stdin);
  int startNode;
  //freopen(FOUT, "w", stdout);
  scanf("%d", &nodes);

  for(i = 0; i < nodes; ++i) {
    for(j = 0; j < nodes; ++j) {
      scanf("%d", &matrix[i][j]);
    }
  }

  //Display matrix adjcency

  for(i = 0; i < nodes; ++i) {
    for(j = 0; j < nodes; ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  startNode = 1;

  dfs( startNode );

  return 0;
}
