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

void insertTree(int elem) {

     struct Node *curr, 
                 *newnode;

     if(root == NULL) {

        root = (struct Node*)malloc(sizeof(struct Node)); 
        root->info = elem;
        root->left = NULL;
        root->right = NULL; 

     } else {

       curr = root;

       while( 1 ) {

             if(elem < curr->info) {

                     if( curr->left ) {

                         curr = curr->left;

                     } else {

                        newnode = (struct Node*)malloc(sizeof(struct Node)); 
                        newnode->info = elem;
                        newnode->left = NULL;
                        newnode->right = NULL; 
                        curr->left = newnode;  

                        break;  
                     }

             } else {


                     if( curr->right ) {

                         curr = curr->right;

                     } else {

                        newnode = (struct Node*)malloc(sizeof(struct Node)); 
                        newnode->info = elem;
                        newnode->left = NULL;
                        newnode->right = NULL; 
                        curr->right = newnode;  

                        break;  
                     }
             }  
       }
     } 
}

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

     for(i = 0; i < n; i++) scanf("%d", &elem), insertTree( elem );     

     inorder(root);

     fclose( stdin );

     fclose( stdout );
}

int main() {

    sort();

    return(0); 
}