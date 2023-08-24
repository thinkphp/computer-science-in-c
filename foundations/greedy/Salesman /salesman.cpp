#include <iostream>
#define FIN "salesman.in"
#define BIG 999999
#define DIM 100

using namespace std;

int matrix[ DIM ][ DIM ], //define adjacency matrix
    explored[ DIM ], //visited array
    nodes; //define a variable that holds the number of the nodes;

void readMatrix() {

     cin>>nodes;

     for(int i = 1; i <= nodes; ++i) {

       for(int j = 1; j <= nodes; ++j) {

           cin>>matrix[i][j];
       }
     }

     cout<<"Adjacency Matrix:\n";

     for(int i = 1; i <= nodes; ++i) {

       for(int j = 1; j <= nodes; ++j) {

           cout<<matrix[i][j]<<" ";
       }
       cout<<endl;
     }

     cout<<"\n";
}

void greedy() {

     int node, start, min, next_node = 1, cost = 0;

     for(int peak = 1; peak <= nodes; ++peak) explored[ peak ] = 0;

     node = 1;

     start = node;

     explored[ node ] = 1;

     cout<<"Road:\n";

     cout<<node<<" ";

     for(int i = 1; i <= nodes - 1; ++i) {

             min = BIG;

             for(int vertice = 1; vertice <= nodes; ++vertice) {

                     if(matrix[ node ][ vertice ] != 0 && explored[ vertice ] == 0 && matrix[ node ][ vertice ] < min) {

                         min = matrix[ node ][ vertice ];

                         next_node = vertice;
                     }
             }

             cout<<next_node<<" ";

             explored[ next_node ] = 1;

             cost = cost + matrix[ node ][ next_node ];

             node = next_node;
     }


     cout<<start;

     cost = cost + matrix[ start ][ node ];

     cout<<"\nCost = "<<cost<<"\n";
}

int main(int argc, char const *argv[]) {

  freopen(FIN, "r", stdin);

  readMatrix();

  greedy();

  return 0;
}
