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

     int queue[SIZE],
 
         visited[SIZE],

         front,

         rear;    

void breadth_first_search_in_action() {

     int theNode;

     struct Node *c;   

     if(front <= rear) {
           
           theNode = queue[front];

           c = L[theNode];

           while(c) {

                     if(!visited[c->info]) {     
                     
                         queue[++rear] = c->info;

                         visited[c->info] = 1;
                      }

                      c = c->next; 
           }

           front++; 

           breadth_first_search_in_action();
     } 
}



int main() {

       struct Node *node;

       freopen(FIN, "r", stdin);
  
       scanf("%d %d", &nodes, &edges);

       for(int i = 1; i <= nodes; i++) L[ i ] = NULL;

 while(edges--) {

       scanf("%d %d", &a, &b);       

       node = (struct Node*)malloc(sizeof( struct Node ));

       node->info = b;

       node->next = L[a];

       L[a] = node;   
 }

     front = rear = 0; 

     queue[ front ] = 1;
 
     memset(visited, 0, sizeof(visited));

     visited[ 1 ] = 1;

     breadth_first_search_in_action();

     for(int j = 0; j < nodes; j++) printf("%d ",queue[j]);

 return(0);
}