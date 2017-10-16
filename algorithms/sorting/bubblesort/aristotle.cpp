#include <iostream>
#include <fstream>
#include <cstring>
#define FIN "persons.in"

using namespace std;

typedef struct data {

        char name[30], 
             surname[30];         
        int age;
        float note;   

} Data;

typedef struct node {
       
       Data info;
       struct node *next;
    
} Node;

Node *head = NULL;

void add(Data elem) {

     Node *c;

        c = new Node;

     if(head == NULL) {

        c->info = elem;

        c->next = NULL;

        head = c;   
          
     } else {

        c->info = elem;
        c->next = head;
        head = c;           
     }
};

void displayList() {

     Node *c = head;

     int cnt = 1;

     while( c ) {
        
        cout<<(cnt++)<<". "<<(c->info).name<<" "<<(c->info).surname<<" "<<(c->info).age<<" "<<(c->info).note<<endl; 

        c = c->next;

     }

     cout<<endl;
};

Node* reverse() {

     Node *curr = head,
          *next,
          *prev = NULL; 

     while(curr) {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
     }

     return prev;
}; 

void sort(Node *head) {

     Node *i,*j;
     Data tmp;
     int swapped = 1;

     for(i = head; i->next != NULL && swapped; i = i->next) {

              swapped = 0; 

              for(j = i->next; j != NULL; j = j->next) {

                      if((i->info).note < (j->info).note) {

                          tmp = i->info;

                          i->info = j->info;

                          j->info = tmp;

                          swapped = 1; 
                      }
              }
     }      
};


int main( void ) {

    ifstream fin(FIN);
    int i,n;
    Data elem;
    char x[30],y[30]; 
  
    fin>>n; 
    for(i = 0; i < n; ++i) {

        fin>>x>>y>>elem.age>>elem.note;
        strcpy(elem.name,x);
        strcpy(elem.surname,y);
        add(elem);       
    } 

    displayList(); 
    head = reverse();
    displayList();
    sort(head); 
    displayList(); 
 
 return(0);
};