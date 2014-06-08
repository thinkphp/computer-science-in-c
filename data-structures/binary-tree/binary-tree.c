#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <ctype.h>

struct Node {
        int info;
        struct Node* left;
        struct Node* right;
};

struct Node* create();
void inorder(struct Node *p);
void postorder(struct Node *p);
void preorder(struct Node *p);

void main() {

     struct Node *root = NULL;

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

struct Node* create() {

     struct Node *p;

     p = (struct Node*)malloc(sizeof(struct Node));

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

void inorder(struct Node *node) {

     if(node->left) {

	inorder(node->left);
     }

     printf(" %d", node->info);

     if(node->right) {

	inorder(node->right);
     }
}

void preorder(struct Node *node) {

     printf(" %d", node->info);

     if(node->left) {

	inorder(node->left);
     }


     if(node->right) {

	inorder(node->right);
     }
}

void postorder(struct Node *node) {

     if(node->left) {

	inorder(node->left);
     }

     if(node->right) {

	inorder(node->right);
     }

     printf(" %d", node->info);
}