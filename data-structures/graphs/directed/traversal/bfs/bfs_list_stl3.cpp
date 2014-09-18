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
#include <queue>
#define MAX 1000
#define FIN "bfs.in"
#define FOUT "bfs.out"
#define pb push_back

using namespace std;

FILE *fin, *fout;

vector<int> List_of_adjacency[ MAX ];
queue<int> QUEUE;
vector<int> sol;

int num_nodes, num_arcs;

int visited[ MAX ];

//function prototype
void readGraph();
void BFS();
void displayListAdjacency();
void displaySol();

int main() {

    readGraph();
    displayListAdjacency(); 
    BFS();
    displaySol();
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
 
     int i, 

         j, 

         node, 

         start = 1;
      
      
      QUEUE.push( start );

      visited[ start ] = 1;

      while(!QUEUE.empty()) {  

           node = QUEUE.front();

           sol.push_back( node );

           QUEUE.pop();

           for(vector<int>::iterator it = List_of_adjacency[ node ].begin(); it != List_of_adjacency[ node ].end(); ++it) {

                     if(!visited[ *it ]) {

                         QUEUE.push( *it );

                         visited[ *it ] = 1; 
                     }
           } 
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

void displaySol() {

     fout = fopen(FOUT, "w");

     for(vector<int>::iterator i = sol.begin(); i != sol.end(); ++i) 

                                     fprintf(fout, "%d ", *i), 

                                     printf("%d ", *i);

     fclose( fout );
}