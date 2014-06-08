#include <stdio.h>
#include <malloc.h>

struct Node {
       int info;
       struct Node *next;
};

struct Node *curr, *head = NULL;

//number of nodes
int n;

void create();
void display();
void bubblesort();
void selectionbymin();

int main() {

     int i;

     printf("n=");
     scanf("%d", &n);

     for(i = 1; i <= n ;i++) {

         create();
     }     

     display();

     //bubblesort();
     selectionbymin();

     display();

    return (0);
}

void create() {

         int val;
         curr = (struct Node*)malloc(sizeof(struct Node));
         printf("info=");
         scanf("%d",&val);
         curr->info = val;
         curr->next = head;
         head = curr;          
}

void display() {

     struct Node *p = head;

     while( p ) {

            printf("%d ",p->info);

            p = p->next;
     }
 
     printf("\n");
}

void bubblesort() {

    struct Node *p = head;

    int xor, 
        swapped;
 

    swapped = 0;

    do {

       swapped = 0;

       p = head; 

       while(p->next) {

             if(p->info > p->next->info) {
 
                xor = p->info ^ p->next->info;

                p->info = xor ^ p->info;

                p->next->info = xor ^ p->next->info;

                swapped = 1;  
             }

             p = p->next;
       }  

    }while(swapped);
}

void selectionbymin() {

     int min;

     struct Node *p = head, *minNode = NULL, *first;
        

     while( p ) {
         
         first = p;

         curr = first->next; 

         min = first->info;

         minNode = first;
   
         while( curr ) {

               if(curr->info < min) {

                  min = curr->info;
                  minNode = curr;
               }
               
               curr = curr->next; 
         }
         
         minNode->info = first->info;

         first->info = min;
           
                            
         p = p->next;          
     }
} 