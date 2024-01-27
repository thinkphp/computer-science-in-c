#include <iostream>
#define FIN "graph.in"
#define FOUT "graph.out"
#define size 100

using namespace std;

int succ[ size ], //tinem minte succesorii unui nod i

    prec[ size ], //tinem minte predecesorii unui nod i

    matrix[ size ][ size ],

    i,

    j,

    nodes,

    nrc;

//aplicam DFS pentru a gasi succesorii = Depth First Search

//succesorii nodului i => toate nodurile j pentru care exista drum de la i la j

//succ[ 1 ] = 1
//succ[ 2 ] = 1
//succ[ 3 ] = 1
void dfs_r1( int node ) {

    int k;
    succ[ node ] = nrc;
    for(k = 1; k <= nodes; ++k) {
        if(matrix[ node ][ k ] == 1 && succ[ k ] == 0) {
            //dfs_r1(4)
            //dfs_r1(5)
            dfs_r1( k );
        }
    }
}

//aplicam DFS pentru a gasi predecesorii = Depth First Search

//predecesorii nodului i => toate nodurile j pentru care exista drum dela j la i
void dfs_r2( int node ) {
     int k;
     prec[ node ] = nrc;
     for(k = 1; k <= nodes; ++k) {
        if(matrix[ k ][ node ] == 1 && prec[ k ] == 0) {
           dfs_r2( k );
        }
     }
}

void readgraph() {

     int x, y;

     freopen(FIN, "r", stdin);

     cin>>nodes;

     //graful este orientat
     while( cin>>x>>y ) {

         matrix[ x ][ y ] = 1;  //marcam existenta arcului intr-o matrice binara
     }
}

void displaygraph() {

    for(int i = 1; i <= nodes; ++i) {

      for(int j = 1; j <= nodes; ++j) {

         cout<<matrix[i][j]<<" ";
      }
      cout<<"\n";
    }
}

int main( int argc, char const *argv[] ) {

  readgraph();

  nrc = 1;

  displaygraph();


/*  dfs_r1( 1 );

  dfs_r2( 1 );

  cout<<"Succesori: \n";
  for(int i = 1; i <= nodes; ++i) cout<<succ[i]<<" ";

  printf("\n");
  cout<<"Predecesori: \n";
  for(int i = 1; i <= nodes; ++i) cout<<prec[i]<<" ";

  printf("\n");
}

        succ: 0 0 0 0 0
        prec: 0 0 0 0 0

        dfs_r1(1)
        dfs_r2(1)
*/
  for(int i = 1; i <= nodes; ++i) {
      if( succ[ i ] == 0 ) {
         succ[ i ] = nrc;
         dfs_r1( i );
         dfs_r2( i );
         for(int j = 1; j <= nodes; ++j)
             if(succ[ j ] != prec[ j ]) succ[ j ] = prec[ j ] = 0;
          nrc++;//2
      }
  }
  for(int i = 1; i < nrc; ++i) {

          cout<<"Componenta "<<i<<"\n";

          for(int j = 1; j <= nodes; ++j)

              if( succ[ j ] == i ) cout<<j<<" ";

          cout<<"\n";
  }

  return 0;
}


/*
succ: 0 0 0 0 0
prec: 0 0 0 0 0


succ: 1 1 1 1 1
prec: 1 1 1 0 0

succ: 1 1 1 0 0
prec: 1 1 1 0 0

nrc++; nrc=2

succ: 1 1 1 2 2
prec: 1 1 1 2 2

Output:

Componenta 1: 1 2 3

Componenta 2: 4 5

node = 5
node = 4

dfs_r1( 5 )
dfs_r2( 4 )

node 4
succ: 0 0 0 0 1
prec: 1 1 1 0 0

In cazul in care nu exista arc de la 5 la 4

- succ: toate nodurile j pentru care exista drum de la i la j
- prec: toate nodurile j pentru care exista drum de la j la i

node 5
succ: 0 0 0 0 0
prec: 1 1 1 1 0

*/

//algoritmul lui Kosaraju
