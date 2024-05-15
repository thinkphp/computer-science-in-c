/*

Problema1:
Se citeste un graf neorientat. Acesta este dat prin matricea de adiancenta. Se cere sa se decida
daca graful este sau nu arbore.


Problema2:
Se citeste un graf orientat. Acesta este dat prin matricea de adiancenta. Se cere sa se decida
daca graful este sau nu arborescenta. In caz afirmativ, se va tipari radacina acestuia.

*/
#include <iostream>

#define FIN "graph.in"
#define FOUT "graph.out"
#define SIZE 100

using namespace std;

int mat[SIZE][SIZE], //matricea de adiacenta
    mat2[SIZE][SIZE], //copie
    used[SIZE],//pentru vizitare
    found = 0,
    n,//numarul de noduri
    ok,
    root,
    suma,
    radacina;

void read_graph() {

     int i, j;

     freopen(FIN,"r",stdin);

     cin>>n;

     while(cin>>i>>j) mat[i][j] = 1;
}

void display_graph() {

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void DFS(int node) {

    int k;

    used[ node ] = 1;

    for(k = 1; k <= n; ++k) {

        if(mat[node][k] == 1 || mat[k][node] == 1) {

          mat[node][k] = mat[k][node] = 0;

          if(used[k] == 0) DFS( k );

          else
              found = 1;
        }
    }
}

void DFS2(int node) {

     int k;

     used[ node ] = 1;

     for(k = 1; k <= n; ++k)

         if(mat[node][k] == 1 && used[k] == 0) DFS2( k );
}


int main(int argc, char const *argv[]) {

  read_graph();
  display_graph();

  for(int i = 1; i <= n; ++i) {

      for(int j = 1; j <= n; ++j) {

        mat2[i][j] = mat[i][j];
      }
  }

  DFS( 1 );

  //daca suma nodurilor vizitate === numarul de noduri atunci este un graf conex

  for(int i = 1; i <= n; ++i) suma += used[ i ];

  if(suma != n) cout<<"Graful nu este conex!\n";
      else
                cout<<"a) Graful este conex!\n";

  if(found == 1) cout<<"Graful are cel putin un ciclu!\n";
         else
               cout<<"b) Graful nu are cicluri!\n";


  if( suma == n && !found ) {

    cout<<"=>>Este arborescenta!";
    ok = 1;
  } else {
    cout<<"Nu este arborescenta!";
  }

  for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
         mat[i][j] = mat2[i][j];
      }
  }


  if( ok ) {

    root = 1;

    do {
      //suma == numarul de noduri

       suma = 0;

      //reset la nodurile parcurse
       for(int j = 1; j <= n; ++j) used[j] = 0;

       DFS2( root );

       for(int j = 1; j <= n; ++j) suma += used[j];

       if(suma == n) {

           radacina = 1;

           cout<<"\n Root = "<<root<<endl;

       } else root++;

    } while( !radacina && root <= n );

  }


  return 0;
}
