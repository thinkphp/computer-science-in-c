/**
 *  Adrian Statescu <http://adrianstatescu.com> - <mergesortv@gmail.com> - <http://thinkphp.ro>
 *
 *  Demystifying the Singly Linked List for C Developers.
 *
 *  - create
 *  - display
 *  - reverse
 *  - addBefore
 *  - addAfter
 *  - removeNode
 *  - sort
 */

#include <stdio.h>
#include <malloc.h>

typedef struct node {

        int data;
        struct node *next;
} Node;

Node *head = NULL;

void displaySinglyLinkedList( Node* head ) {
  
     Node *c = (head);

     while(c) {

        printf("%d ", c->data);

        c = c->next; 
     }

     printf("\n");
};

void addToSinglyLinkedList(int val) {

     if(head == NULL) {

        Node *new_node = (Node*)malloc(sizeof(Node));
              new_node->data = val;
              new_node->next = NULL;
              head = new_node;
     } else {

        Node *new_node = (Node*)malloc(sizeof(Node));
              new_node->data = val;
              new_node->next = head;
              head = new_node;          
     }
};

void removeNode(int delval) {

     Node *ptr;

     if(head->data == delval) {

        ptr = head;
 
        head = head->next;

        free(ptr);

     } else {

        Node* c = head;

        while(c->next->data != delval) c = c->next;

        ptr = c->next;

        c->next = ptr->next;

        free(ptr);
     } 
};

Node* reverse(Node *head) {

     Node* curr = head,
           *prev = NULL, 
           *next;
      
     while(curr) {

           next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;  
     }

     return prev;
};

void addAfterNode(int afternode,int val) {

     Node *c = head;

           while(c->data != afternode) c = c->next;

           Node*new_node = (Node*)malloc(sizeof(Node));

                new_node->data = val;
                new_node->next = c->next;
                c->next = new_node;
};

void addBeforeNode(int beforenode,int valnode) {

     //we have 2 cases; one is before head and the two is after head
     Node *c, 
          *new_node;
           new_node = (Node*)malloc(sizeof(Node));

     if(head->data == beforenode) {

        new_node->data = valnode;
        new_node->next = head;
        head = new_node;
   
     } else {
        c = head;
        while(c->next->data != beforenode) c = c->next;

        new_node->data = valnode;
        new_node->next = c->next;
        c->next = new_node;  
 
     }
     
};

void sort() {

     Node *c = head;

     int arr[20], i, n, k = 0;

    while(c) {

           arr[k] = c->data; 

           c = c->next;

           k++;
     }
     

     int maxint = 32000;

     Node *base = (Node*)malloc(sizeof(Node));
                 
           base->data = maxint;

           base->next = NULL;  
  
     for(i = 0; i < k; ++i) {

         Node *p = (Node*)malloc(sizeof(Node));
               p->data = arr[i];

         if(base->data > p->data) {

                  p->next = base;
                  base = p;  

         }  else {
          
             Node *p1 = base,
                  *p2 = p1->next;

                  while(p1 != NULL && p2->data < p->data) p1 = p1->next, p2 = p2->next;
                  p1->next = p;
                  p->next = p2; 
         }         
     }

     Node *r = base;

     while(r != NULL && r->data != maxint) {

           printf("%d < ", r->data); r = r->next; 
     }           
};

int main() {

    int i, //this represents an iterator for loop
        arr[] = {9,8,7,6,25,4,3,23,-11,0},  // the main array
        n = sizeof(arr)/sizeof(arr[0]); // the length of the array
     
    for(i = 0; i < n; ++i) {

        addToSinglyLinkedList( arr[ i ] );
    }

    displaySinglyLinkedList( head );

    int delval;
    printf("Remove Node = "); 
    scanf("%d", &delval);
    removeNode( delval );

    displaySinglyLinkedList( head );

     
    head = reverse(head); 

    printf("Revese Singly Linked List:\n");

    displaySinglyLinkedList( head );

    printf("After node; what value = ");
    int afternode, val;
    scanf("%d %d", &afternode, &val);
    addAfterNode(afternode, val);   

    displaySinglyLinkedList( head );


    printf("Insert before node; what value = ");
    int beforenode;
    scanf("%d %d", &beforenode, &val);
    addBeforeNode(beforenode, val);   

    displaySinglyLinkedList( head );
 
    sort();

 return(0);
};