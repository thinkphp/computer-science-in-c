/*
 * 
 *  @ Depth First Search 
 *
 *  @ Graph -> Matrix of Adjacency -> recursion
 *
 *  @ author Adrian Statescu <mergesortv@gmail.com> <http://thinkphp>
 *
 *  @ Compiler -> C 
 *
 */
#include <stdio.h>
#define MAX 1000
#define FIN "bfs.in"
#define FOUT "bfs.out"

FILE *fin, *fout;

int num_nodes, num_arcs;

int matrix_of_adjacency[ MAX ][ MAX ];
int Queue[ MAX ];
int visited[ MAX ];

int first_index, 
    last_index;



//function prototype
void readGraph();
void BFS();
void displayMatrixAdjacency();
void displayQueue();

int main() {

    readGraph();
    displayMatrixAdjacency();

     first_index = 1;
      last_index = 1;
      visited [ first_index ] = 1;
      Queue[ first_index ] = 1;

    BFS();

    displayQueue();

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

void BFS() {

      int node, i;
   
      if(first_index <= last_index) {

           node = Queue[ first_index ];

           for(i = 1; i <= num_nodes; i++) {

                   if(matrix_of_adjacency[ node ][ i ] == 1 && !visited[ i ]) {

                            visited[ i ] = 1;

                            Queue[ ++last_index ] = i;
                   } 
           }   
          
           first_index++;  

           BFS();
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

void displayQueue() {

     int j;  

     for(j = 1; j <= num_nodes; j++) {

             printf("%d ", Queue[ j ]);
     }   

}