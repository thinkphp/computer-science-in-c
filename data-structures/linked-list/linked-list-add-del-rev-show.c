#include <stdio.h>
#include <malloc.h>

typedef struct Node {
        int data;
        struct Node *next;
} Node;

Node *head = NULL;

Node* add(Node*head, int value) {

      if(head == NULL) {
         head = (Node*)malloc(sizeof(Node));
         head->data = value;
         head->next = NULL;
      } else {
        Node *c = (Node*)malloc(sizeof(Node));
        c->data = value;
        c->next = head;
        head = c;
      }

    return head;
}

Node* delete(Node *head , int key) {

      if(head->data == key) {

         Node *ptr;
         ptr = head;
         head = head->next;
         free(ptr);

      } else {
        Node *c = head;
        while(c->next->data != key) c = c->next;
        Node *ptr;
        ptr = c->next;
        c->next = ptr->next;
        free(ptr);
      }
      return head;
}

Node *reverse(Node *head) {

      Node *curr = head, *prev = NULL,
                         *next = NULL;

      while(curr) {

          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
      }
   return prev;
}

void display(Node*head) {
    Node *c = head;
    while(c) {
      printf("%d ", c->data);
      c = c->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {

    int val;


    printf("%s", "Value=");
    scanf("%d", &val);

    while(val) {

      head = add(head, val);
      printf("%s", "Value=");
      scanf("%d", &val);
    }

    display(head);
    int key;
    printf("%s", "Del Value=");
    scanf("%d", &key);

    head = delete(head, key);
    display(head);

    head = reverse(head);
    display(head);
  return 0;
}
