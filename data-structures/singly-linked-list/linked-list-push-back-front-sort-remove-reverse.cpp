#include <bits/stdc++.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node* HEAD = nullptr;

void addToLinkedListFront(int value) {

	if(HEAD == NULL) {

		HEAD = (struct Node*)malloc(sizeof(struct Node));

		HEAD->data = value;

		HEAD->next = NULL;

	} else {

		struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

		new_node->data = value;

		new_node->next = HEAD;

		HEAD = new_node;
	}
}


void addToLinkedListBack(int value) {

	if(HEAD == NULL) {

		HEAD = (struct Node*)malloc(sizeof(struct Node));

		HEAD->data = value;

		HEAD->next = NULL;

	} else {
           
		struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

		new_node->data = value;	

		new_node->next = NULL;	

		struct Node *c = HEAD;

		while(c->next!=NULL) c = c->next;

		c->next = new_node;
	}
}

struct Node *reverse(struct Node *head) {

	   struct Node *curr, *next, *prev = NULL;

	   curr = head;

	   while(curr!=NULL) {

             next = curr->next;

             curr->next = prev;

             prev = curr;

             curr = next;  
	   }

	   return prev;
}

void display() {

        struct Node *c = HEAD;

        while(c!=NULL) {

        	std::cout<<c->data<<" ";

        	c = c->next;
        }
}

int search(int node) {

	int pos = 0;

    if(HEAD->data == node) return 0;

	struct Node *c = HEAD;

	while(c!=NULL) {

        if(c->data == node) return pos; 

		pos++;

		c = c->next;
	}

	return -1;
}

void removeNode(int delnode) {

     if(!HEAD) {std::cout<<"Linked List is empty";return; }
     std::cout<<"Found at position: "<<search(delnode)<<std::endl; 
     if(search(delnode) == -1) {
     	std::cout<<"Not Found del Node!\n";
     	return;
     }

      //if the del node is even HEAD->data then remove it
     if(HEAD->data == delnode) {
     	struct Node *ptr = HEAD;
     	HEAD = HEAD->next;
     	free(ptr);

     //otherwise if the del node is inside the linked list then process it
     } else {

        struct Node *c = HEAD;

        while(c->next && c->next->data != delnode) c = c->next;

        struct Node *ptr = c->next;

        c->next = ptr->next;

        free(ptr); 
     }
}

void sort() {

	struct Node *c = HEAD, *last=NULL;
	bool swapped, finished = false;

	do {
		c = HEAD;
        swapped = false; 
		while(c->next!=last) {
			if(c->data > c->next->data) {
               int temp = c->data;
               c->data = c->next->data;
               c->next->data = temp;
               swapped = true;
			}
			c = c->next;
		}

		if(swapped) last = c;
		else 
		  finished = true;

	}while(!finished);
}

void update(int oldvalue, int newvalue) {
	 struct Node *c = HEAD;
	 while(c!=NULL) {
	 	if(c->data == oldvalue) {
           c->data = newvalue;
           return;
	 	}
	 	c  = c->next;
	 }
}

int main(int argc, char const *argv[])
{
/*
	addToLinkedListFront(1);
	addToLinkedListFront(2);
	addToLinkedListFront(3);
	addToLinkedListFront(4);
	addToLinkedListFront(5);
*/
    addToLinkedListBack(11);
	addToLinkedListBack(21);
	addToLinkedListBack(32);
	addToLinkedListBack(41);
	addToLinkedListBack(51);
	addToLinkedListBack(16);
	addToLinkedListBack(17);
	addToLinkedListBack(18);

	display();

	HEAD = reverse(HEAD);

	std::cout<<"\nReverse:\n";

	display();

	int node;
	std::cout<<"\nRemove node = ";
	std::cin>>node;

	removeNode(node);

	display();
	std::cout<<"\n-------------------\n"; 
	std::cout<<"\nSorted Linked List";
	sort();
    std::cout<<"\n-------------------\n"; 
	display();
    std::cout<<std::endl;

    update(41,41111111);
    std::cout<<"update node 41 ---> node 42\n-------------------\n"; 
	display();
    
	return 0;
}
