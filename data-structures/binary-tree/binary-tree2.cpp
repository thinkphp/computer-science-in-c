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

     Node *p;

     p = new Node;

     cout<<"Node = ";

     cin>>p->info;

     cout<<"Left for the node "<<p->info<<" (y/n)?: \n";

     if(tolower(getch()) == 'y') {

	p->left = create();

     } else {

	p->left = NULL;
     }

     cout<<"Right for the node "<<p->info<<" (y/n)?: \n";

     if(tolower(getch()) == 'y') {

	p->right = create();

     } else {

	p->right = NULL;
     }

   return p;
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