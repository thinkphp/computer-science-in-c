#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int value):data(value), next(nullptr){};
};

void push(Node ** head, int data) {

    Node *new_node = new Node(data);

    new_node->next = (*head);
    (*head) = new_node;

}


void push_back(Node ** head, int data) {

    Node *new_node = new Node(data);

    if(!(*head)) {
      (*head)=new_node;
      return;
    }
    Node* last = (*head);
    while(last->next) {
      last = last->next;
    }


    last->next = new_node;
}


void print(Node*head){
  Node *curr = head;
  while(curr){
    cout<<curr->data<<" ";
    curr = curr->next;
  }
  cout<<endl;
}

void selecttion_by_min(Node *head) {
    Node *nextNode,
         *minNode,
         *curr = head;

    while(curr) {

      minNode = curr;
      nextNode = curr->next;

      while(nextNode) {

         if(nextNode->data < minNode->data) {
             minNode = nextNode;
         }
         nextNode = nextNode->next;
      }

      if(minNode != curr) {
        swap(minNode->data, curr->data);
      }
      curr = curr->next;
    }

}

int main(int argc, char const *argv[]) {
  Node *head = nullptr;

  push_back(&head, 1);
  push_back(&head, 5);
  push_back(&head, 2);
  push_back(&head, -1);
  push_back(&head, 4);

  print(head);

  //selecttion_by_min(head);
  print(head);
  return 0;
}
