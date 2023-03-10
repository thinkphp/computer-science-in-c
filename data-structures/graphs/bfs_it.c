#include <stdio.h>
#include <memory.h>
#define FIN "graph.in"
#define FOUT "bfs.out"
#define DIM 30

//Breadth First Search
void bfs(int mat[][DIM], int n, int startNode) {

     int explored[DIM],
         Q[DIM],
         first, last,
         node;

     memset(explored, 0, sizeof(explored));

     Q[0] = startNode;

     first = last = 0;

     explored[startNode] = 1;

     while( first <= last ) {

       node = Q[first];

       for(int j = 0; j < n; ++j) {

          //is adjcency and not explored  execute
           if(explored[ j ]==0 && mat[ node ][ j ]==1) {

             Q[ ++last ] = j;

             explored[ j ] = 1;
           }
       }

       first++;
     }

     printf("Breadh First Search:\n");

     for(int j = 0; j < n;++j) {

       printf("%d ", Q[j]+1);

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
  /*
  for(i = 0; i < nodes; ++i) {
    for(j = 0; j < nodes; ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  */
  startNode = 2;

  bfs( matrix, nodes, startNode );

  return 0;
}
