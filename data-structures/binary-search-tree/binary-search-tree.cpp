/**
 *  Binary Search Tree - recursive solution
 */

#include <iostream>

using namespace std;

typedef struct Node {
        int   info;
        Node *left;
        Node *right;
} Node;

void insert(Node*&, int);
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
int search(Node*&,int);
void remove(Node *&, int);
void mostlyright(Node *&,Node *&);

int main() {

    Node *root=NULL;

    insert(root,8);
    insert(root,3);
    insert(root,1);
    insert(root,2);
    insert(root,10);
    insert(root,6);
    insert(root,4);
    insert(root,7);
    insert(root,14);
    insert(root,11);

    cout<<endl;
    cout<<"Postorder:"<<endl;    
    postorder(root);
    cout<<endl;    

    remove(root,3);   
    postorder(root);

    return 1;
}

void insert(Node *&node, int val) {
      
     if(node == NULL) {
        
        node = new Node;
        node->info = val;
        node->left = NULL;
        node->right = NULL; 
        
     } else {

        if(val < node->info) {

           insert(node->left, val);

        } else {

           insert(node->right, val);
        }
     }
}

void inorder(Node *node) {

     if(node->left) {
        inorder(node->left);
     }

     cout<<node->info<<" ";
 
     if(node->right) {
        inorder(node->right);
     }
}

void preorder(Node *node) {

     cout<<node->info<<" ";

     if(node->left) {
        preorder(node->left);
     }
 
     if(node->right) {
        preorder(node->right);
     }
}

void postorder(Node *node) {

     if(node->left) {
        postorder(node->left);
     }
 
     if(node->right) {
        postorder(node->right);
     }

     cout<<node->info<<" ";
}

int search(Node *&node,int key) {

   if(node != NULL)

           if(node->info == key) {

                    return 1;

           } else if(key < node->info){
       
                    return search(node->left, key); 
           } else {

              return search(node->right, key); 
           }

   return 0; 
}

void remove(Node *&node, int key) {

  Node *next;

  if(node != NULL)

     if(node->info == key) {

        if(node->left == NULL && node->right == NULL) {

                 delete node;

                 node = NULL;

        } else if(node->left != NULL && node->right == NULL) {

                 next = node->left;

                 delete node;

                 node = next;


        } else if(node->left == NULL && node->right != NULL) {

                 next = node->right;

                 delete node;

                 node = next;

        } else {

               mostlyright(node, node->left);               
        }


     } else if(node->info < key) {

            remove(node->right, key);

     } else {

            remove(node->left, key);
     }

}

void mostlyright(Node *&p, Node *&q) {

     Node *a;

     if(q->right != NULL) {

        mostlyright(p, q->right); 

     } else {

        p->info = q->info;
         
        a = q;

        q = q->left;   

        delete a;
     }

}
