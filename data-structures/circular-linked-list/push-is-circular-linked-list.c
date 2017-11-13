#include <stdio.h>
#include <malloc.h>

typedef struct node {

       int data;
       struct node* next;

} Node;

void push(Node** head, Node** tail, int data) {

     Node* new_node = (Node*)malloc(sizeof(Node));

           new_node->data = data;
           new_node->next = NULL;

           if((*head) == NULL) {
    
               (*head) = new_node;

           } else {

               (*tail)->next = new_node;
           }

           (*tail) = new_node;                      

};

void print(Node*head) {
    
     while(head){

        printf("%d ", head->data);

        head = head->next;  
     }
};

int isCircular(Node*head) {

    Node *curr = head;

    while(curr != NULL) {

          curr = curr->next;

          if(curr == head) {

              return 1;
              break;
          } 
    } 

    return 0;  
};

int main() {

    Node *head = NULL,
         *tail = NULL;

    push(&head,&tail,1); 
    push(&head,&tail,2);
    push(&head,&tail,3);
    push(&head,&tail,4);
    push(&head,&tail,5);
    push(&head,&tail,6);
    push(&head,&tail,7);

    tail->next = head;

    printf("%d\n", isCircular(head));

return(0);
}