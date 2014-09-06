#include <stdio.h>
#include <malloc.h>

typedef struct Node {
       int          info;
       struct node *next; 
} node;

struct Node *head = NULL;

struct Node* create();
void display(struct Node*);

int main() {

    head = create();

    display(head);

    return (0); 
}

struct Node* create() {

       int info;
       struct Node *newNode;
    
       printf("Node=");
       scanf("%d", &info);

       if(info!=0) {

            newNode = (struct Node*)malloc(sizeof(struct Node));

            newNode->next = create(); 
            newNode->info = info;
               
          return newNode;

      } else {

          return NULL; 
      }
                   
}

void display(struct Node* head) {

     struct Node *c;

     c = head;

     while(c) {
        printf("%d ",c->info);
        c = c->next;
     }
}