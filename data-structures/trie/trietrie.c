#include <stdio.h>
#include <malloc.h>
#define ch (*str - 'a')
#define SIZE 'z' - 'a' + 1

struct Trie {

       int data;

       struct Trie *character[ SIZE ];

} *head = NULL;

struct Trie* getNode() {

       int i;

       struct Trie *node = (struct Trie*)malloc(sizeof(struct Trie));

       for(i = 0; i < SIZE; i++) node->character[ i ] = NULL;

       node->data = 0;

       return node;
};

void insert(char *str) {

     struct Trie *ptr = head;

           if(head == NULL) {

              head = getNode();

              ptr = head; 
           } 

     while(*str != '\0') {

           if(ptr->character[ ch ] == NULL) 

              ptr->character[ ch ] = getNode();      

           if(*(str+1) == '\0') ptr->data = 1;

           ptr = ptr->character[ ch ];

           str++;  
     }
};

//returns 1 for SUCCESS, 0 if not found
int search(char *str) {

    struct Trie *ptr = head; 
 
    while(*str != '\0') {
    
          if(ptr == NULL && *str != '\0') return 0;

          if(*(str+1) == '\0') return ptr->data; 

          ptr = ptr->character[ ch ];

          str++; 
    }

    return ptr->data;   
};

void deletion(char *str) {

    struct Trie *ptr = head; 
 
    while(*str != '\0') {

          if(ptr == NULL && *str != '\0') break;

          if(*(str+1) == '\0') ptr->data = 0; 

          ptr = ptr->character[ ch ];

          str++; 
    }
};

int main() {

    insert("metallic");

    insert("metallica");

    if(search("metallic") == 1) printf("%s", "Found!");

                            else printf("%s", "Not Found!");

    if(search("linkinpark") == 1) printf("%s", "Found!");

                            else printf("%s", "Not Found!");

    return(0);  
};