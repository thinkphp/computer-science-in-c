/*
 * 
 *  @ Depth First Search 
 *
 *  @ Graph -> Using List of Adjacency -> Recursion Version
 *
 *  @ author Adrian Statescu <mergesortv@gmail.com> <http://thinkphp>
 *
 *  @ Compiler -> GNU C gcc dfs_lis_rec.c -o d.exe
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
void DFS(int);
void displayListAdjacency();
void displaySol();

int main() {

    int j;

    readGraph();

    displayListAdjacency(); 

    DFS(1);

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

void DFS(int node) {

     struct Node *c;

     int i;

     visited[ node ] = 1;

     c = List_of_adjacency[ node ];

     while( c ) {

            if( !visited[c->info] ) {

                 visited[ c->info ];

                 DFS( c->info );   
            }

            c = c->next;
     }

     sol[++sol[0]] = node;
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

    for(i = sol[ 0 ]; i >= 1;i--) printf("%d ", sol[i]), fprintf(fout, "%d ", sol[i]);

    fclose( fout );
}