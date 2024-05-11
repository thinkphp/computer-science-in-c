/*
Problema1 (arbore):
Se citeste un graf neorientat. Acesta este dat prin matricea de adiacenta. Se ca
cere programul sa decida daca graful este arbore sau nu.


- daca avem un graf orientat: conex si fara cicluri = arborescenta

 (caz particular: arbori binari de cautare) radacina si niveluri

 Parcurgerile: inordine, postordine, preordine

- daca avem un graf neorientat: conex si fara cicluri = arbore

Problema2:
Se citeste un graf orientat. Acesta este dat prin matricea de adiacenta. Se ca
cere programul sa decida daca graful este sau nu arborescenta. In caz afirmativ, se va tipari radacina acestuia.

*/

#include <iostream>
#define FIN "graph.in"
#define FOUT "graph.out"
#define SIZE 100

using namespace std;

int mat[SIZE][SIZE],mat2[SIZE][SIZE],
    n,
    used[SIZE],
    found = 0,
    ok,
    root,
    suma, r, radacina = 0;

void read_graph() {

    int i, j;

    freopen(FIN,"r",stdin);

    cin>>n;//citim numarul de noduri

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

    for( k = 1; k <= n; ++k )

       if(mat[ node ][ k ] == 1 || mat[ k ][ node ] == 1) {

               //mat[1][2] = 0;
               //mat[2][4] = 0
               //sterge arcul
               mat[ k ][ node ] = mat[ node ][ k ] = 0;

               if( used[ k ] == 0 ) DFS( k );
               //daca gaseste used[k] == 1

               else found = 1;
       }
}

//parcurgere in adancime a grafului
void DFS2(int node) {

     int k;

     used[node] = 1;

     for(k = 1; k <= n; ++k) {

         if(mat[node][k] == 1 && used[k] == 0) DFS2(k);
     }
}

int main(int argc, char const *argv[]) {

  read_graph();
  display_graph();

  //facem o copie a grafului in mat2[][]
  for(int i = 1; i <= n; ++i)

      for(int j = 1; j <= n; ++j)

        mat2[i][j] = mat[i][j];

  DFS( 1 );

  //daca suma nodurilor vizitate === numarul de noduri atunci este conex
  for(int i = 1; i <= n; ++i) suma += used[ i ];

  if( suma != n ) cout<<"Graful nu este conex!"<<endl;

  else cout<<"Graful este connex!\n";

  if( found == 1 ) cout<<" Graful are cel putin un ciclu! ";

      else

        cout<<"Graful nu are cicluri!\n";

  if( suma == n && !found ) {

      cout<<"Este arborescenta!";

      ok = 1;

  } else {

      cout<<"\nNu este arborescenta!";
  }

  //recopiem graful in mat din mat2
  for(int i = 1; i <= n; ++i) {

      for(int j = 1; j <= n; ++j) {

         mat[i][j] = mat2[i][j];
      }
  }

  //daca graful orientat este arborecenta atunci incercam sa detercam radacina arborescentei
  if( ok ) {

      r = 1;

      do {
          suma = 0;
          //reset la toate nodurile parcurse; nevizitate
          for(int i = 1; i <= n; ++i) used[ i ] = 0;

          DFS2( r );

          for(int j = 1; j <= n; ++j) suma+=used[j];

          if( suma == n ) {

             cout<<"\nRadacina este: "<<r<<endl;

             radacina = 1;

          } else r++;

      }while(!radacina && r<=n);
  }

//TREE
//Binary Search Tree = arbore binar de cautare (arborescenta)
//Binary Tree = arborescenta
//Tree = arbore
  return 0;
}
