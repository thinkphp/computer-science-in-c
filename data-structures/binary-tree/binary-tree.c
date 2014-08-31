#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <ctype.h>

typedef struct Node {
        int info;
        Node* left;
        Node* right;
} Node;

Node* create();
void inorder(Node *p);
void postorder(Node *p);
void preorder(Node *p);


void main() {

     Node *root = NULL;

     clrscr();

     printf("%s","\nBinary Tree\n\n\n");

     root = create();

     printf("%s","\nInorder:\n");
     inorder( root );

     printf("%s","\nPreorder:\n");
     preorder( root );

     printf("%s","\nPostorder:\n");
     postorder( root );

     printf("\nPress any key for exit!");
     getch();

}

Node* create() {

     Node *p;

     p = (Node*)malloc(sizeof(Node));

     printf("%s","Node = ");

     scanf("%d",&p->info);

     printf("Left for the node %d (y/n)?:\n", p->info);

     if(tolower(getch()) == 'y') {

	p->left = create();

     } else {

	p->left = NULL;
     }

     printf("Right for the node %d (y/n)?: \n", p->info);

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

     printf(" %d", node->info);

     if(node->right) {

	inorder(node->right);
     }
}

void preorder(Node *node) {

     printf(" %d", node->info);

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

     printf(" %d", node->info);
}