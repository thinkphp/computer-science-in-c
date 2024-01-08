#include <iostream>
using namespace std;
struct Node {
  int data;
  struct Node *next;
};

void CreateList(struct Node*&head) {
     int nr,
         val;
     cout<<"Number Of Nodes = ";
     cin>>nr;          
  while(nr--) {

     if(head == NULL) {
       cout<<"node = ";
       cin>>val;
       head = new Node;
       head->data = val;
       head->next = NULL;
     } else {
       struct Node *last,*c;
       cout<<"node = ";
       cin>>val;
       last = head;
       while(last->next) last = last->next;
       c = new Node;
       c->data = val;
       c->next = NULL;
       last->next = c;
     }
   }
}

void DisplayList(Node *c) {
  while(c) {
    printf("%d ", c->data);
    c = c->next;
  }
};

int main(int argc, char const *argv[]) {
  struct Node *head = NULL;
  CreateList(head);
  DisplayList(head);
  return 0;
}
