#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

struct Node {

       int info;

       struct Node *left; 

       struct Node *right;
};

struct Node *root = NULL;

int n;

void insertTree(struct Node **treeroot, int elem) {

     struct Node *newnode;

     if(*treeroot == NULL) {

        *treeroot = (struct Node*)malloc(sizeof(struct Node)); 

        (*treeroot)->info = elem;

        (*treeroot)->left = NULL;

        (*treeroot)->right = NULL; 

     } else {

        if(elem < (*treeroot)->info) {

                   insertTree(&((*treeroot)->left), elem);
        } else {

                   insertTree(&((*treeroot)->right), elem);
        }

     } 
};

void inorder(struct Node *node) {

     if( node->left ) inorder( node->left );

     printf("%d ",node->info);

     if( node->right ) inorder( node->right );
}

void sort() {

     int i,
         elem;

     freopen(FIN, "r", stdin);

     freopen(FOUT, "w", stdout);

     scanf("%d", &n); 

     for(i = 0; i < n; i++) scanf("%d", &elem), insertTree(&root, elem );     

     inorder( root );

     fclose( stdin );

     fclose( stdout );
}

int main() {

    sort();

    return(0); 
}