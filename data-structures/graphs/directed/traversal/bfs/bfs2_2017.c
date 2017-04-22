#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#define SIZE 1000
#define FIN "graph_adjacency.in"

int nodes, 
    edges, 
    visited[ SIZE ], 
    a, b;

typedef struct queue {
        int data;
        struct queue *link;
} Queue;


Queue *Front, 
      *Rear;

struct Node {

        int info;
        struct Node *next; 

} *L[ SIZE ];


//inserts a new element at the end of the queue, after its current last element. 
//the content of the new element is initialized to val.
void push(Queue**rear,int data)
{

     if((*rear) == NULL) {

                (*rear) = (Queue*)malloc(sizeof(Queue)); 
                (*rear)->data = data;
                (*rear)->link = NULL;
                 Front = (*rear);

     } else {

                Queue *temp = (Queue*)malloc(sizeof(Queue)); 
                temp->data = data;
                temp->link = NULL;
                (*rear)->link = temp;
                (*rear) = temp;
     }
};

//removes the next element in the queue, effectively reducing its size by one.
int pop() {

    Queue *c = Front;

           if(c == NULL) return 0;
  
           if(c->link != NULL) {

               Front = Front->link;
  
               free(c);     

           } else {

             Rear = Front = NULL;

             free(Front);

           }
}


//returns a reference to the next element in the queue.
int front() {

    Queue *c = Front;

    if(c) return c->data;
}


//returns a reference to the last element in the queue. This is the last
//element pushed into the queue. I mean newest element in the queue.
int back() {

    Queue *c = Rear;
    if(c)  return c->data;
}



//returns the number of elements in the queue.
void displayQueue(Queue *front) {

    Queue *c = front;

    while( c ) {

          printf("%d ", c->data); 

          c = c->link;
    } 
     
    printf("\n");
}

int isEmpty(Queue*queue) {

    if((queue) == NULL) return 1;

           else return 0;
}


void breadth_first_search_in_action(int node) {

     int visited[SIZE];

     push(&Rear, node);
 
     memset(visited, 0, sizeof(visited));

     visited[ node ] = 1; 

     while(!isEmpty(Front)) {

           int theNode = front();

           printf("%d ", theNode);

           struct Node *c = L[theNode]; 

               while( c ) {

                     if(!visited[c->info]) {     
                     
                         push(&Rear, c->info);

                         visited[c->info] = 1;
                     }

                     c = c->next;
                 }

           pop();
     } 
}

int main() {

 struct Node* node;

 freopen(FIN, "r", stdin);
  
 scanf("%d %d", &nodes, &edges);

 while(edges--) {

       scanf("%d %d", &a, &b);       

       node = (struct Node*)malloc(sizeof( struct Node ));

       node->info = b;

       node->next = L[a];

       L[a] = node;   
 }

 breadth_first_search_in_action( 1 );

 return(0);
}