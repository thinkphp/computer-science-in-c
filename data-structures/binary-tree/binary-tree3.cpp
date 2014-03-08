#include <iostream.h>
#include <conio.h>
#include <ctype.h>

typedef struct Element{
        int info;
	struct Element* left;
	struct Element* right;
} Node;

Node* create();
void inorder(Node *p);
void postorder(Node *p);
void preorder(Node *p);

void main() {

     Node *root = NULL;

     clrscr();

     cout<<"\nBinary Tree\n\n";

     root = create();

     cout<<"\nInorder:\n";
     inorder( root );

     cout<<"\nPreorder:\n";
     preorder( root );

     cout<<"\nPostorder:\n";
     postorder( root );

     cout<<"\nPress any key for exit!";
     getch();
}

Node* create() {

     int info;
     Node *newNode;

     cout<<"info = ";cin>>info;

     if(info) {

	newNode = new Node;

	newNode->info = info;

	cout<<"left for: "<<info<<" ";
	newNode->left = create();

	cout<<"right for: "<<info<<" ";
	newNode->right = create();

	return newNode;

     } else {

       return 0;
     }

}

void inorder(Node *node) {

     if(node->left) {

	inorder(node->left);
     }

     cout<<node->info<<" ";

     if(node->right) {

	inorder(node->right);
     }
}

void preorder(Node *node) {

     cout<<node->info<<" ";

     if(node->left) {

	inorder(node->left);
     }


     if(node->right) {

	inorder(node->right);
     }
}

void postorder(Node *node) {

     if(node->left) {

	inorder(node->left);
     }

     if(node->right) {

	inorder(node->right);
     }

     cout<<node->info<<" ";
}