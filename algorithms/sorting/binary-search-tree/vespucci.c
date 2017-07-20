#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005

typedef struct node {
        int info;
        struct node *left;
        struct node *right;
} Node;

Node *root = NULL;

int arr[ SIZE ], 
    n;


void insertBST(int value) {

     if( root == NULL ) {

         root = ( Node* )malloc(sizeof( Node ));

         root->info = value;
         root->left = NULL;
         root->right = NULL;   

     } else {

         Node *curr = root;

         while( 1 ) {

         if(value < curr->info) {

            if(curr->left) {

               curr = curr->left;
 
            } else {

               Node *tmp = ( Node* )malloc(sizeof( Node ));

                     tmp->info = value;
                     tmp->left = NULL;
                     tmp->right = NULL;
                     curr->left = tmp;   
                     break; 
            } 

         } else {

            if(curr->right) {

               curr = curr->right;
 
            } else {

               Node *tmp = ( Node* )malloc(sizeof( Node ));

                     tmp->info = value;
                     tmp->left = NULL;
                     tmp->right = NULL;
                     curr->right = tmp;
                     break;   
            } 

         }

         }

     }
};

void inorder(Node *node) {

     if(node->left) inorder(node->left);

     printf("%d ", node->info);

     if(node->right) inorder(node->right);
};

int main() {

    int i;

    freopen(FIN,"r",stdin);

    scanf("%d", &n);

    for(i = 0; i < n ; i++) scanf("%d", &arr[ i ]);

    for(i = 0; i < n ; i++) insertBST(arr[i]);

    freopen(FOUT,"w",stdout);

    inorder( root );

 return(0);
};