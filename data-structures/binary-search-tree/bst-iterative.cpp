/*
Binary Search Tree (BST - iterative )

struct Node {
   int data;
   struct Node *left;
   struct Node *right;
}

Node *mostlyLeft(Node *root) {

     while(root->left) root = root->left;


     return root;
}

Node *remove( Node *root, int key ) {

      if(root == NULL) {
        return root;
      } else if(root->data > key) {
             root->left = remove(root->left, key);
     } else if(root->data < key) {
             root->right = remove(root->right, key)
     } else {

            if(root->left == NULL && root->right == NULL) {
                   free(root);
                    return NULL
            }   else if(root->left == NULL) {
                  Node *temp = root->right;
                  free(root);
                  return temp;
           }  else if(root->right == NULL) {
                  Node *temp = root->left;
                  free(root);
                  return temp;

           }  else if(root->left !=NULL && root->right != NULL) {
                Node *temp = mostlyLeft(root->right)
                     root->data = temp->data;
                     root->right = remove(root->right, temp->data)
           }
     }
}

*/


#include <iostream>

struct Node {

     int data;
     struct Node *left;
     struct Node *right;
};

struct Node *root = NULL;

void insert(int val) {

     struct Node *curr, *new_node;

     if(root == NULL) {

          root = (struct Node*)malloc(sizeof(struct Node));

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

                          new_node = (struct Node*) malloc(sizeof(struct Node));

                          new_node->data = val;
                          new_node->left= NULL;
                          new_node->right = NULL;
                          curr->left = new_node;
                          break;

                      }


                  } else {


                         if(curr->right) {

                              curr = curr->right;

                         }  else {

                              new_node = (struct Node*)malloc(sizeof(struct Node));
                              new_node->data = val;
                              new_node->left = NULL;
                              new_node->right = NULL;
                              curr->right = new_node;

                              break;

                         }

                  }

            }


     }
}

void inorder(struct Node *node) {

     if(node->left) inorder(node->left);

     printf("%d ", node->data);

     if(node->right) inorder(node->right);
}

void postorder(struct Node*node) {

     if(node->left) postorder(node->left);

     if(node->right) postorder(node->right);

     printf("%d ", node->data);
}

void preorder(struct Node *node) {

     printf("%d ", node->data);

     if(node->left) preorder(node->left);

     if(node->right) preorder(node->right);
}


int search(int val) {

     //get the pointer of the BST
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
void remove(int val) {
    struct Node *curr = root, *parent = NULL, *next;
    int found = 0;
    
    // Search for the node to be removed
    while(!found && curr) {
        if(curr->data == val) {
            found = 1;
        } else {
            parent = curr;
            if(val < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
    
    if(found) {
        // Case 1: Node has no children
        if(curr->left == NULL && curr->right == NULL) {
            // Special case: removing root node
            if(parent == NULL) {
                free(root);
                root = NULL;
            } else {
                if(parent->data > curr->data) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                free(curr);
            }
        } 
        // Case 2: Node has only right child
        else if(curr->left == NULL && curr->right != NULL) {
            next = curr->right;
            // Special case: removing root node
            if(parent == NULL) {
                root = next;
            } else {
                if(parent->data > curr->data) {
                    parent->left = next;
                } else {
                    parent->right = next;
                }
            }
            free(curr);
        } 
        // Case 3: Node has only left child
        else if(curr->left != NULL && curr->right == NULL) {
            next = curr->left;
            // Special case: removing root node
            if(parent == NULL) {
                root = next;
            } else {
                if(parent->data > curr->data) {
                    parent->left = next;
                } else {
                    parent->right = next;
                }
            }
            free(curr);
        } 
        // Case 4: Node has two children
        else if(curr->left != NULL && curr->right != NULL) {
            // Find the in-order successor (minimum value in right subtree)
            // Or alternatively, the in-order predecessor (maximum value in left subtree)
            // We're using the in-order predecessor approach (max of left subtree)
            struct Node *p = curr, *c = curr->left;
            
            // Find the rightmost node in the left subtree
            while(c->right) {
                p = c;
                c = c->right;
            }
            
            // Copy the data
            curr->data = c->data;
            
            // Handle the special case where c is directly curr->left
            if(p == curr) {
                p->left = c->left;
            } else {
                p->right = c->left;
            }
            
            free(c);
        }
        
        printf("The node is removed!\n");
    } else {
        printf("The Node not found!\n");
    }
}

int main(int argc, char const *argv[]) {

  insert(8);
  insert(3);
  insert(10);
  insert(1);
  insert(7);
  insert(12);
  insert(21);
  printf("\nInorder: \n");
  inorder(root);
  printf("\nPreorder: \n");
  preorder(root);
  printf("\npostorder: \n");
  postorder(root);

  int search_key = 1;

  int ans = search(search_key);

  if(ans == 1) printf("The key is found in BST\n");
          else
               printf("The key is not found in BST\n");

  int remove_key = 7;

  remove(remove_key);

  inorder(root);

  return 0;
}
