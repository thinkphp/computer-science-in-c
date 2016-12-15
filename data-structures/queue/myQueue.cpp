/*
 * Adrian Statescu
 * Implement a Queue based on Linked List;
 * MIT License
 */
#include <iostream>

using namespace std;

typedef struct QueueNode {
       int data;
       struct QueueNode *next;  
} QNode;

class Queue {

      private:
      QNode *front = NULL, 
            *rear = NULL;

      public: 
      void push(int val){

           QNode *temp = new QNode;
                  temp->data = val;
                  temp->next = NULL;

           if(front == NULL) {

                 front = temp;
                 rear = front; 

           } else {
                 rear->next = temp;
                 rear = temp; 
           } 
      };

      int pop(){

           if(front == NULL) return -1;

           else {

                int val;
                QNode *temp; 
                       temp = front;
                       val = front->data;
                       front = front->next;
                       delete temp; 
                       if(front == NULL) {
                          front = rear = NULL;
                       }
                       return val;
           }             
      };

      int getFront() {

          if(!isEmpty()) return front->data;
      };
     
      int isEmpty(){

          if(front == NULL) return 1;
                   else 
                            return 0;
      }

        
};

int main() {

    Queue *queue = new Queue;
    queue->push(1);
    queue->push(2);
    queue->push(3);
    cout<<queue->getFront(); 

return(0);
}