#include <stdio.h>
#include <malloc.h>

struct Node {
       int data;
       struct Node *next;
};

void push(struct Node** head, int data) {

     struct Node *node = (struct Node*)malloc(sizeof(struct Node));
                  node->data = data;
                  node->next = (*head);
                  (*head) = node;  
};

void displayList(struct Node *head) {

     struct Node *c = (head);

     while(c) {
        printf("%d ", c->data);
        c = c->next; 
     }
     printf("\n");
};


void sortedList(struct Node **head) {

     struct Node *ptr = (*head), *start = NULL;
     int arr[10000], index = 0, i, j, n = 0;

     while(ptr) {

           arr[index++] = ptr->data;
           ptr = ptr->next;
           n++;
     }

         for(i = 0; i < n - 1; i++) 

         for(j = 0; j < n - i - 1; j++)
          
             if(arr[j] > arr[j+1]) {

                  int temp = arr[j];

                      arr[j] = arr[j+1];

                      arr[j+1] = temp;  
             }

         struct Node *nextnode;

         for(index = 0; index < n; index++){

                  struct Node *gnode = (struct Node*)malloc(sizeof(struct Node));
                         gnode->data = arr[index];
                         gnode->next = NULL;    
 
             if(start == NULL) {

                start = gnode; 
                nextnode = gnode;

             }  else {

                nextnode->next = gnode;
                nextnode = gnode;
             }
                
         }

   
        *head = start;   
};

int main() {

    int i,
        n,
        x;

    struct Node *head = NULL;

    scanf("%d",&n);

    for(i = 0; i < n; i++) {

        scanf("%d", &x);

        push(&head,x);
    }

    displayList(head);
    sortedList(&head);
    displayList(head);

return(0);
}