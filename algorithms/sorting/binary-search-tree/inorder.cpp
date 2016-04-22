#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

ofstream fout(FOUT);

struct Node {

       int val;
       struct Node *left;
       struct Node *right;
};

Node *root = NULL;

void insert(int elem) {

     if(root == NULL) {

        Node *newElem = new Node;

              newElem->val = elem;

              newElem->left = NULL;

              newElem->right = NULL;  

              root = newElem;

     } else {

        Node *curr = root;

        while( 1 ) {

              if(elem < curr->val) {

                 if( curr->left ) {

                     curr = curr->left; 

                 } else {

                     Node *node = new Node;

                           node->val = elem;

                           node->left = NULL;

                           node->right = NULL;

                           curr->left = node;

                           break;                             
                 }

              } else {

                 if( curr->right ) {

                     curr = curr->right; 

                 } else {

                     Node *node = new Node;

                           node->val = elem;

                           node->left = NULL;

                           node->right = NULL;

                           curr->right = node;

                           break;                             
                 }

              } 
        }

     }
}

void inorder(Node *node) {

     if(node->left) inorder(node->left);

     fout<<node->val<<" ";

     if(node->right) inorder(node->right);
}

int main() {

    ifstream fin(FIN);

    int n, elem;

    fin>>n;

    for(int i = 0; i < n; ++i) fin>>elem, insert( elem );

    inorder( root );

    return(0);  
}