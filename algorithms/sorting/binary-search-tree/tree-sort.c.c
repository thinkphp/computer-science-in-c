#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

struct Node {
       int val;
       struct Node *left;
       struct Node *right;
};

typedef struct Node node;

void insert(node **bt, node *Node) {

     if( !(*bt) ) {

         *bt = Node;
     
     } else {

            if( Node->val < (*bt)->val )

                insert(&((*bt)->left), Node);

            else

                insert(&((*bt)->right), Node);
     }
}

void printout(node *root) {

     if(root->left) printout(root->left); 

     printf("%d ", root->val);  

     if(root->right) printout(root->right);
}

void postorder(struct Node *node) {

     if(node->left) printout(node->left); 

     if(node->right) printout(node->right);

     printf("%d ", node->val);  
}

void preorder(struct Node *node) {

     printf("%d ", node->val);  

     if(node->left) printout(node->left); 

     if(node->right) printout(node->right);
}

int main(){

    int i, n, elem;    

    node *curr; 
 
    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    node *bt = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; ++i) {

         scanf("%d", &elem); 

         curr = malloc( sizeof(struct Node) );

         curr->val = elem;

         curr->left = NULL;

         curr->right = NULL;

         insert(&bt, curr );
    }

    printout( bt ); 
    
    return(0);
}