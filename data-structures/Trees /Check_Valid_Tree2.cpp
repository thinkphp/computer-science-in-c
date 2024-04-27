/*
- grafuri neorientate ( arbori )
- grafuri orientate   ( arborescente )

Se numeste arbore un graf neorientat care este conex si nu contine cicluri.

1. Mai intai , trebuie vazut daca graful este conex. In cazul grafurilor orientate acesta
problema se rezolva printr-o simpla parcurgere in adancime (DF). Dar in cazul grafurilor neorientate?

2. TRebuie analizat daca graful nu are cicluri. Aceasta problema se rezolva  tot cu ajutorul parcurgerii in adancime.
Parcurgea asigura  selectia unei muchii o singura data. Daca graful are cel putin un ciclu, adica un nod este atins de doua ori.
Cum ne putem da seama daca acest lucru are loc? SImplu, daca a fost atins un nod i, pentru care a[i] = 1;

Se da un graf neorientat. Sa se scrie un program care verifica daca este ARBORE.
*/

#include <bits/stdc++.h>
#define FIN "graph.in"
#define FOUT "graph.out"
#define SIZE 100

using namespace std;

int matrix_adiacenta[ SIZE ][ SIZE ],
    n,//stocheaza numarul de noduri
    cycle = 0, //semnaleaza daca are ciclu sau nu
    sum = 0,//suma nodurilor
    folosit[ SIZE ]; //vector pentru a afla daca este folosit nodul sau nu

void read_graph() {

      int i, j;

      freopen(FIN, "r", stdin);

      scanf("%d", &n);

      while(cin>>i>>j) {
          matrix_adiacenta[i][j] = 1;
          matrix_adiacenta[j][i] = 1;
      }
}

void display_graph() {

     int i , j;
     for(i = 1; i <= n; ++i) {
       for(j = 1; j <= n; ++j) {
         printf("%d ", matrix_adiacenta[i][j]);
       }
       cout<<endl;
     }
}

//Depth First Search
void DFS( int node ) {

    //marcam nodul ca fiind explorat
    folosit[ node ] = 1;

    for( int i = 1; i <= n; ++i ) {

       if(matrix_adiacenta[ node ][ i ] == 1) {

           matrix_adiacenta[ i ][ node ] = 0;

           //daca nodul nu este explorat
           if( folosit[ i ] == 0 ) DFS( i );

              else cycle = 1;
       }
    }
 }


int main(int argc, char const *argv[]) {

    printf("Arbore = graf conex si fara cicluri. Program verificare!\n");

    read_graph();

    display_graph();

    memset(folosit, 0, sizeof( folosit ));

    DFS( 1 );

    for(int i = 1; i <= n; i++) {

        sum = sum + folosit[ i ];
    }

    if( sum != n ) printf("Graful nu este conex (connected). Nu este Arbore Valid!");

    else if( cycle == 1 ) {

         printf("Graful are cel putin un ciclu.");

    } else {

       printf("Graful este un VALID TREE (arbore valid)");
    }

    return 0;
}
