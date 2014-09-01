#include <iostream>

using namespace std;

//Stack LIFO - Last In First Out
typedef struct node {
       int    data;
       node *back; 
} Node;

Node *head = NULL;

void push(Node*&,int);
void pop(Node*&);

int main() {

    //push elements onto stack
    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    push(head,5);

    //pop stack
    pop(head);
    pop(head);
    pop(head);
    pop(head);
    pop(head);
    pop(head);

    return 1;
}

void push(Node *&head,int val) {

     Node *p;

     if(head == NULL) {

        head = new Node;
    
        head->data = val;

        cout<<"Added "<<val<<" to Stack"<<endl;

        head->back = NULL;
        
     } else {

        p = new Node;

        p->data = val;

        cout<<"Added "<<val<<" to Stack"<<endl;

        p->back = head;

        head = p;
     }
}

void pop(Node *&head) {

     Node *p;

     if(head == NULL) {

        cout<<"Stack is empty!"<<endl; 

     } else {
        
        p = head;

        cout<<"Pop "<<p->data<<" from stack"<<endl;

        head = head->back;

        delete p;          
     }
}