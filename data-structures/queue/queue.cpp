#include <iostream>

using namespace std;

typedef struct node {
 
       int data;
       node *next;
         
} Node;

Node *front, *end;

void push(Node*&,Node*&,int);
void pop(Node*&);

int main() {

    push(front,end,1);
    push(front,end,2);
    push(front,end,3);
    pop(front);
    pop(front);
    pop(front);
    pop(front);
}

void push(Node *&front,Node *&end,int val) {

     Node *c;

     if(front == NULL) {

        front = new Node;
        front->data = val;
        cout<<"Added to Queue "<<val<<endl;
        front->next = NULL;
        end = front;    

     } else {

        c = new Node;
        end->next = c;
        c->data = val;
        cout<<"Added to Queue "<<val<<endl;
        c->next = NULL;
        end = c;    

     }      
}

void pop(Node *&front) {

     Node *c; 

     if(front == NULL) {

        cout<<"Queue is empty";

     } else {

        c = front;
        cout<<"Pop from Queue "<<c->data<<endl;
        front = front->next;

        delete c;        
     }
}
