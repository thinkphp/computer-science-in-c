#include <stdio.h>
#include <malloc.h>
#define FIN "topsort.in"
#define DIM 100

typedef struct Node {
     int info;
     struct Node *next;
} Node;

Node *ListAdj[ DIM ];
Node *solutions;
int explored[DIM];
int nodes, edges;

void readListAdjcency() {

     int x, y;
     Node *c;

     freopen(FIN, "r", stdin);

     scanf("%d %d", &nodes, &edges);

     while(edges--){
       scanf("%d %d", &x, &y);
       Node *c = (Node*)malloc(sizeof(Node));
       c->info = y;
       c->next = ListAdj[x];
       ListAdj[x] = c;
     }
}

void dfs(int node) {

     explored[node] = 1;

     Node *c = ListAdj[node];

     while(c!=NULL) {

       if(!explored[c->info]) {

         dfs(c->info);

       }

       c = c->next;
     }

     Node*c2 = (Node*)malloc(sizeof(Node));
     c2->info = node;
     c2->next = solutions;
     solutions = c2;
}

void topsort() {

     for(int i = 1; i <= nodes; ++i) {
       if(!explored[i]) {
         dfs(i);
       }
     }

     Node *c = solutions;
     while(c) {
       printf("%d ", c->info);
       c = c->next;
     }
}

int main(int argc, char const *argv[]) {

  readListAdjcency();
  topsort();
  return 0;
}
