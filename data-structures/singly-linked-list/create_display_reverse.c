#include <stdio.h>
#include <malloc.h>

struct Node {
	int val;
	struct Node *next;
};

void add(struct Node**head,int info) {
	 
	 	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	 	node->val = info;

	 	if(node == NULL) {
	 		printf("Error malloc!");
	 		return;
	 	}
	 	
	 	if(*head == NULL) {
	 		(*head) = node;
	 		return;
	 	}

	 	struct Node* curr = (*head);

	 	while(curr->next) {
	 		curr = curr->next;
	 	}

	 	curr->next = node;
	 
}

struct Node* reverse(struct Node *head) {

       struct Node *prev, *next, *curr;

       prev = NULL; 
       curr = head;

       while(curr!=NULL) {
       	next = curr->next;
       	curr->next= prev;
       	prev = curr;
       	curr = next;
       }

       return prev;
}

void printList(struct Node*head) {
	struct Node* curr= head;
	while(curr != NULL){
		printf("%d ", curr->val);
		curr = curr->next;
	}
}

int main()
{
	struct Node *head = (struct Node*) 0;
  
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    add(&head, 4);
    add(&head, 5); 

    printf("Original List: \n");
	printList(head);

	head = reverse(head);
   
    printf("\nReverse List: \n");
    printList(head);

    struct Node *c = head;

    while(c){
    	struct Node *temp = c;
    	c = c->next;
    	free(temp);
    }
    
	return 0;
}
