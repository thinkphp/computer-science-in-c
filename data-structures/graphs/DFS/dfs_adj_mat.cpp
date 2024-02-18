//Depth First Search (parcurgere in adancime)
//Breadth First Search (parcurgere in latime)
#include <iostream>
#define FIN "graph.in"
#define DIM 100
int matrix[DIM][DIM], //matricea de adiacenta
    nodes,//numarul de noduri
    explored[ DIM ];//il folosim atunci cand vizitam un nod

//parcurgerea grafului in adancime
void dfs( int node ) {

     //afisam nodul
     printf("%d ", node);

     //se marcheaza ca fiind explorat, vizitat
     explored[ node ] = 1;

     //parcurg toti descendentii nodului si se apeleaza din nou dfs cu primul descendent
     for(int i = 1; i <= nodes; ++i) {
           //daca exista un arc de la node la nodul i, inseamna ca
           //i este descendent, atunci verificam in acelasi timp
           //si daca nodul i este vizitat, explorat,
           //in caz afirmativ adica daca nu este vizitat sau explorat
           //apelam din nou functia DFS cu nodul i
           if( matrix[ node ][ i ] == 1 && explored[ i ] == 0)

           dfs( i );
     }
}

using namespace std;

void ReadGraph() {

    for(int i = 1; i <= nodes; ++i) {

      for(int j = 1; j <= nodes; ++j) {

            scanf("%d", &matrix[i][j]);
      }
    }
}

void ReadGraph2() {

      int i, j;

      freopen(FIN, "r", stdin);

      cin>>nodes;

      while( cin>>i>>j ) {
        //i = 1 si j = 2//arc de la 1 la 2
        //arc de la 2 la 1 , nu
        matrix[i][j] = 1;
      }
}

/*
Liste de adiacenta:
7
1 2
1 6
1 3
2 4
2 5
3 6
3 7

1: 2,3,6
2: 4,5
3: 6,7
4
5
6
7
*/

void DisplayGraph() {

     for(int i = 1; i <= nodes; ++i) {

       for(int j = 1; j <= nodes; ++j) {

           printf("%d ", matrix[i][j]);
       }

       printf("\n");
     }
}

int main(int argc, char const *argv[]) {

  ReadGraph2();
  DisplayGraph();
  printf("DFS in action: \n");
  dfs( 1 );//apelam Depth First Search cu nodul 1 de start
  return 0;
}

//matrix[ node ][ i ] == 1 SI explored[ i ] == 0

/*
node ->>> i
daca exista un ARC de la node la i si nu este explorat

mat11 mat12 mat13 mat14 mat15 mat16 mat17
0      1      1    0    0      1     0
daca avem arc de la 1 la 2, apare 1
daca avem arc de la 1 la 3, apare 1
daca avem arc de la 1 la 6, apare 1
in rest linia se completeaza cu 0 pentru ca nu avem arce
*/
