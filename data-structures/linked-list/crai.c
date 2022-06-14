#include <stdio.h>
#include <malloc.h>
#define MAXINT 500050

/*
   - add(head,value)
   - removeNode(head,key)
   - reverse(head)
   - display(head)
   - insertAfterNode(head,key,value)
   - insertBeforeNode(head,key,value)
   - sort(arr, n)
 */

typedef struct Node {

     int data;
     struct Node *next;

} Node;

Node *head = NULL;

Node *add(Node *head, int val) {

     if(head == NULL) {

        head = (Node *)malloc(sizeof(Node));
        head->data = val;
        head->next = NULL;

     } else {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = val;
        newNode->next = head;
        head = newNode;
     }
   
   return head;
}

Node *removeNode(Node *head, int key) {

      if(head->data == key) {
        Node *ptr = head;
        head = head->next;
        free(ptr);
      } else {
        Node *c = head;
        while(c->next->data != key) c = c->next;
        Node *ptr = c->next;
        c->next = ptr->next;
        free(ptr);
      }

      return head;
}

Node* reverse(Node*head) {

      Node *next = NULL, *prev = NULL;
      Node *curr = head;

      while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }

      return prev;
}

void display(Node *head) {

     Node *c = head;
     while(c) {
       printf("%d ", c->data);
       c = c->next;
     }
     printf("\n");
}

Node *insertAfterNode(Node *head, int key, int value) {

      Node *c = head;

      while(c->data != key) {
        c = c->next;
      }

      Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->data = value;
            newNode->next = c->next;
            c->next = newNode;

      return head;
}

Node *insertBeforeNode(Node *head, int key, int value) {

      if( head->data == key ) {

          Node *newNode = (Node*)malloc(sizeof(Node));
                newNode->data = value;
                newNode->next = head;
                head = newNode;
      } else {

          Node *c = head;

          while(c->next->data != key) c = c->next;

          Node *newNode = (Node*)malloc(sizeof(Node));
                newNode->data = value;
                newNode->next = c->next;
                c->next = newNode;
      }

      return head;
}

void sort(int arr[], int n) {

      Node *head;
      //int n = sizeof(arr) / sizeof(arr[0]);

      head = (Node*)malloc(sizeof(Node));
      head->data = MAXINT;
      head->next = NULL;

      for(int i = 0; i < n; ++i) {

             Node *newNode = (Node*)malloc(sizeof(Node));
             newNode->data = arr[i];

            if(newNode->data < head->data) {

               newNode->next = head;
               head = newNode;

            } else {

              Node *c, *c2;

              c = head;
              c2 = head->next;

              while(newNode->data > c2->data) {
                   c = c->next;
                   c2 = c2->next;
              }
              c->next = newNode;
              newNode->next = c2;
            }

      }

      Node *c = head;

      while(c->data != MAXINT) {
        printf("%d ", c->data);
        c = c->next;
      }
}

int main(int argc, char const *argv[]) {
  
  int val, key;

  printf("val = ");
  scanf("%d", &val);

  while(val) {

    head = add(head, val);

    printf("val = ");
    
    scanf("%d", &val);
  }

  display(head);

  printf("key del = ");
  scanf("%d", &key);
  head = removeNode(head, key);

  display(head);

  head = reverse( head );

  display(head);

  printf("insert beforekey = ");
  scanf("%d", &key);
  head = insertBeforeNode(head, key, 7777);
  display(head);

  printf("insert afterkey = ");
  scanf("%d", &key);
  head = insertAfterNode(head, key, 8888);
  display(head);

  int arr[] = {8,7,6,5,4,3,2,1,0},
      n = sizeof(arr) / sizeof(arr[0]);

  sort(arr, n);

  return 0;
}
