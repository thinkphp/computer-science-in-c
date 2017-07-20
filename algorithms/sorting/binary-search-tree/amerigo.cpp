#include <iostream>
#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005

using namespace std;

int arr[SIZE],//the array in which we hold the elements of an input vector
    n;//the number of the elements

typedef struct node {
       int info;
       struct node *left;
       struct node *right; 
} Node;

Node *root = NULL;

void insert_into_binary_tree_search(int val) {

     if(root == NULL) {

        root = new Node();
        root->info = val;
        root->left = NULL;
        root->right = NULL; 

     } else {

        Node *curr = root;

        while(1) {

          if(curr->info > val) {

            if(curr->left) {

               curr = curr->left;

            } else {

               Node *tmp = new Node();
                     tmp->info = val;
                     tmp->left = NULL;
                     tmp->right = NULL;
                     curr->left = tmp;
                     break; 
            } 

          } else {

            if(curr->right) {

               curr = curr->right;

            } else {

               Node *tmp = new Node();
                     tmp->info = val;
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
     cout<<node->info<<" ";
     if(node->right) inorder(node->right);
};

int main() {

    ifstream fin(FIN);

    fin>>n;

    for(int i = 0; i < n; ++i) fin>>arr[i];

    //the binary search tree in action

    for(int i = 0; i < n; ++i) insert_into_binary_tree_search(arr[i]);
 
    cout<<"Input  Array -> ";  
    for(int i = 0; i < n; ++i) cout<<arr[i]<<" ";

    cout<<endl<<"Output Array -> ";

    inorder( root );  

    return(0); 
};