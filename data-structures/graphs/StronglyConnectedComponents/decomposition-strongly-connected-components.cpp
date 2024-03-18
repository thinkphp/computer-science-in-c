#include <iostream>
#define FIN "graf.in"
#define FOUT "graf.out"
#define SIZE 100

using namespace std;

int mat[ SIZE ][ SIZE ], succ[SIZE],
                     prec[SIZE],
nodes, start_node, nrc;

//                           1
// succesorii nodului i ..sunt nodurile j pentru care exista drum de la i la j
void Depth_First_Search1( int node ) {

    int k;

    succ[ node ] = nrc;

    for(k = 1; k <= nodes; ++k) {

        if(mat[ node ][ k ] == 1 && succ[k] == 0) Depth_First_Search1( k );
    }
}

void Depth_First_Search2(int node) {

     int k;

     prec[ node ] = nrc;

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

  read_graph();

  nrc = 1;

  for(int i = 1; i <= nodes; ++i) {

      if(succ[ i ] == 0) {

         succ[ i ] = nrc;

         //marcam succesorii
         Depth_First_Search1( i );

         //marcam predecesorii
         Depth_First_Search2( i );

         for(int j = 1; j <= nodes; ++j)

            if(succ[j]!=prec[j]) succ[j] = prec[j] = 0;

         nrc++;
      }
  }


  for(int i = 1; i < nrc; ++i) {

      printf("Componenta %d: ", i);

      for(int j = 1; j <= nodes; ++j) {

        if(succ[ j ] == i) printf("%d ", j);
      }

      cout<<"\n";
  }

//1 2 3 4 5
//1 1 1 1 1
//1 1 1 0 0

//1 1 1 0 0
//1 1 1 0 0


  return 0;
}
