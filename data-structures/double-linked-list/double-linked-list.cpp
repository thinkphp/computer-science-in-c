#include <iostream>
#include <fstream>

using namespace std;

struct Node {
       int info;
       struct Node *next;
       struct Node *prev;
};

//globals
Node *front = NULL, *back = NULL;

void add_to_right(int);
void add_after(int,int);
void add_before(int,int);
void remove_node(int);
void display_from_left_to_right();
void display_from_right_to_left();

int main() {
    int whichnode, whatvalue;
    int removenode;

    for(int i=1;i<=9;i++)
        add_to_right( i );

    display_from_left_to_right(); 
    display_from_right_to_left();

    cout<<endl;
    cout<<"insert after node=";
    cin>>whichnode;
    cout<<"which one value=";
    cin>>whatvalue;
    add_after(whichnode, whatvalue);
    display_from_left_to_right(); 


    cout<<endl;
    cout<<"insert before node=";
    cin>>whichnode;
    cout<<"which one value=";
    cin>>whatvalue;
    add_before(whichnode, whatvalue);
    display_from_left_to_right(); 

    cout<<endl;
    cout<<"Node to remove=";
    cin>>removenode;
    remove_node(removenode);
    display_from_left_to_right(); 
        

    return (0);
};

void add_to_right(int whatvalue) {

     struct Node *c;
 
     if(front == NULL) {
 
        c = new Node;
        c->info = whatvalue;
        c->next = c->prev = NULL; 
        front = back = c;
  
     } else {

        c = new Node;
        c->info = whatvalue;
        c->next = NULL;
        c->prev = back;
        back->next = c; 
        back = c;
     }

};

void add_after(int whichone, int whatvalue) {

     struct Node *c = front, *p;

     if(back->info == whichone) {

       p = new Node;
       p->info = whatvalue;
       p->next = NULL;
       p->prev = back;
       back->next = p; 
       back = p;
        
     } else {

       while(c->info != whichone) c = c->next;

       p = new Node;
       p->info = whatvalue;
       p->next = c->next;
       p->prev = c; 
       c->next->prev = p;
       c->next = p;
     }     
};

void remove_node(int removenode) {

     struct Node *removal, *c;


     if(front->info == removenode) {

        removal = front;

        front = front->next;
        front->prev = 0;

        delete removal;    

     } else if(front->info != removenode && back->info != removenode){

       c = front;

       while(c->info != removenode) c = c->next;

       c->next->prev = c->prev;
       c->prev->next = c->next;

       delete c;       

      } else if(back->info == removenode) {

       removal = back;

       back = back->prev;
       back->next = NULL;

       delete removal; 
     }
};

void display_from_left_to_right() {

     struct Node *c;

     cout<<endl;

     for(c = front; c; c = c->next) 

         cout<<c->info<<" ";      
};

void display_from_right_to_left() {

     struct Node *c = back;

     cout<<endl; 

     for(c = back; c; c = c->prev) 

         cout<<c->info<<" ";     
};

void add_before(int whichnode,int whatvalue) {

    struct Node *p,*c;

    if(front->info == whichnode) {

       p = new Node;
       p->info = whatvalue;
       p->next = front;
       front->prev = p;  
       front = p; 

    } else {

       c = front;

       while(c->next->info != whichnode) c = c->next;

       p = new Node;
       p->info = whatvalue;
       p->next = c->next;
       p->prev = c;
       c->next->prev = p;
       c->next = p;
    }
}