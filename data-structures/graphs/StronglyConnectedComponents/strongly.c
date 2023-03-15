#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define fin "strongly.in"
#define STACK_MAX 100
#define DIM 100
 
typedef struct Node {
        int info;
        struct Node *next;
} Node;
 
int nodes,
    edges,
    comp;
Node *L[DIM],
     *L_Reverse[DIM],
     *Result[DIM];
 
int explored[DIM];
 
#include <stdio.h>
#define STACK_MAX 100
#define FIN "scarface.in"
 
struct Stack {
 
	int size;
	char data[ STACK_MAX ];
};
 
typedef struct Stack Stack;
 
void Stack_Init(Stack *S) {
 
     S->size = 0;
}
 
int Stack_Empty(Stack *S) {
 
     return S->size == 0;
}
 
void Stack_Push(Stack *S, int val) {
 
     if( S->size < STACK_MAX ) {
 
         S->data[S->size++] = val;
 
     } else fprintf(stderr, "Err: Stack Full!\n");
 
}
 
void Stack_Pop(Stack *S) {
 
     if( S->size == 0 ) fprintf(stderr, "Error: Stack Empty!");
 
         else S->size--;
}
 
int Stack_Top(Stack *S) {
 
	if(S->size == 0) {
 
       fprintf(stderr, "Error: Stack Empty!");
       return -1;
	}
 
    return S->data[ S->size - 1];
}
 
Stack S;
 
void readGraph() {
     int x, y;
     //freopen(fin, "r", stdin);
     scanf("%d %d", &nodes, &edges);
     while(edges--) {
       scanf("%d %d", &x, &y);
       Node*c = (Node*)malloc(sizeof(Node));
       c->info = y;
       c->next = L[x];
       L[x] = c;
       Node*c2 = (Node*)malloc(sizeof(Node));
       c2->info = x;
       c2->next = L_Reverse[y];
       L_Reverse[y] = c2;
     }
}
 
void dfs(int node) {
 
     explored[node] = 1;
 
     Stack_Push(&S, node);
 
     Node *c = L[node];
 
     while(c) {
 
       if(!explored[c->info]) {
 
          dfs(c->info);
       }
 
       c = c->next;
     }
}
 
void dfs_r(int node) {
 
     explored[ node ] = 1;
 
     Node*head = (Node*)malloc(sizeof(Node));
     head->info = node;
     head->next = Result[comp];
     Result[comp] = head;
 
     Node *c = L_Reverse[node];
 
     while(c) {
 
       if(!explored[c->info]) {
 
          dfs_r(c->info);
       }
 
       c = c->next;
     }
}
 
void kosaraju() {
 
  Stack_Init(&S);
 
  for(int node = 1; node <= nodes; ++node) {
 
      if(!explored[node]) {
 
        dfs(node);
      }
  }
 
   memset(explored, 0, sizeof(explored));
 
   int vertex;
 
   comp = 0;
 
   while(!Stack_Empty(&S)) {
 
         vertex = Stack_Top(&S);
 
         Stack_Pop(&S);
 
         if(!explored[vertex]) {
 
            comp++;
 
            dfs_r(vertex);
         }
   }
 
   for(int i = 1; i <= comp; ++i) {
 
       printf("Component %d:", i);
 
       Node *k = Result[i];
 
       while( k ) {
 
         printf("%d ", k->info);
 
         k = k -> next;
       }
 
       printf("\n");
 
   }
}
 
int main(int argc, char const *argv[]) {
 
  readGraph();
 
  kosaraju();
 
  return 0;
}
 
