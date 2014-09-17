/*
 * 
 *  @ Depth First Search 
 *
 *  @ Graph -> Using List of Adjacency -> Iterative version
 *
 *  @ author Adrian Statescu <mergesortv@gmail.com> <http://thinkphp>
 *
 *  @ Compiler -> GNU C gcc dfs_lis_it.c -o d.exe
 *
 */
#include <stdio.h>
#include <malloc.h>
#define MAX 1000
#define FIN "dfs.in"
#define FOUT "dfs.out"

struct Node {
       int info;
       struct Node *next;
}; 

FILE *fin, *fout;

int num_nodes, 
    num_arcs;

struct Node *List_of_adjacency[ MAX ];
int    visited[ MAX ], 
       sol[ MAX ], 
       stack[ MAX ], start_node;

//function prototype
void readGraph();
void DFS();
void displayListAdjacency();
void displaySol();

int main() {

    int j;

    readGraph();

    displayListAdjacency(); 

    DFS();

    displaySol();
   
    return(0);
};

void readGraph() {
  
     struct Node *newnode;

     int i,
         j;

     fin = fopen(FIN, "r");

     fscanf(fin, "%d %d", &num_nodes, &num_arcs);

     for(i = 1; i <= num_nodes; i++) List_of_adjacency[ i ] = NULL;

     for(; num_arcs; num_arcs--) {

           fscanf(fin, "%d %d", &i, &j);
 
           newnode = (struct Node*)malloc(sizeof(struct Node));
           newnode->info = j;
           newnode->next = List_of_adjacency[i];
           List_of_adjacency[i] = newnode;
     }

     fclose( fin ); 
};

void DFS() {

     struct Node *c,
                 *p;
 
     //declared the following variables
     int _index, 
         node, 
         found;

     _index = 0;//first index from Stack

     start_node = 1; //start node

     stack[ _index ] = start_node;//push first node onto stack

     visited[ start_node ] = 1; //marked the start node as selected

     sol[++sol[0]] = start_node;

     while(_index >= 0) {

           //get the front from stack
           node = stack[ _index ];

           found = 0;
        
           c = List_of_adjacency[ node ];
           
           while( c!=NULL && !found) {
                 
                 if( !visited[ c->info ] ) {

                     //we hold the precedent in a pointer P 
                     p = c;

                     found = 1;
                 }

                 c = c->next; 
           }
          

           if(!found)

           _index--;

          else {

               sol[++sol[0]] = p->info;

               visited[p->info] = 1;

               stack[++_index] = p->info;
          }
     };     
};

void displayListAdjacency() {

     struct Node *c;

     int i;

     for(i = 1; i <= num_nodes; i++) {

         printf("%d => ", i);

         c = List_of_adjacency[ i ];

         while( c ) {   
  
                printf("%d ", c->info);

                c = c->next;
         }

         printf("\n");
     }
}

void displaySol() {
    int i;

    fout = fopen(FOUT, "w");

    printf("Depth First Search -> "); 

    fprintf(fout, "Depth First Search -> "); 

    for(i = 1; i <= sol[ 0 ]; i++) printf("%d ", sol[i]), fprintf(fout, "%d ", sol[i]);

    fclose( fout );
}
