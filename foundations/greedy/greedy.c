/*
 * Techniques of Programming; Greedy for Salesman
 */

#include <stdio.h>
#define MAX 20
#define Gmin 8888

//function prototypes
void read(); //read from file the graph
void read2(); //read the graph from file
void matrix(); //display the matrix of costs
void greedy(); //greedy in action

int mat[ MAX ][ MAX ];

int num_nodes, 
    num_edges;

int main() {

    read(); 

    greedy();

    return(0);
}

void greedy() {

     int i, 
         j, 
         min, node, start, next = 0;
     int cost = 0; 

     int selected[ MAX ];

     for(i=0;i<=num_nodes;i++) selected[i] = 0;

     //start node
     node = 1;

     start = node;

     printf("%d ",start); 

     selected[ node ] = 1; 

     for(i = 1; i <= num_nodes - 1; i++) {

         min = Gmin; 

         for(j = 1; j <= num_nodes; j++) {

             if( mat[ node ][ j ] != 0 && selected[ j ] == 0  && mat[node][j] < min ) {
                 
                    min = mat[ node ][ j ];
                    next = j;
             }                
         } 

         cost = cost + mat[ node ][ next ];

         printf("%d ", next); 

         selected[ next ] = 1;
 
         node = next; 
     }

     printf("%d ",start);

     printf("cost = %d", cost + mat[start][node]);

};

//Here we read the matrix of costs from Graph; version 1
void read() {

     int i, j, cost;

     freopen("graph_costs.in", "r", stdin);
     freopen("output.out", "w", stdout);

     scanf("%d", &num_nodes);
     scanf("%d", &num_edges);

     for(; num_edges; num_edges--) {

           scanf("%d %d %d", &i, &j, &cost);
           mat[i][j] = cost;
           mat[j][i] = cost;            
     }
};


//Here we read the matrix of costs from Graph; version 2
void read2() {

     int i, j, cost;

     freopen("graph_costs2.in", "r", stdin);

     freopen("output.out", "w", stdout);

     scanf("%d", &num_nodes);     
     
     for(i=1;i<=num_nodes;i++) {

          for(j=1;j<=num_nodes;j++) {

              scanf("%d",&mat[i][j]);
          }
     }        
};


//method that displays the matrix of cost
void matrix() {

     int i,j;

     for(i=1;i<=num_nodes;i++) {

         for(j=1;j<=num_nodes;j++) {

             printf("%d ",mat[i][j]);
         }
             printf("\n");
     }
}