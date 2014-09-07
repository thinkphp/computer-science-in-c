#include <stdio.h>
#include <malloc.h>

typedef struct Node {

        int info;
        struct Node *next;  
} Node;

Node *start=NULL, *end;

void add_to_list(int);
void print_list();
void add_after_node(int,int);
void add_before_node(int,int);
void remove_node(int);


int main() {

    int i,whatnode,whatval;

    for(i=1;i<=9;i++) 
        add_to_list(i); 
    print_list();

    printf("After what node");
    scanf("%d",&whatnode);
    printf("What val=");
    scanf("%d",&whatval);
    add_after_node(whatnode,whatval);
    print_list();   

    printf("Before what node");
    scanf("%d",&whatnode);
    printf("What val=");
    scanf("%d",&whatval);
    add_before_node(whatnode,whatval);
    print_list();   


    printf("Remove node");
    scanf("%d",&whatnode);
    remove_node(whatnode);
    print_list();   


    return (0);  
}

void add_to_list(int whatvalue) {

     struct Node *c;
 
     if(start == NULL) {

        start = (struct Node*)malloc(sizeof(struct Node));  
        start->info = whatvalue;
        start->next = NULL;
        end = start;

     } else {

        c = (struct Node*)malloc(sizeof(struct Node));           
        c->info = whatvalue;
        c->next = NULL;
        end->next = c;
        end = c;
     }
}

void print_list() {
     struct Node* c;
   
     c = start;

     while(c){
           printf("%d ", c->info);
           c = c->next; 
     }
}

void add_after_node(int afterwhat, int val) {

     struct Node* c = start, *newNode;

     while(c->info != afterwhat) c = c->next;

     newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->info = val;
     newNode->next = c->next;
     c->next = newNode;
     
     if(c == end) end = newNode;

}

void add_before_node(int beforewhat,int val) {

     struct Node* c, *newNode;

     if(start->info == beforewhat) {

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->info = val;
        newNode->next = start;
        start = newNode; 

     } else {

       c = start;

       while(c->next->info != beforewhat) c = c->next;

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->info = val;
        newNode->next = c->next;         
        c->next = newNode; 
     }      
}

void remove_node(int whatnode) {

     struct Node *ptr,*c;

     if(start->info == whatnode) {

       ptr = start;
       start = start->next;

       free(ptr); 

     } else {

       c = start;

       while(c->next->info != whatnode) c = c->next;
      
       ptr = c->next;

       c->next = ptr->next;

       if(c->next == end) end = c;
              
       free(ptr);
    
     }
}
