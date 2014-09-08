#include <stdio.h>
#include <malloc.h>

struct Node {

       int         info;
       struct Node *next; 
};

struct Node *first=NULL, *last=NULL;

void menu();
void add_to_list(int);
void list();
void deleteLast();

int main() {
 
    menu();

    return(0); 
}

void menu() {

     int choice, num_nodes, val, i;

     while(1) {     

             printf("\n-----\nMenu\n-----\n");
             printf("1. Create\n");
             printf("2. List\n");
             printf("3. Delete last\n");
             printf("5. EXIT");
             
             printf("\nSELECT:");
             scanf("%d",&choice); 

             switch( choice ) {

                    case 1:
                    printf("How many nodes do you want?");
                    scanf("%d",&num_nodes);

                    for(i=1;i<=num_nodes;i++) {
                        printf("Node=");
                        scanf("%d",&val);
                        add_to_list(val);
                    } 
 
                    break;

                    case 2:
                    list();
                    break;

                    case 3:
                    deleteLast();
                    break;

                    case 5:
                    exit(0);

                    default:
                    printf("Wrog number");
             }
     }

}

void add_to_list(int val) {

     struct Node *c;

     if(first==NULL) {
 
        first = (struct Node*)malloc(sizeof(struct Node));        
        first->info = val;
        first->next = last;
        last = first; 

     } else {

        c = (struct Node*)malloc(sizeof(struct Node));
        c->info = val;
        last->next = c;
        last = c;
        last->next = first;  
     }  
 
};

void list() {

     struct Node *c = last;

     printf("%d ",c->info);
 
     for(c = last->next; c != last; c = c->next) 

         printf("%d ", c->info);
};

void deleteLast() {

     struct Node *c, *q;

     c = first;

     while(c->next != last) c = c->next;

     q = c->next;
     c->next = q->next;
     last = c;
 
     free(q);          

};
