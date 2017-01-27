#include <stdio.h>
#include <malloc.h>

typedef struct Node {

       int data;
        struct Node *next;  
} Node;

Node *head = NULL;

void push(Node** head, int val) {
  
     Node *newNode = (Node*)malloc(sizeof(Node));
           newNode->data = val;
           newNode->next = (*head);         
           (*head) = newNode;
};

void display_list(Node*head) {

     while(head){
         printf("%d ", head->data);
         head = head->next; 
     } 
     printf("\n");
}

void reverse(Node**head) {

     Node*next,*curr = (*head),*prev = NULL;   

     while(curr) {

           next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;            
     }
     *head = prev;
}

int main() {

  int i,
      n,
      item;

  scanf("%d",&n);
  for(i = 0; i < n; i++) {

      scanf("%d",&item);
      push(&head,item);
  }

  display_list(head);
  reverse(&head);
  display_list(head);
    
 return 0;
}