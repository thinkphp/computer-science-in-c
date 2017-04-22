#include <iostream>
#include <fstream>
#include <vector>
#define SIZE 1000
#define FIN "graph_adjacency.in"

 using namespace std;
 
 int nodes, edges, visited[ SIZE ], a, b;
 vector<int> G[SIZE];

 void dfs(int node) {

      visited[ node ] = 1;

      printf("%d ", node);

      for(vector<int>::iterator it = G[node].begin(); it != G[node].end(); ++it) {

                 if(!visited[ *it ]) {

                     dfs(*it); 
                 }  
      } 
 }

int main() {

 ifstream fin(FIN); 

 fin>>nodes>>edges;

 while(edges--) {

       fin>>a>>b;
       G[ a ].push_back( b );
 }


 dfs(1);

 return(0);
}