/*
Lista simplu inlantuita:

//1 2 3 4 5

node1 are o referinta catre nodul2
node2 are o referinta catre nodul3
node3 are o referinta catre nodul4
node4 are o referinta catre nodul5

ultimul node are referinta catre NULL

node1 ----> node2 --->node3 ---> node4 --->NULL

Nodul il putem reprezenta ca un struct

typedef struct Node {

   int data;

   struct Node *next;

} Node;
*/
/*
  - creare
  - afisare
  - adaugare dupa un nod
  - stergere node
  - adaugare inainte de un nod
  - sortare
  - reverse
*/

#include <stdio.h>
#include <malloc.h>
#include <time.h>

struct ExecutionTimer {

    clock_t startTime;
    int useFile;
};

//                                              pentru fisier useFile = 1
void initTimer(struct ExecutionTimer *timer, int useFile) {

    timer->startTime = clock();

    timer->useFile = useFile;

    if( useFile ) {

      freopen("input.txt","r", stdin);
      freopen("out.txt","w", stdout);
    }
}

double getExecutionTime(const struct ExecutionTimer *timer) {

       return ((double)(clock() - timer->startTime)) / CLOCKS_PER_SEC;
}

void printExecutionTime(const struct ExecutionTimer *timer) {

      printf("\nExecution Time: %.6f seconds\n", getExecutionTime(timer));
}


typedef struct Node {

   int data;//zona de informatii

   struct Node *next;//zona de referinta catre urmatorul nod
   //struct Node *prev;
   //ultimul nod are referinta NULL

} Node;

//capul listei este un pointer catre Node
//global
Node *head = NULL;

void addToSinglyLinkedList( int val ) {

      if( head == NULL ) {

          Node *new_node = (Node*)malloc(sizeof(Node));

          new_node->data = val;

          new_node->next = NULL;

          head = new_node;

      } else {

        Node *new_node = (Node*)malloc(sizeof(Node));

        new_node->data = val;

        new_node->next = head;

        head = new_node;
      }

}


void displayLinkedList(Node*head) {

  Node *c = head;

  while( c!= NULL ) {

      printf("%d ", c->data);

      c = c->next;//se deplaseaza la urmatorul nod
  }

  printf("\n");
}

void addAfterNode( int afternode, int val ) {

         Node *c = head;

         while(c->data != afternode) c = c->next;

         //se creeaza un nod nou in HEAP
         Node *new_node = (Node*)malloc(sizeof(Node));

         new_node->data = val;//completezi campul de data

         new_node->next = c->next;//adrese 0x1231

         c->next = new_node;
}

void addBeforeNode(int beforenode, int val) {

    //avem de studiat doua cazuri:
    // ----primul caz in care avem de adaugat inainte de capul listei HEAD
    //---- al doilea caz in care avem de adaugat noul nod in interiorul listei
    Node *c = head,
         *new_node = (Node*)malloc(sizeof(Node));

    //daca head este nodul inainte de care vrem sa adaugam
    if(head->data == beforenode) {
          new_node->data = val;
          new_node->next = head;
          head = new_node;
          //al doilea caz : in interiorul listei
    } else {

        c = head;

        while(c->next->data != beforenode) c = c->next;

          new_node->data = val;

          new_node->next = c->next;

          c->next = new_node;
    }
}

// lista 11 ---> -20 ---> 123 ---> 88 ----> 15 --->> 7 ---> 8 ---> 9


// lista in reverse: next=NULL 11 <--- -20 <---- 123 <---- 88 <---- 15 <---- 7 <---- 8 <---- 9
//curr

// (next= NULL)11 ---> -20 ---> 123 ---> 88 ----> 15 --->> 7 ---> 8 ---> 9

Node* reverse(Node*head) {

     Node *curr = head,//am adresa de inceput a listei

          *prev = NULL,
          *next;
//lista: 11 -20 123 88 15 7 8 9
//      curr, curr->next, curr->next->next, curr->next->next->next
          while( curr ) {

              next = curr->next;

              curr->next = prev;

              prev = curr;

              curr = next;
          }

          return prev;
}

//1 2 3 4 5
  //c c->next
  //head
void removeNode(int delNode) {

     Node *ptr;

     //daca este capul listei
     if( head->data == delNode ) {

       ptr = head;

       head = head->next;

       free(ptr);

      //cazul 2 daca nu este capul listei
     } else {

      Node *c = head;

      while(c->next->data != delNode) c = c->next;

      ptr = c->next;

      c->next = ptr->next;

      free( ptr );
     }
}

int main(int argc, char const *argv[]) {

   struct ExecutionTimer timer;

   initTimer(&timer, 0);

    int arr[] = { 9,8,7,15,88,123,-20,11 };
    //MAXINT = 10000000000
    //capul listei HEAD
    //      15 7 8 9
    //                        -1
  //       node1(info=9,next) node2(info=8,next)...nodeN(info=11, next=NULL)
  //
    int i;

    int n = sizeof(arr)/sizeof(arr[0]);

    for( i = 0; i < n; ++i ) {

         addToSinglyLinkedList( arr[i] );
    }

    displayLinkedList( head );

    //addAfterNode(88,-88);

    //displayLinkedList( head ); //al doilea caz in interiorul listei

    //addBeforeNode(11,-88);

    //displayLinkedList( head );//primul caz

    printf("\n");

    //head = reverse(head);

    //displayLinkedList( head );

    removeNode( 123 );

    displayLinkedList( head );

    removeNode( 11 );

    displayLinkedList( head );

   //free(head);

///1 2 3 43 4 5 6 7

//free(node)

    printExecutionTime(&timer);

    return 0;
}
