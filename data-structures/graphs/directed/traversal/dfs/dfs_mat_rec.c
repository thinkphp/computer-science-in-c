/*
 * 
 *  @ Depth First Search 
 *
 *  @ Graph -> Matrix of Adjacency -> recursive
 *
 *  @ author Adrian Statescu <mergesortv@gmail.com> <http://thinkphp>
 *
 *  @ Compiler -> C 
 *
 */
#include <stdio.h>
#define MAX 1000
#define FIN "dfs.in"
#define FOUT "dfs.out"

FILE *fin, *fout;

int num_nodes, num_arcs;
int matrix_of_adjacency[ MAX ][ MAX ];
int visited[ MAX ];
int sol[ MAX ];

//function prototype
void readGraph();
void DFS();
void DFS2();
void displayMatrixAdjacency();
void displaySol();
void displaySol2();

int main() {

    int j;

    int start_node = 1;

    readGraph();

    displayMatrixAdjacency(); 

    visited[ start_node ] = 1;  

    DFS2( start_node );

    displaySol2();

    return(0);
};

void readGraph() {
  
     int i,j;

     fin = fopen(FIN, "r");

     fscanf(fin, "%d %d", &num_nodes, &num_arcs);

     for(; num_arcs; num_arcs--) {

           fscanf(fin, "%d %d", &i, &j);

           matrix_of_adjacency[ i ][ j] = 1;        
     }

     fclose( fin ); 
};

void DFS( node ) {

     int i;  

     visited[ node ] = 1;      

     for(i = 1; i <= num_nodes; i++) {

         if(matrix_of_adjacency[ node ][ i ] == 1 && !visited[i]) {

                      visited[i] = 1;

                      DFS( i ); 
         }

     }           

     sol[ ++sol[ 0 ] ] = node;

};

void DFS2( node ) {

     int i;  

     sol[++sol[0]] = node;

     visited[ node ] = 1;      

     for(i = 1; i <= num_nodes; i++) {

         if(matrix_of_adjacency[ node ][ i ] == 1 && !visited[ i ]) {

                      visited[i] = 1;

                      DFS2( i ); 
         }

     }           

};


void displayMatrixAdjacency() {

     int i,j;

     for(i = 1; i <= num_nodes; i++) {

         for(j = 1; j <= num_nodes; j++) {

                 printf("%d ", matrix_of_adjacency[ i ][ j ]); 
         } 

                 printf("\n");
     }   
}

void displaySol() {

    int j;  

    for(j = sol[0]; j >= 1; j--) printf("%d ", sol[j]);
}

void displaySol2() {

    int j;  

    fout = fopen(FOUT, "w");

    printf("Depth First Search -> ");

    fprintf(fout, "Depth First Search -> ");

    for(j = 1; j <= sol[0]; j++) printf("%d ", sol[j]), fprintf(fout, "%d ", sol[j]);
}