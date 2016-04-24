#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

struct Node {
       int val;
       struct Node *left;
       struct Node *right;
};

void insert(struct Node **bt, struct Node *node) {

     if( *bt == NULL) {

         *bt = node;
     
     } else {

            if( node->val < (*bt)->val )

                insert(&((*bt)->left), node);

            else

                insert(&((*bt)->right), node);
     }
}

void printout(struct Node *node) {

     if(node->left) printout(node->left); 

     printf("%d ", node->val);  

     if(node->right) printout(node->right);
}

void postorder(struct Node *node) {

     if(node->left) printout(node->right); 

     printf("%d ", node->val);  

     if(node->right) printout(node->right);
}

int main(){

    int i, n, elem;    

    struct Node *curr; 
 
    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    struct Node *bt = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; ++i) {

         scanf("%d", &elem); 

         curr = (struct Node*)malloc( sizeof(struct Node) );

         curr->val = elem;

         curr->left = NULL;

         curr->right = NULL;

         insert(&bt, curr );
    }

    printout( bt ); 

    return(0);
}