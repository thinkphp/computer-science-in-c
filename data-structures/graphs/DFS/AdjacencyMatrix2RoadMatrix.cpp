#include <iostream>
#include <cstring>
#define FIN "graph.in"
#define FOUT "graph.out"
#define size 100

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

struct Node *adjacencyList[ size ];

int matrix[size][size];

int explored[size];

int nodes; //this variable holds the number of the nodes

void createlist() {

     int i, j;
     struct Node *c;
     freopen(FIN, "r", stdin);
     cin>>nodes;
     cout<<"Number of nodes: "<<nodes<<"\n";
     while(cin>>i>>j){
       c = new Node;
       c->data = j;
       c->next = adjacencyList[i];
       adjacencyList[i] = c;
     }
}

void displayList() {
       struct Node *c;
       for(int i = 1; i <= nodes; ++i) {
         printf("Node %d: ", i);
         c = adjacencyList[i];
         while(c) {
           printf("%d ", c->data);
           c = c->next;
         }
         printf("\n");
       }
}

void dfs(int base, int node) {

     if(base!=node) matrix[ base ][ node ] = 1;

     struct Node *c = adjacencyList[ node ];

     explored[ base ] = 1;

     while( c ){

       if(explored[c->data] == 0) dfs(base, c->data);

       c = c->next;
     }
}

void roadMatrix() {
     for(int i = 1; i <= nodes; ++i) {
         memset(explored, 0, sizeof(explored));
         dfs(i,i);
     }

     for(int i = 1; i <= nodes; ++i) {
         for(int j = 1; j <= nodes; ++j) {
           cout<<matrix[i][j]<<" ";
         }
         cout<<"\n";
     }
}

int main(int argc, char const *argv[]) {

  createlist();
  displayList();
  roadMatrix();
  return 0;
}
