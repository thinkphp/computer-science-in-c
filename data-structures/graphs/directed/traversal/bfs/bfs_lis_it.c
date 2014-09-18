/*
 * 
 *  @ Breadth First Search 
 *
 *  @ Graph -> List of Adjacency -> iterative -> struct Node
 *
 *  @ author Adrian Statescu <mergesortv@gmail.com> <http://thinkphp>
 *
 *  @ Compiler -> C 
 *
 */
#include <stdio.h>
#include <malloc.h>
#define MAX 1000
#define FIN "bfs.in"
#define FOUT "bfs.out"

struct Node {

       int info;
       struct Node *next;
};

struct Node *List_of_adjacency[ MAX ];

FILE *fin, *fout;

int num_nodes, num_arcs;

int Queue[ MAX ];
int visited[ MAX ];

//function prototype
void readGraph();
void BFS();
void displayListAdjacency();
void displayQueue();

int main() {

    readGraph();
    displayListAdjacency(); 
    BFS();
    displayQueue();
    return(0);
};

void readGraph() {
  
     int i,j;
     struct Node *newnode;   

     fin = fopen(FIN, "r");

     for(i = 1; i <= num_nodes; i++) List_of_adjacency[ i ] = NULL;

     fscanf(fin, "%d %d", &num_nodes, &num_arcs);

       while(num_arcs--) {

         fscanf(fin, "%d %d", &i, &j);
         newnode = (struct Node*)malloc(sizeof(struct Node));
         newnode->info = j;
         newnode->next = List_of_adjacency[ i ];
         List_of_adjacency[ i ] = newnode;       

       }
 
     fclose( fin ); 
};

void BFS() {

     struct Node *c;
 
     int first_index, 

         last_index,

         i, j, node;

     first_index = 1;

      last_index = 1;

      visited [ first_index ] = 1;

      Queue[ first_index ] = 1;

      while(first_index <= last_index) {

           node = Queue[ first_index ];

           c = List_of_adjacency[ node ];

           while( c ) {

                  if( !visited[ c->info ] ) {

                       Queue[ ++last_index ] = c->info;

                       visited[ c->info ] = 1;  
                  }
 
                  c = c->next;
           }                         

           first_index++;  
     }

};

void displayListAdjacency() {

     struct Node *c; 
     int i;

     for(i = 1; i <= num_nodes; i++) {

         printf("%d -> ", i); 

         c = List_of_adjacency[ i ]; 

         while( c ) {

                printf("%d ", c->info);

                c = c->next;
         }

         printf("\n");         
     }
};

void displayQueue() {

     int index_queue;

     for(index_queue = 1;index_queue <= num_nodes; index_queue++) {

         printf("%d ", Queue[ index_queue ]); 
     }
}