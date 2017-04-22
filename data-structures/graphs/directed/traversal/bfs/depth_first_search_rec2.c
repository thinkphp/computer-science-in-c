#include <stdio.h>
#include <malloc.h>
#define SIZE 1000
#define FIN "graph_adjacency.in"

 int nodes, edges, visited[ SIZE ], a, b;
 struct Node {
        int info;
        struct Node *next; 
 } *L[SIZE];


 void dfs(int node) {

      struct Node *c;

      visited[ node ] = 1;

      printf("%d ", node);

      for(c = L[node]; c != NULL; c = c->next) {

              if(!visited[c->info]) {

                  dfs(c->info);
              }                            
      }

 }

int main() {

 struct Node *node;

 freopen(FIN, "r", stdin);
  
 scanf("%d %d", &nodes, &edges);

 while(edges--) {

       scanf("%d %d", &a, &b);       
       node = (struct Node*)malloc(sizeof( struct Node ));
       node->info = b;
       node->next = L[a];
       L[a] = node;   
 }


 dfs(1);

 return(0);
}