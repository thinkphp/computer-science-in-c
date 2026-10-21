#include <iostream>

using namespace std;

typedef struct Node {
	int data;
	struct Node *next;
} Node;

class SinglyLinkedList {

      private:
      Node *head;

	  public:
	  SinglyLinkedList() {
	  	head = NULL;
	  }	

	  SinglyLinkedList& added_front(int key) {
	  	    Node *newNode = new Node;
	  		newNode->data = key;
	  		newNode->next = NULL;
	  	if(head == NULL) {
	  		head = newNode;
	  	} else {
	  		newNode->next= head;
	  		head = newNode;
	  	}
	  	return *this;
	  }


	  SinglyLinkedList& added_back(int key) {
	  	    Node *newNode = new Node;
	  		newNode->data = key;
	  		newNode->next = NULL;
	  	if(head == NULL) {
	  		head = newNode;
	  	} else {
	  		Node *temp = head;

	  		while(temp->next) temp = temp->next;

	  		temp->next = newNode;

	  	
	  	}
	  	return *this;
	  }

	  void display() {
	  	   Node *c = head;
	  	   while(c) {
	  	   	cout<<c->data<<" ";
	  	   	c = c->next;
	  	   }
	  }

	  ~SinglyLinkedList() {
  
          Node *c = head;
          while(c) {
          	Node *temp = c;
          	c = c->next;
          	delete temp;
          }

          head = NULL;
        
          cout<<"destructor called"<<endl;
	  }

};

int main(int argc, char const *argv[])
{
	SinglyLinkedList list;

	list.added_front(1)
	    .added_back(33)
	    .added_back(2)
	    .added_back(3)
	    .added_back(4)
	    .added_back(5)
	    .display();
	
	return 0;
}
