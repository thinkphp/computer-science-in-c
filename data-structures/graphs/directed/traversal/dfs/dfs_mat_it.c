/*
 * 
 *  @ Depth First Search 
 *
 *  @ Graph -> Matrix of Adjacency -> iterative version
 *
 *  @ author Adrian Statescu <mergesortv@gmail.com> <http://thinkphp>
 *
 *  @ Compiler -> GNU C gcc dfs_mat_it.c -o d.exe
 *
 */
#include <stdio.h>
#define MAX 1000
#define FIN "dfs.in"
#define FOUT "dfs.out"

FILE *fin, *fout;

int num_nodes, 
    num_arcs;

int matrix_of_adjacency[ MAX ][ MAX ], 
    visited[ MAX ], 
    sol[ MAX ], 
    stack[ MAX ],
    start_node;

//function prototype
void readGraph();
void DFS();
void displayMatrixAdjacency();
void displaySol();

int main() {

    int j;

    int start_node = 1;

    readGraph();

    displayMatrixAdjacency(); 

    DFS();

    displaySol();
   
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

void DFS() {

    int _index,
        node,
        found,
        i;

    start_node = 1;

    _index = 0;

    visited[ start_node ] = 1;

    stack[ _index ] = 1; 
 
    sol[++sol[0]] = _index + 1;  

    while( _index >= 0) {

           node = stack[ _index ]; 

           found = 0;

           for(i = 1; i <= num_nodes && !found; i++)
                  
                   if(matrix_of_adjacency[ node ][ i ] == 1 && !visited[ i ])

                      found = 1;

           if( found ) {
        
              //we take i-1 because i was i + 1
              sol[++sol[0]] = i - 1;

              //we take i-1 because i was i + 1
              visited[ i - 1] = 1;

              //we take i-1 because i was i + 1
              stack[++_index] = i - 1;

           } else {

             _index--;

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

    fout = fopen(FOUT, "w");

    printf("DFS -> "); 

    fprintf(fout, "Depth First Search -> "); 
   
    for(j = 1; j <= sol[0]; j++) 

            printf("%d ", sol[ j ]), fprintf(fout, "%d ", sol[ j ]);

    fclose( fout );
}
