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

void bubblesort() {
     Node *ptr;
     bool swapped = false, finished = false;
     Node *last = NULL;

     while(!finished) {
           swapped = false;
           ptr = head;
           while(ptr->next != last) {
                 if(ptr->info > ptr->next->info) {
                        int tmp;
                        tmp = ptr->info;
                        ptr->info = ptr->next->info;
                        ptr->next->info = tmp;
                        swapped = true;
                 }
                 ptr = ptr->next;
           }

           if(swapped)last = ptr;
           else finished = true;
     }
}

//----------------------------------
//----------------------------------
//----------------------------------
Node* searchNode(int value) {
      Node *ptr = head;
      while(ptr!=NULL) {
            if(ptr->info == value) return ptr;
            ptr = ptr->next;
      }
      return NULL;
}
//----------------------------------
//----------------------------------
//----------------------------------

void removeNode( int val ) {
    if(searchNode(val)==NULL) {cout<<"Not Found";return;}
      if(head->info == val) {
        Node*ptr = head;
        head = head->next;
        free(ptr);
        cout<<"\ndeleted!";
      }  else {
        Node *c = head;
        while(c->next->info!=val) c = c->next;
        Node*ptr = c->next;
        c->next = ptr->next;
        free(ptr);
        cout<<"\ndeleted!";
      }
}

int main(int argc, char const *argv[]) {

  addToListBack(10);
  addToListBack(12);
  addToListBack(-3);
  addToListBack(34);
  addToListBack(1);
  addToListBack(51);
  display();
  //head = reverse(head);
  cout<<endl;
  //display();
  cout<<endl;
  //bubblesort();
  //display();

  int node_remove;
  cout<<"Give a node to remove: ";
  cin>>node_remove;
  removeNode(node_remove);
  display();

  //int node_search;
  //cout<<"Give a node to search: ";cin>>node_search;
  //if(searchNode(node_search)!=NULL) cout<<"Found!";
    //        else
      //                               cout<<"Not Found!";

  return 0;
}
