#include <iostream>

using namespace std;

typedef struct Node {
       int data;
       struct Node *next;
} Node;

Node *head= NULL;
int val;

Node* add(Node *&head, int value) {

     if(head == NULL) {
       head = new Node;
       head->data = value;
       head->next = NULL;
     } else {
       Node *c = new Node;
       c->data = value;
       c->next= head;
       head = c;
     }

     return head;
}

Node* add_at_end(Node *&head, int value) {

     if(head == NULL) {
       head = new Node;
       head->data = value;
       head->next = NULL;
     } else {
       Node *c = new Node;
             c->data = value;
             c->next = NULL;
       Node *curr = head;
       while(curr->next) curr = curr->next;
       curr->next= c;
     }

     return head;
}

void display(Node *head) {
     Node *curr = head;
     while(curr) {
         cout<<curr->data<<" ";
         curr = curr->next;
     }
}

int main(int argc, char const *argv[]) {

  cout<<"value = ";
  cin>>val;

  while(val) {
    add_at_end(head, val);
    cout<<"value = ";
    cin>>val;
  }

  display(head);

  return 0;
}
