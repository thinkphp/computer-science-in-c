#include <iostream>

using namespace std;

class Node {
   public:
     int data;
     Node *next;
     Node *prev;
     //constructor of the class
     Node(int info) {
       data = info;
       next = NULL;
       prev = NULL;
     }
};

class Queue {
   public:
     Node *tail;
     Node *head;
     int size = 0;

   void enqueue(int data) {
        Node *node = new Node(data);
        cout<<"Enqueue: "<<data<<endl;
        if(size == 0) {
           tail = node;
           head = node;
        } else {
          tail->prev = node;
          node->next = tail;
          tail = node;
        }
        size++;
   }

   int dequeue() {
         if(size == 0) {
           return 0;
         } else {
           int data = head->data;
           head = head->prev;
           size--;
           return data;
         }
   }

   int getSize() {

        return size;
   }

   int peek(void) {
     if(head != NULL) {
        return head->data;
     }
   };

};

int main(int argc, char const *argv[]) {
  Queue q = Queue();
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  cout<<"Size: "<<q.getSize()<<endl;
  cout<<"Dequeue(): "<<q.dequeue()<<endl;
  cout<<"peek -> "<<q.peek()<<endl;
  cout<<"Size: "<<q.getSize()<<endl;
  return 0;
};
