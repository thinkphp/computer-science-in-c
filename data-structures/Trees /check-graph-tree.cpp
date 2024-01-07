
#include <bits/stdc++.h>
int adjancencyMatrix[100][100], //the matrix
    n,
    cycle = 0,
    sum = 0,
    used[100];//the number of the nodes

void readGraph() {

     int i, j, used[100];

     freopen("graph.in","r",stdin);

     scanf("%d ", &n);

     while(std::cin>>i>>j) {

           adjancencyMatrix[i][j] = 1;

           adjancencyMatrix[j][i] = 1;
      }
}

void dfs( int node )
{
  used[ node ] = 1;

  for(int i = 1; i <= n; ++i) {

        if(adjancencyMatrix[node][i] == 1) {

          adjancencyMatrix[i][node] = 0;

          if( used[i] == 0 ) dfs(i);

           else cycle = 1;
        }
  }
}

int main(int argc, char const *argv[]) {

  printf("Tree = Connected Graph, without cycles.\n");

  readGraph();

  std::cout<<n<<std::endl;

    for(int i = 1; i <= n; ++i ) {

    for(int j = 1; j <= n; ++j ) {

        std::cout<<adjancencyMatrix[i][j]<<" ";
    }

    std::cout<<"\n";
   }

   memset(used, 0, sizeof(used));

   dfs( 1 );

   for( int i = 1; i <= n; ++i ) {

       sum += used[ i ];
   }

   if(sum != n) std::cout<<"The Graph is not connected.";

      else if(cycle == 1) {

        std::cout<<"The Graph has at least cycle.";

      } else {

        std::cout<<"The Graph is a valid Tree.";
      }

  return 0;
}
