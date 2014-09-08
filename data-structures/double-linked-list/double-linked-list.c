/**
 *  Implementation Doubly Linked List in C by Adrian Statescu <http://thinkphp.ro> <mergesortv@gmail.com>
 */
#include <stdio.h>
#include <malloc.h>

struct Node {
       int info;
       struct Node *next;  
       struct Node *prev;  
};

struct Node *first = NULL, 
            *last = NULL;

//function prototypes
void myMenu();
void add(int);
void list_from_left();
void list_from_right();
void add_after(int,int);
void add_before(int,int);
void delete(int);

//main function
int main() {

    myMenu();

    return(0);
};

//explicit functions
void myMenu() {
 
     int choice, i, num_nodes, val, what;

     for(;;) {

             printf("\n-----\nMenu\n------\n");
             printf("1. Insert to List\n");
             printf("2. list from left to right\n");
             printf("3. list from right to left\n");
             printf("4. insert after\n");
             printf("5. insert before\n");
             printf("7. removal\n");
             printf("8. EXIT");
 
             printf("\nSelect:");
             scanf("%d",&choice);  

             switch(choice) {

                    case 1:
                    printf("How many nodes do you want?");
                    scanf("%d", &num_nodes);

                    for(i = 1; i <= num_nodes; i++) {

                        printf("Node=");
                        scanf("%d",&val);
                        add( val ); 
                    }
  
                    
                    break;

                    case 2:
                    printf("\n\n\nOutput ->\n");
                    list_from_left();
                    break;

                    case 3:

                    printf("\n\n\nOutput ->\n");
                    list_from_right();
                    break;

                    case 4:

                    printf("\n\n\nOutput ->\n");
                        printf("Afte which one=");
                        scanf("%d",&what);
                        printf("val=");
                        scanf("%d",&val);
                    add_after(what,val);
                    break;

                    case 5:
                    printf("\n\n\nOutput ->\n");
                        printf("Before which one=");
                        scanf("%d",&what);
                        printf("val=");
                        scanf("%d",&val);
                    add_before(what,val);
                    break;

                    case 7:
                    printf("\n\n\nOutput ->\n");
                        printf("Remove node=");
                        scanf("%d",&what);
                    delete( what );
                    break;

                    case 8:
                    exit(0);

                    default:
                    printf("Wrong Number");

             }
     }
}

void add(int val) {

     struct Node *c;

     if(first == NULL) {

        c = (struct Node *)malloc(sizeof(struct Node));
        c->info = val; 
        c->next = c->prev = NULL;
        last = first = c;
        printf("Added to list\n");

     } else {
        printf("Added to list\n");
        c = (struct Node *)malloc(sizeof(struct Node));
        c->info = val;
        c->next = NULL;
        c->prev = last;
        last->next = c;
        last = c;
     }
};

void list_from_left() {

     struct Node *c;

     c = first;  
     while( c ) {
            printf("%d ",c->info);
            c = c->next; 
     }
};


void list_from_right() {

     struct Node *c;

     c = last;  
     while( c ) {
            printf("%d ",c->info);
            c = c->prev; 
     }
};

void add_after(int node, int val) {

     struct Node *c,*newnode;

     if(last->info == node) {

        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->info = val; 
        newnode->next = NULL;
        newnode->prev = last;
        last->next = newnode;
        last = newnode;

     } else { 

        c = first;
 
        while(c->info != node) c = c->next;

        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->info = val; 
        newnode->next = c->next;
        newnode->prev = c;
        c->next->prev = newnode;
        c->next = newnode;
     }
};

void add_before(int node,int val) {

        struct Node *c,*newnode;

        if(first->info == node) {

        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->info = val; 
        newnode->next = first;
        newnode->prev = NULL;
        first->prev = newnode;
        first = newnode;             

        } else {

          c = first;
 
          while(c->next->info != node) c = c->next;

               newnode = (struct Node *)malloc(sizeof(struct Node));
               newnode->info = val; 
               newnode->next = c->next;
               newnode->prev = c;
               c->next->prev = newnode;
               c->next = newnode;               
        }  
 
};

void delete(int node) {

     struct Node *c,*newnode,*removal;

     if(first->info == node) {

        removal = first;
        first = first->next;
        first->prev = NULL;

        free( removal );    

     } else if(last->info == node) {

        removal = last;
        last = last->prev;
        last->next = NULL;

        free( removal ); 

     } else {

        c = first;

        while(c->info != node) c = c->next;
        
        c->prev->next = c->next;
        c->next->prev = c->prev;           
         
        free(c); 
     }
 

};

