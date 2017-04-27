#include <stdio.h>
#include <malloc.h>

typedef struct node {

       int data;
       struct node* next,
                  * prev;   
} Node;

void push(Node**head, int data) {

     //dynamic allocation for a new node
     Node *temp = (Node*)malloc(sizeof(Node));

           //put in data
           temp->data = data;

           //update next area
           temp->next = (*head);

           //update prev area
           temp->prev = NULL;

           if((*head) != NULL) (*head)->prev = temp;

           //move the head here  
           (*head) = temp;  
};

void print(Node *head) {

      while(head != NULL) {

            printf("%d ", head->data);

            head = head->next; 
      }
      printf("\n");
};


void printR(Node *head) {

      Node*last;

      while(head != NULL) {

            last = head;

            head = head->next;             
      }
    
      while(last != NULL) {

            printf("%d ",last->data);

            last = last->prev;             
      }

};

void addNode(Node **head, int pos, int data) {

     Node *new_node = (Node*)malloc(sizeof(Node));
           new_node->data = data;

     int k = 0; 
     Node *aux = (*head);
            
           while(k++ < pos) {
                 aux = aux->next;
           } 

           if(aux->next == NULL) {
              aux->next = new_node;
              new_node->next = NULL;
              new_node->prev = aux;
              return;  
           }

           new_node->next = aux->next;
           aux->next->prev = new_node;
           aux->next = new_node;
           new_node->prev = aux;            


};

int main() {

    Node *head = NULL;
    push(&head,1); 
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    push(&head,7);
    print(head);
    addNode(&head,5,171);    
    print(head);
   
return(0);
}