#include <iostream>
using namespace std;

typedef struct Node {
  int info;
  struct Node* next;
} Node;

Node *head = NULL;

void addToListFront(int value) {

     if(head == NULL) {
       head = new Node;
       head->info = value;
       head->next = NULL;
     } else {
       Node* new_node = new Node;
       new_node->info = value;
       new_node->next = head;
       head = new_node;
     }
}

void addToListBack(int value) {

     if(head == NULL) {
       head = new Node;
       head->info = value;
       head->next = NULL;
     } else {
       Node*c=head;
       //1 2 3 4 5
       while(c->next!=NULL) c = c->next;
       Node* new_node = new Node;
       new_node->info = value;
       c->next = new_node;
     }
}

void display() {
     Node *c = head;
     while(c) {
       cout<<c->info<<" ";
       c = c->next;
     }
}

Node* reverse(Node*head) {

  Node *curr=head, *next=NULL, *prev = NULL;

       while(curr) {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
       }
return prev;
}

int main(int argc, char const *argv[]) {

  addToListBack(1);
  addToListBack(2);
  addToListBack(3);
  addToListBack(4);
  addToListBack(5);
  display();
  head = reverse(head);
  cout<<endl;
  display();

  return 0;
}
