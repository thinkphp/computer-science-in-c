#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#define SIZE 1000
#define FIN "graph_adjacency.in"

 int nodes, edges, visited[ SIZE ], a, b;
 struct Node {
        int info;
        struct Node *next; 
 } *L[SIZE];

void breadth_first_search_in_action(int node) {

     int queue[SIZE],
 
         visited[SIZE],

         front,

         rear;

     front = rear = 0; 

     queue[ front ] = node; //push start node into the queue
 
     memset(visited,0,sizeof(visited)); 

     //marked as visited
     visited[ node ] = 1; 

     int i,j;

     while(front <= rear) {

           int theNode = queue[front++];

           for(struct Node *c = L[theNode]; c!=NULL; c = c->next)

                     if(!visited[c->info]) {     
                     
                         rear++;
 
                         queue[rear] = c->info;

                         visited[c->info] = 1;
                     }
     } 

     for(j = 0; j < nodes; j++) printf("%d ",queue[j]);       

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


 breadth_first_search_in_action(1);

 return(0);
}