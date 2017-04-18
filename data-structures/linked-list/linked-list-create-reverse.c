#include <stdio.h>
#include <malloc.h>

struct Node {

       int info;
       struct Node *next; 
};

struct Node* reverse(struct Node *head) {

     struct Node* curr = head,
                * prev = NULL,
                * next;         

     while(curr) {

           next = curr->next;

           curr->next = prev;

           prev = curr;            

           curr = next; 

     }  

     return prev;
}

struct Node* create(struct Node *head, int val) {

       if(head == NULL) {

          struct Node *nod = (struct Node*)malloc(sizeof(struct Node)); 
                 nod->info = val;
                 nod->next = NULL;
                 head = nod;

       } else {

          struct Node *nod = (struct Node*)malloc(sizeof(struct Node)); 
           
                       nod->info = val;

                       nod->next = head;

                       head = nod;  
       }

       return head;         
}


void display(struct Node *head) {

     while(head) {
           printf("%d ", head->info);
            head = head->next;
     }
           printf("\n");
}

int main() {

    struct Node *head = NULL;

    head = create(head,1);     
    head = create(head,2);
    head = create(head,3);
    head = create(head,4);
    head = create(head,5);
    display(head);     
    head = reverse(head);
    display(head);     

 return(0);
}