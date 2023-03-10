//Depth First Search Traversal
#include <stdio.h>
#include <memory.h>
#define FIN "graph.in"
#define FOUT "bfs.out"
#define DIM 30

void dfs(int mat[][DIM], int nodes, int startNode) {

     int Stack[DIM],
         explored[DIM],
         ptr, //pointer to the stack
         node,
         found, k;

     memset(explored, 0, sizeof(explored));

     explored[startNode] = 1;

     ptr = 0;

     Stack[ptr] = startNode;

     printf("%s\n", "Depth First Search");

     printf("%d ", startNode+1);

     while(ptr>=0){

         node = Stack[ptr];

         found = 0;

         for(k = 0; !found && k < nodes;++k)

             if(mat[node][k] == 1 && !explored[k]) found = 1;

          if(!found) {

              ptr--;

          } else {

              printf("%d ", k);
              explored[k-1] = 1;
              Stack[++ptr] = k-1;
          }

     }

     printf("\n");
}

int main(int argc, char const *argv[]) {

  int matrix[DIM][DIM], nodes, i, j;

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

  startNode = 0;

  dfs( matrix, nodes, startNode );

  return 0;
}
