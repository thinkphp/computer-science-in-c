//parcurgerea in adancime folosind stiva
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

int used[100];

void ReadGraph_Matrix() {

     int i, j;
     freopen("graph.in", "r", stdin);
     //citire numarul de noduri
     cin>>nodes;

     while(cin>>i>>j) {

         matrix[ i ][ j ] = 1;
     }
}

void ReadGraph_Lists() {

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

void DFS( int node ) {
     printf("%d ", node);
     used[ node ] = 1;
     struct Node *c = List[ node ];
     while( c ) {
          if(!used[ c->data]) {
              DFS( c->data );
          }
          c = c->next;
     }
}

void DFS_Matrix(int node) {

    //afisam nodul
    printf("%d ", node);

    //este explorat
    used[node] = 1;

    //parcurg toti descendentii nodurlui si apelez primul

    for(int i = 1; i <= nodes; ++i) {

         if(matrix[ node ][ i ] == 1 && used[ i ] == 0)

         DFS_Matrix( i );
    }

}

int main(int argc, char const *argv[]) {

  //read graph
  //ReadGraph_Lists();
  ReadGraph_Matrix();

  displayMatrix();

  //DFS(1);
  DFS_Matrix(1);

  return 0;
}
