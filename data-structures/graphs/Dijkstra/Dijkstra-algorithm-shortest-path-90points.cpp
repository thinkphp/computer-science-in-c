/*
     Algoritmul lui Dijkstra
*/
#include <bits/stdc++.h>
#include <vector>
#define MAXN 50005
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"
#define PlusINFINITY ((1LL<<31)-1)

using namespace std;

vector<int> V[MAXN];
vector<int> C[MAXN];

queue<int> Queue;
int distMin[MAXN];
bitset<MAXN> inQueue( 0 );

//MAXN = 5
//inQueue: 00000
//00000000000000000000000000000000000000000000000

int nodes,
    edges;

void read_graph() {

    int x,
        y,
        cost;

    freopen(FIN, "r", stdin);

    scanf("%d %d", &nodes, &edges);
    //printf("%d %d\n", nodes, edges);

    for(int edge = 1; edge <= edges; ++edge) {
        //3 5 6
        //x = 3
        //y = 5
        //cost = 6
        //V[ 3 ].push_back( 5 );
        //C[ 3 ].push_back( 6 );
        scanf("%d %d %d", &x, &y, &cost);
        //printf("%d %d %d\n", x, y, cost);

        V[ x ].push_back( y );
        C[ x ].push_back( cost );
    }
}

void display_graph() {

     printf("Graful reprezentat prin liste de adiacenta: \n");

     for(int i = 1; i <= nodes; ++i) {

          printf("Node %d --> ", i);

          for(int j = 0; j < V[i].size(); ++j)
          cout<<V[i][j]<<" ";

          printf("\n");
     }
}

void display_costs() {

     printf("Graful costurilor: \n");

     for(int i = 1; i <= nodes; ++i) {

          printf("Node %d --> ", i);

          for(int j = 0; j < V[i].size(); ++j)

                  cout<<C[i][j]<<" ";

          printf("\n");
     }
}

/*
1 2 1
1 4 2
4 3 4
2 3 2
4 5 3
3 5 6

V[1].size() => 2

V[1][0] -> 2
V[1][1] -> 4

Listele de adiacenta:
1: 2, 4
2: 3
3: 5
4: 5
5: NULL

facem o asociere intre V[nodes] si C[nodes]

Costuri:
1: 1, 2
2: 2
3: 6
4: 3
5: NULL

C[3][0] =>

V[2].size() = 1
V[2][0] --->2
C[2][0] ->>2


*/

// ---> 1 2 3 4 5 6 7 8 9 10 11 <---
//int curr = Queue.front()
//curr = 1
//Queue.push(11)

//distMin[i] = distanta de la nodul 1 la i, unde i reprezinta un nod de la 2, la nodes

//tehnica Greedy
void dijkstra() {

     //distanta de la nodul 1 la fiecare nod va fi +oo
     for(int i = 2; i <= nodes; ++i) distMin[ i ] = PlusINFINITY;

     //distanta de la nodul 1 la nodul 1 => 0
     distMin[ 1 ] = 0;

     //adaug in coada nodul 1
     Queue.push( 1 );

     //marchez faptul ca nodul 1 se afla in coada
     inQueue[ 1 ] = true;


     //atata timp cat avem noduri in coada sa executa instructiunile
     //se verifica conditia: coada este goala? nu este goala coada pentru ca avem nodurile [2,4]
     while( !Queue.empty() ) {

            //luam nodul front din coada care este 1
            //retinut in variabila curr (current)

            //curr = 2
            //curr = 4
            //[ 3, 5]
            int curr = Queue.front();

            //curr = 3

            //scoate din coada nodul 1
            //scoate nodul 2
            //coada are doar nodul [4]
            Queue.pop();
            //scoate din coada pe 4

            //[ 5]

             //marcam faptul ca nodul 1 nu mai figureaza in coada, nu se mai afla
             //inQueue[2] = false
             //00001000
            inQueue[ curr ] = false;
            //inQueue[ 4 ] = false
            //inQueue[ 5 ] = false


            //iteram prin toti descendentii nodului 1
            //V[1].size() = 2 descendenti
            //v[1][0] = 2
            //v[1][1] = 4

            //iteram prin descendentii nodului 2
            //v[2].size() = 1

            //v[4].size() = 2

            for(int i = 0; i < V[ curr ].size(); ++i) {


              int y = V[ curr ][i];//2//4//3//3//5//5

              int cost = C[ curr ][i];//1//2//2//4//5//6

              //distanta de la 1 la 2 este mai mare decat distanta de la 1 la 1 plus costul 1 ?
              //distanta de la 1 la 4 este mai mare decat distanta de la 1 la 1 plus costul 2 ?

              //distanta de la 1 la 3 este mai mare decat distanta de la 1 la 2 plus costul 2
              if( distMin[ y ] > distMin[ curr ] + cost) {

                  //distanta de la 1 la 2 se va actualiza cu distanta de la 1 la 1 plus costul 1
                  //distanta de la 1 la 2 = 1

                  //distanta de la 1 la 4 se va actualiza cu distanta de la 1 la 1 plus costul 2
                  // distanta de la 1 la 4  = 2

                  //se actualizeaza distanta de la 1 la 3 = 3

                  //distanta de la la 1 la 5 se actualizeaza cu 5
                  distMin[ y ] = distMin[ curr ] + cost;

                  //daca nu se afla in coada sa adaugam nodul 2
                  if(!inQueue[ y ]) {

                      //coada se actualizeaza [ 2, 4 ]

                      //coanda se actualizeaza cu [ 4, 3 ]
                      //coanda adaugare [4,3,5]
                      Queue.push( y );

                      //0000 0100
                      //marcam inQueue setat cu 1, exista incoada
                      //marcam inQuue setat cu 1 nodul 3
                      inQueue[ y ] = true;
                  }
              }
            }
     }
}

void write_data() {
    freopen(FOUT, "w", stdout);
    //printf("Dijkstra in Action:\n");
    for(int i = 2; i <= nodes; i++) printf("%d ", (distMin[ i ] < PlusINFINITY ) ? distMin[ i ] : 0);
}

int main(int argc, char const *argv[]) {

  read_graph();
  //display_graph();
  //display_costs();
  dijkstra();
  write_data();
  return 0;
}
