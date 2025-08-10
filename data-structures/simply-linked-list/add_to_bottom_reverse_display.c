#include <stdio.h>
#include <malloc.h>

struct Node {
	int info;
	struct Node*next;
};

void add_to_bottom(struct Node**head, int val) {
 
     struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 

     if(newNode == NULL) {
     	printf("Error: Allocation Memory HEAP");
     	return;
     }


                  newNode->info = val; 

     if(*head == NULL) {
     	*head = newNode;
     	return;
     }         

     struct Node* curr = (*head);          

     while(curr->next!=NULL) {

           curr = curr->next; 
     }
     curr->next = newNode;

}

void add(struct Node**head, int val) {

        struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));  

        if(newNode == NULL) {
        	printf("Error Allocation HEAP");
        	return;
        }

        newNode->info = val;
        newNode->next = (*head);
        (*head) = newNode;
}

struct Node* reverse(struct Node* head) {
       struct Node *curr, *next, *prev; 

       curr = head;
       prev = NULL;

       while(curr != NULL) {
       	     next = curr->next;
       	     curr->next = prev;
       	     prev = curr;
       	     curr = next;
       }

       return prev;
}

void printLinkedList(struct Node*head) {
     while(head) {
     	printf("%d ", head->info);
     	head = head->next;
     } 

     printf("\n");
}

int main(int argc, char const *argv[])
{

	struct Node *head = (struct Node*)0;

	add_to_bottom(&head,1);
	add_to_bottom(&head,2);
	add_to_bottom(&head,3);
	add_to_bottom(&head,4);
	add_to_bottom(&head,5);

    printf("Original: \n");
	printLinkedList(head);

	head = reverse(head);

    printf("Reverse: \n");
	printLinkedList(head);
	
	return 0;
}
