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


     struct Node *curr = root, *parent, *next;

     int found = 0;

     while(!found && curr) {

            if(curr->data == val) {

               found = 1;

            }  else {

               if(val < curr->data) {
                  parent = curr;
                  curr = curr->left;
               }  else {
                  parent = curr;
                  curr = curr->right;
               }
            }
     }

    if( found )  {


          if(curr->left == NULL && curr->right == NULL) {

                 if(parent->data < curr->data) parent->right = NULL;
                            else
                                               parent->left = NULL;
                 free(curr);

          } else if(curr->left == NULL && curr->right != NULL) {

                 next = curr->right;

                 if(parent->data < curr->data) parent->right = next;
                              else
                                               parent->left = next;
                 free(curr);

          } else if(curr->left != NULL && curr->right == NULL) {

                 next = curr->left;

                 if(parent->data < curr->data) parent->right = next;
                                    else
                                               parent->left = next;
                  free(curr);

          } else if(curr->left != NULL && curr->right != NULL) {

                 struct Node *p, *c;

                 c = curr->left;

                while(c->right) {

                    p = c;

                    c = c->right;
                }

                curr->data = c->data;

                next = c->left;

                if(p->data < c->data) p->right = next;
                             else
                                      p->left = next;

                free(c);

          }


          printf("The node is removed!");

    } else {


         printf("The Node not found!");
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
