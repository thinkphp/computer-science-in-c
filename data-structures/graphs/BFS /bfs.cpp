/**
 * Breadth First Search Traversal
 */
#include <iostream>
#include <cstring>

using namespace std;

struct Node {

  int data;
  struct Node *next;
};

int nodes;

struct Node *List[ 100 ];//declare an array of pointers to struct Node

int matrix[100][100];

int Queue[ 100 ],//the queue

    first_index,

    last_index,

    used[ 100 ];

void ReadGraph() {

     int i, j;

     freopen("graph.in","r",stdin);

     cin>>nodes;

     while(cin>>i>>j) {

       struct Node *c = new Node;
       c->data = j;
       c->next = List[i];
       List[i] = c;
     }
}

void AdjancencyMatrix() {

     int i, j;

     freopen("graph.in","r",stdin);

     cin>>nodes;

     while(cin>>i>>j) {

           matrix[i][j] = 1;
     }
}

void DisplayGraph() {

  printf("%s\n","List Adjancency List");
  for(int i = 1; i <= nodes; ++i) {

      struct Node *p = List[i];
      printf("Node %d: ", i);

      while(p) {
        std::cout<<p->data<<" ";
        p = p->next;
      }
      printf("\n");
  }
}

void bfs( int node ) {

     memset(used, 0, sizeof(used));

     first_index = last_index = 1;
     Queue[first_index] = node;

     while(first_index<=last_index) {
       struct Node *c = List[Queue[first_index]];
       while(c) {
         if(used[c->data] == 0) {
            last_index++;
            Queue[last_index] = c->data;
            used[c->data] = 1;
         }
         c = c->next;
       }
       first_index++;
     }

     printf("Breadth First Search: \n");

     for(int i = 1; i <= nodes; ++i) {

       printf("%d ", Queue[i]);
     }
}


void bfs_AdjMat( int node ) {

     memset( used, 0, sizeof( used ) );

     first_index = last_index = 1;

     Queue[ first_index ] = node;

     while( first_index <= last_index ) {

            for(int i = 1; i <= nodes; ++i) {

                if(matrix[ Queue[ first_index ] ][ i ] == 1 && used[i] == 0) {

                     used[i] = 1;
                     last_index++;
                     Queue[last_index] = i;
                }
            }

            first_index++;
     }

     printf("Breadth First Search: \n");
     for(int i = 1; i <= nodes; ++i) {

         printf("%d ", Queue[i]);
     }
     printf("\n");
}

int main(int argc, char const *argv[]) {
  ReadGraph();
  DisplayGraph();
  bfs(1);
  //AdjancencyMatrix();
  //bfs_AdjMat(1);
  return 0;
}
