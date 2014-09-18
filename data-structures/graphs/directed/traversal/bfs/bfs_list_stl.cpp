/*
 * 
 *  @ Breadth First Search 
 *
 *  @ Graph -> List of Adjacency -> iterative -> STL
 *
 *  @ author Adrian Statescu <mergesortv@gmail.com> <http://thinkphp>
 *
 *  @ Compiler -> CPP
 *
 */
#include <cstdio>
#include <vector>
#define MAX 1000
#define FIN "bfs.in"
#define FOUT "bfs.out"
#define pb push_back

using namespace std;

FILE *fin, *fout;

vector<int> List_of_adjacency[ MAX ];

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

     fscanf(fin, "%d %d", &num_nodes, &num_arcs);

       while(num_arcs--) {

         fscanf(fin, "%d %d", &i, &j);

         List_of_adjacency[ i ].pb( j ); 

       }
 
     fclose( fin ); 
};

void BFS() {
 
     int first_index, 

         last_index,

         i, j, node;

     first_index = 1;

      last_index = 1;

      visited [ first_index ] = 1;

      Queue[ first_index ] = 1;

      while(first_index <= last_index) {

           node = Queue[ first_index ];

           for(vector<int>::iterator it = List_of_adjacency[ node ].begin(); it != List_of_adjacency[ node ].end(); ++it) {

                     if(!visited[ *it ]) {

                         Queue[ ++last_index ] = *it; 

                         visited[*it] = 1; 
                     }
           } 

           first_index++;  
     }

};

void displayListAdjacency() {

     int i,
         j;

     for(i = 1; i <= num_nodes; i++) {

         printf("%d -> ", i); 

         for(vector<int>::iterator it = List_of_adjacency[ i ].begin(); it != List_of_adjacency[ i ].end(); ++it) {

             printf("%d ", *it);
         }

         printf("\n");         
     }
};

void displayQueue() {

     int index_queue;

     fout = fopen(FOUT, "w");

     for(index_queue = 1;index_queue <= num_nodes; index_queue++) {

         printf("%d ", Queue[ index_queue ]); 

         fprintf(fout, "%d ", Queue[ index_queue ]); 
     }
}