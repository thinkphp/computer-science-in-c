/*
    Singly Linked List Data Structure

 - addAtBeginning(head, key)
 - addAtEnd(head, key)
 - removeNode(head, key)
 - display(head)
 - insertAfterNode(key, value)
 - insertBeforeNode(key, value)
 - search(head, key)
 - reverse(head)

*/
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

int searchNode(Node*head,int key) {
    Node *c = head;

    while(c) {
          if(c->data == key) return 1;
          c = c->next;
    }

    return 0;
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

     cout<<("\n");
}

Node* insertAfterNode(Node* head,  int key, int value) {

      Node *c = head;

      while(c->data != key) c = c->next;

      Node *node;
      node = new Node();
      node->data = value;
      node->next = c->next;
      c->next = node;

      return node;
};

Node* insertBeforeNode(Node *&head, int key, int val ) {

      if(head->data == key) {

         Node *c = new Node();
               c->data = val;
               c->next = head->next;
               head = c;
      } else {
        Node *ptr = head;
        while(ptr->next->data != key) ptr = ptr->next;
        Node *c = new Node();
        c->data = val;
        c->next = ptr->next;
        ptr->next = c;
      }

      return head;
};

Node* removeNode(Node *head, int key ) {

      Node *c;

      //if the node to delete is even header
      if(head->data == key)
      {
         c = head;
         head = c->next;
         delete c;

      } else {

        c = head;

        Node *ptr;

        while(c->next->data != key) c = c->next;

        ptr = c->next;

        c->next = ptr->next;

        delete ptr;
      }

      return head;
};

int main(int argc, char const *argv[]) {

  cout<<"value = ";
  cin>>val;

  while(val) {
    add_at_end(head, val);
    cout<<"value = ";
    cin>>val;
  }

  display( head );

  int del;
  cout<<"del=";
  cin>>del;

  head = removeNode( head, del );

  display( head );

  int node = 9;
  insertAfterNode(head, node, 7777);
  display( head );

  int node2 = 66;
  insertBeforeNode(head, node2, -7777);
  display( head );

  int s = searchNode(head, 5);
  cout<<"Search: "<<s;
  return 0;
}
