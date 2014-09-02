/**
 *  Binary Search Tree - BST non-recursive solution
 *  -----------------------------------------------
 *
 *  Methods:
 *  -------
 *  add
 *  search
 *  delete
 *   
 *  inorder
 *  postorder
 *  inorder
 */

#include <stdio.h>
#include <malloc.h>

struct Node {

       int data;
       struct Node *left;
       struct Node *right;
};

struct Node *root=NULL;

void add(int);
void inorder(struct Node*);
void preorder(struct Node*);
void postorder(struct Node*);
int  search(int);
void delete(int);

int main() {
    int node;
    int whatsearch; 

    add(8);
    add(3);
    add(10);
    add(1);
    add(2);
    add(14);
    add(11);
    add(6);
    add(4);
    add(7);     

    postorder(root);

    printf("\nNode to search=");
    scanf("%d",&whatsearch);
 
    if(search(whatsearch)) {

       printf("The node %d exists in Tree \n",whatsearch);

    } else {

       printf("The node %d not exist in Tree \n",whatsearch);
    }

    printf("Give me a node to remove NODE=");
    scanf("%d",&node);

    printf("\nTrying to remove the node=%d", node);
    delete(node);

    //Traversals
    printf("\n\nPostorder:\n");
    postorder(root);    
    printf("\nInorder:\n");
    inorder(root);    
    printf("\nPreorder:\n");
    preorder(root);    


    //return SUCCESS to the Operating System
    return (0);  
};

void add (int val) {

     struct Node *curr, *new;

     if(root == NULL) {

        root = (struct Node*) malloc(sizeof(struct Node));
 
        root->data = val;

        root->left = NULL;

        root->right = NULL;
 
     } else {

       curr = root;

       while(1) {

            if(val < curr->data) {

               if(curr->left) {

                 curr = curr->left;

               } else {
                 
                 new = (struct Node*) malloc(sizeof(struct Node));             

                 new->data = val;

                 new->left = NULL;

                 new->right = NULL; 

                 curr->left = new;

                 break; 
               }

            } else {

               if(curr->right) {

                 curr = curr->right;

               } else {

                 new = (struct Node*) malloc(sizeof(struct Node));             

                 new->data = val;

                 new->left = NULL;

                 new->right = NULL; 

                 curr->right = new;

                 break; 
               }
            } 
       }     
     }
};

void postorder(struct Node* node) {

    if(node->left) {

       postorder(node->left);
    } 

    if(node->right) {

       postorder(node->right);
    } 

    printf("%d ",node->data);   

};

void inorder(struct Node* node) {

    if(node->left) {

       inorder(node->left);
    } 

    printf("%d ",node->data);   

    if(node->right) {

       inorder(node->right);
    } 

};


void preorder(struct Node* node) {

    printf("%d ",node->data);   

    if(node->left) {

       preorder(node->left);
    } 

    if(node->right) {

       preorder(node->right);
    } 
};


int search(int val) {

    struct Node *curr = root;

    int found = 0;

    while(!found && curr) {

         if(curr->data == val) {

            found = 1;

         } else {

            if(val < curr->data) {

               curr = curr->left;

            } else {

               curr = curr->right;
            }  

         } 
    }       

   return found;
}

void delete(int val) {

    struct Node *curr = root, *parrent, *next;

    int found = 0;

    while(!found && curr) {

         if(curr->data == val) {

            found = 1;

         } else {

            if(val < curr->data) {

               parrent = curr;

               curr = curr->left;

            } else {

               parrent = curr;
 
               curr = curr->right;
            }  

         } 
    }       


    if( found ) {

       if(curr->left == NULL && curr->right == NULL) {
         
          if(parrent->data < curr->data) parrent->right = NULL;

                           else parrent->left = NULL;

          free(curr);
                      
       } else if(curr->left == NULL && curr->right != NULL) {

          //for debug
          //printf("node=%d parent=%d",curr->data, parrent->data);  

          next = curr->right;

          if(parrent->data < curr->data) parrent->right = next;

                           else parrent->left = next;
          free(curr);

       } else if(curr->left != NULL && curr->right == NULL) {

         //for debug 
         //printf("node=%d parent=%d",curr->data, parrent->data);

         next = curr->left;

         if(parrent->data < curr->data) parrent->right = next;

                                 else   parrent->left = next;
         free(curr);

       } else if(curr->left != NULL && curr->right != NULL) {
        
               struct Node *p,*c;

               //if the node has left subtree and rightsubtree then trying to find out the mostly right from left subtree
               c = curr->left;

               while(c->right) {

                     p = c;

                     c=c->right;
               }

               //for debug
               //printf("node=%d parrent=%d",c->data,p->data);
    
               curr->data = c->data;

               next = c->left;

               if(p->data < c->data) p->right = next;
                            else     p->left = next;

               free(c);  
       }

         
    printf("\nThe node is removed\n");        

    } else {

       printf("\nNode not found!");
    } 
}