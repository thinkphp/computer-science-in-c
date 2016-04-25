#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

struct Node {
       int val;
       struct Node *left;
       struct Node *right;
};

void insert(struct Node **bt, int info) {

     if( *bt == NULL) {

         (*bt) = malloc(sizeof(struct Node));
         (*bt)->val = info;
         (*bt)->left = NULL;
         (*bt)->right = NULL;
     
     } else {

            if( info < (*bt)->val )

                insert(&((*bt)->left), info);

            else

                insert(&((*bt)->right), info);
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

    struct Node *bt = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; ++i) scanf("%d", &elem), insert(&bt, elem );

    inorder( bt ); 

    return(0);
}