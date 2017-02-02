#include <stdio.h>
#include <malloc.h>

typedef struct queue {
        int data;
        struct queue *link;
} Queue;


Queue *Front, 
      *Rear;


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

           if(c == NULL) return;
  
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
int size() {}


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


int main() {

    push(&Rear,1); 
    push(&Rear,2);
    push(&Rear,3);
    push(&Rear,4);
    push(&Rear,5);   
    push(&Rear,6);   
    push(&Rear,7);   
/*
    displayQueue(Front);
    pop();
    pop();
    pop();
    pop();
    displayQueue(Front);
    printf("Front -> %d\n",front());
    printf("Rear -> %d\n",back());
*/
    while(!isEmpty(Front)) {
         printf("%d ", Front->data);
         pop();
    }


}