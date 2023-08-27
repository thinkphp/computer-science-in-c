#include <stdio.h>
#include <malloc.h>

typedef struct node {
        char data;
        struct node* link;
} Node;

Node* linkedlist(Node * head, int data) {

      Node *c;
      if(head == NULL) {
         c = (Node*)malloc(sizeof(Node));
         c->data = data;
         c->link = NULL;
         head = c;
      } else {
         c = (Node*)malloc(sizeof(Node));
         c->data = data;
         c->link = head;
         head = c;
      }
      return c;
}

void print(Node*head) {
     while(head) {
       printf("%c ", head->data);
       head = head->link;
     }
}

Node* reverse(Node *head) {
      Node *curr, *prev, *next;
      prev = NULL;
      curr = head;
      while(curr) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
      }
      return prev;
}

int main(int argc, char const *argv[]) {
  Node *head = NULL;
  head = linkedlist(head,'a');
  head = linkedlist(head,'b');
  head = linkedlist(head,'c');
  head = linkedlist(head,'d');
  print(head);
  printf("\n");
  head = reverse(head);
  print(head);
  return 0;
}
