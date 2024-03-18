#include <iostream>
#define FIN "graf.in"
#define FOUT "graf.out"
#define SIZE 100

using namespace std;

int mat[SIZE][SIZE], succ[SIZE],
                     prec[SIZE],
nodes, start_node;

//                           1
// succesorii nodului i ..sunt nodurile j pentru care exista drum de la i la j
void Depth_First_Search1( int node ) {

    int k;

    succ[ node ] = start_node;//daca incep cu nodul 1 succ[1] = 1

    for(k = 1; k <= nodes; ++k) {

        if(mat[ node ][ k ] == 1 && succ[k] == 0) Depth_First_Search1( k );
    }
}

void Depth_First_Search2(int node) {

     int k;

     prec[ node ] = start_node;

     for(k = 1; k <= nodes; ++k) {

         if(mat[ k ][ node ] && prec[ k ] == 0) {

            Depth_First_Search2( k );
         }
     }

}


void read_graph() {

     int i, j;

     freopen(FIN,"r",stdin);

     cin>>nodes;

     while( cin>>i>>j ) {

           mat[i][j] = 1;
     }

}

int main(int argc, char const *argv[]) {

  cout<<"Start Node = ";
  cin>>start_node;

  read_graph();


  succ[start_node] = start_node;
  prec[ start_node ] = start_node;

  //apelam DFS pentru a marca succesorii nodului de start
  Depth_First_Search1( start_node );
  Depth_First_Search2( start_node );

  for(int i = 1; i <= nodes; ++i) printf("%d ", succ[i]);
  printf("\n");
  for(int i = 1; i <= nodes; ++i) printf("%d ", prec[i]);

  //apelam DFS pentru a marca predecesorii nodului de start
  //Depth_First_Search2( start_node );


  printf("\n%s: ", "Componenta Tare conexa careia ii apartine");

  for(int j = 1; j <= nodes; ++j) {

       if(succ[j] == prec[j] && succ[j] == start_node) {

        printf("%d ", j);
       }
  }

  return 0;
}
