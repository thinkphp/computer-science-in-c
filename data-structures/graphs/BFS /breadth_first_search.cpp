//parcurgerea in latime folosind o coada
#include <iostream>
#include <cstring>

using namespace std;

struct Node {

   int data;
   struct Node *next;
};

int nodes; //numarul de noduri

struct Node *List[ 100 ];

int matrix[100][100];

int Queue[ 100 ],

   first_index,

   last_index,

   used[ 100 ];

void ReadGraph_Matrix() {

     int i, j;
     freopen("graph.in", "r", stdin);
     //citire numarul de noduri
     cin>>nodes;
     while(cin>>i>>j) {
         matrix[ i ][ j ] = 1;
     }
}


void ReadGraph() {

    int i, j;

    freopen("graph.in", "r", stdin);

    cin>>nodes;

     //cat timp pot sa citesc din file arc(i,j)
    while(cin>>i>>j) {

        struct Node *c = new Node;

        c->data = j;

        c->next = List[ i ];

        List[ i ] = c;
    }
}

void BFS(int node) {

    memset(used, 0, sizeof(used));

    first_index = last_index = 1;

    //add to the Queue
    Queue[ first_index ] = node;

    used[ node ] = 1;

    //cat timp avem conditia adevarata
    while( first_index <= last_index ) {

          struct Node *c = List[Queue[first_index]];

          while(c) {
              if( used[c->data] == 0 ) {
                last_index++;
                Queue[ last_index ] = c->data;
                used[c->data] = 1;
              }
              c = c->next;
          }

          first_index++;
    }

    printf("%s\n", "Breadth First Search");

    for(int node = 1; node <= nodes; ++node) {

        printf("%d ", Queue[node]);
    }
}

void DisplayGraph() {

     printf("%s\n", "Lista de adiacenta");

     for(int i = 1; i <= nodes; ++i) {

          struct Node *p = List[ i ];

          printf("Node %d:", i);

          while(p!=nullptr) {

             cout<<p->data<<" ";

             p = p->next;
          }

          printf("\n");
     }
}

void displayMatrix() {
         for(int i = 1; i <= nodes; ++i) {
              for(int j = 1; j <= nodes; ++j) {
                 printf("%d ", matrix[i][j]);
              }
              cout<<endl;
        }
}

void BFS_AdjMat( int node ) {

    memset(used, 0, sizeof(used));

    first_index = last_index = 1;

    Queue[ first_index ] = node;

    used[ node ] = 1;

    while(first_index <= last_index) {

         for(int i = 1; i <= nodes; ++i) {

              if(matrix[ Queue[first_index] ][ i ] == 1 && used[ i ] == 0) {

                      used[ i ] = 1;
                 
                      last_index++;
                 
                      Queue[last_index] = i;
              }
         }

         first_index++;
    }

    printf("BFS: \n");

    for(int i = 1; i <= nodes; ++i) {

        printf("%d ", Queue[i]);
    }
}

int main(int argc, char const *argv[]) {

  //citire graph
  //ReadGraph();
  ReadGraph_Matrix();

  displayMatrix();

  BFS_AdjMat(1);

  //display graph
  //DisplayGraph();

  //parcurg in latime pornind de la nodul 1
  //BFS( 1 );

  return 0;
}
