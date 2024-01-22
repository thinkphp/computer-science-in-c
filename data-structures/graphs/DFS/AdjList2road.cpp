/*
Problema:
  Fiind dat un graf orientat prin intermediul listelor de adiacenta,
  se cere sa se creeze si tipareasca matricea drumului.
*/
#include <iostream>
#include <cstring> //memset(explored, 0, sizeof(explored))
#define FIN "graph.in"
#define FOUT "graph.out"
#define size 100

using namespace std;

struct Node {
   int data;
   struct Node *next;
};

//declaram lista de adiancenta
struct Node *adjList[ size ];

//declaram matricea de adiacenta drumurilor
int matrix[ size ][ size ];

//un vector care pastreaza varfurile explorate, vizitate
int explored[ size ],

    nodes;//numarul de noduri.


void createList() {

    int i, //varf
        j; //descendent

    freopen(FIN, "r", stdin);

    cin>>nodes;//citim numarul de noduri

/*
1 2
1 3
1 6
2 4
2 5
4 5
3 6
3 7
7 5
*/

    while( cin>>i>>j ) {
        // 1 2
        // 1 3
        //nod este reprezentat in segmentul de date
        struct Node *nod = new Node;//alocam spatiu in HEAP si adresa de acolo este transmisa pointerului nod

        nod->data = j;

        nod->next = adjList[ i ];

        adjList[ i ] = nod;
    }
}

void displayList() {

     struct Node *c;

     //pentru fiecare nod din graf vizualizam descendentii sai
     for(int i = 1; i <= nodes; ++i) {

         printf("Node %d: ", i);

         c = adjList[ i ];

         while( c != nullptr) {

            printf("%d ", c->data);

            c = c->next;
         }
         printf("\n");
     }
}
//Depth First Search = parcurgere in adancime

       //base = 1 si node = 1
       //base = 1 si node = 2
       //base = 1 si node = 4
       //base = 1 si node = 5
void dfs(int base, int node) {

     // 1         1    nu se executa matrix[1][1]
     // 1         2    DA da matrix[1][2] = 1
     // 1         4    DA matrix[1][4] = 1
     // 1         5 matrix[1][5] = 1
     //1 este diferit de 2, rezulta matrix[1][2] = 1
     //1 este diferit de 4 rezulta matrix[1][4] = 1
     //1 este diferint de 5 rezulta matrix[ base ][ node ] = 1
     if( base != node ) matrix[ base ][ node ] = 1;
      //retinem in pointerul c lista simplu inlantuita adjList[1],
      //dar ne putem intrebarea care este aceasta lista?
      //lista descendentilor nodului 1 si anume: 2,3,6
      //retinem in pointerul c lista simplu inlantuita adjList[2]

      //c = adjList[ 1 ] //pointerul c retine adresa listei simplu inlantuite nod 1
      //node 1
     struct Node *c = adjList[ node ];
     //c = adjList[ 2 ] //pointerul c retine adresa listei simply inlantuite pentru nodul 2
     //c = adjList[ 4 ] //pointerul c retine adresa listei cu descendentii nodului 4
     //c = adjList[5] //pointerul c = lista descendentilor nodului 5

     //cautam primul descendent al nodului node=1
    //c->data = 2
    //c->data = 4
    //c->data = 5

     while( c ) {
         //nevizitat, neexplorat, neparcurs
           //primul descendent nevizitat al nodului 1
           if( explored[ c->data ] == 0 ) {

              //dfs(1, 2)
              dfs( base, c->data ); //go to line 89
              //dfs(1, 4)
              //dfs(1, 5)
              //dfs(1, 6)
           }

         c = c->next;//NULL
     }
}

void roadMatrix() {

     for(int i = 1; i <= nodes; ++i){

         for(int j = 1; j <= nodes; ++j) {

           printf("%d ", matrix[i][j]);
         }

         printf("\n");
     }
}

int main(int argc, char const *argv[]) {

    createList();

    printf("Input -> Graful reprezentat prin Liste de adiacenta:\n");

    displayList();

    for(int i = 1; i <= nodes; ++i) {

        //      nodes: 1 2 3 4 5 6 7 8 9
        //explored: [0,0,0,0,0,0,0,0,0,0]
        memset( explored, 0, sizeof( explored ) );

        // dfs(1, 1)
        dfs( i, i );//!!!! 1 si 1 , 2 si 2
    }

    printf("Output -> Matricea Drumurilor\n");

    roadMatrix();

    return 0;
}

/*
int vec[100];

int *p = new int[100];
int *p2 = new int[100];

int *arr;//declari un pointer catre integer

arr = &vec;

in timpul executiei programului sa dezaloci spatiul din memorie runtime
delete p;



dfs(1,5)
dfs(1,4)
dfs(1,2)
dfs(1,1)
  */
