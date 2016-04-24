#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

struct Node {

       int val;
       struct Node *left;
       struct Node *right;
};

struct Node *root = NULL;

void insert(int info) {

     if( root == NULL ) {
 
         root = (struct Node*)malloc(sizeof(struct Node));

         root->val = info;

         root->left = NULL;
      
         root->right = NULL;  
       
     } else {

         struct Node *curr = root;
  
         while( 1 ) { 

           if( info < curr->val ) {

             if( curr->left ) {

                 curr = curr->left; 

             } else {

                 struct Node *node = (struct Node*)malloc(sizeof(struct Node));

                        node->val = info;
                        node->left = NULL;
                        node->right = NULL;
                        curr->left = node; 

                        break; 
             }


           } else {

             if( curr->right ) {

                 curr = curr->right; 

             } else {

                 struct Node *node = (struct Node*)malloc(sizeof(struct Node));

                        node->val = info;
                        node->left = NULL;
                        node->right = NULL;
                        curr->right = node; 

                        break; 
             }

           } 
         }

     } 
}

void inorder(struct Node *node) {

     if(node->left) inorder(node->left); 

     printf("%d ", node->val);  

     if(node->right) inorder(node->right);
}

int main(){

    int i, n, elem;
 
    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    scanf("%d", &n);

    for(i = 0; i < n; ++i) scanf("%d", &elem), insert( elem );

    inorder( root ); 

    return(0);
}