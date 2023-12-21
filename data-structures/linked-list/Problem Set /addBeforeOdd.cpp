#include <iostream>

using namespace std;

struct Node {

  int data;
  struct Node *next;

};

void createList(struct Node*&head) {

     int nr,node;
     cin>>nr;
     while(nr--){
       cout<<"node=";
       cin>>node;
       struct Node*p = new Node;
       p->data = node;
       p->next = head;
       head = p;
     }
}

void insert( struct Node*&head ) {
  struct Node*c,*q;
  c = head;

     if(c->data&1) {
       struct Node*c = new Node;
       c->data = head->data * head->data;
       c->next = head;
       head = c;
     }

     while(c->next != NULL ) {

         if(c->next->data & 1) {

          q = new Node;
          q->data = c->next->data * c->next->data;
          q->next = c->next;
          c->next = q;
          c = q->next;

        } else

           c = c->next;
       }
}

void display(struct Node *head) {

  while(head) {
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {

  struct Node* head = NULL;

  createList(head);
  display(head);
  insert(head);
  display(head);

  return 0;
}
