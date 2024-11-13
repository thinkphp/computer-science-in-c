#include <iostream>

using namespace std;

struct Node {

       int data;
       struct Node *next;

       Node(int v):data(v),next(nullptr){};
};

void push(Node **head, int data) {

      Node *new_node = new Node(data);
      new_node->next = (*head);
      (*head) = new_node;
}

void push_back(Node**head, int value) {

      Node *new_node = new Node(value);

      if(!(*head)) {
          (*head) = new_node;
          return;
      }

      Node *last = (*head);

      while(last->next) {
            last = last->next;
      }

      last->next = new_node;

}

void print(Node *head) {

     Node *curr;

     curr = head;

     while( curr ){

       cout<<curr->data<<" ";

       curr = curr->next;
     }
}

void bubble_sort(Node *head) {

     if(!head) return;

     Node *curr,
          *limit_Ptr = nullptr;

     bool swapped;

     do {

        swapped = false;

        curr = head;

        while( curr->next != limit_Ptr ) {

              if( curr->data > curr->next->data ) {

                swap( curr->data, curr->next->data );

                swapped = true;
              }

              curr = curr->next;
        }

        limit_Ptr = curr;

     } while( swapped );
}

int main(int argc, char const *argv[]) {

  Node *head = nullptr;

  /*push(&head, 1);
  push(&head, 2);
  push(&head, -4);
  push(&head, -3);
  push(&head, 100);
  push(&head, 5);*/

  push_back(&head, 1);
  push_back(&head, 2);
  push_back(&head, -4);
  push_back(&head, -3);
  push_back(&head, 100);
  push_back(&head, 5);
  print(head);

  bubble_sort(head);

  cout<<endl;

  print(head);

  return 0;
}
