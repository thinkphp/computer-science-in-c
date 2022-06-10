#include <stdio.h>
#include <malloc.h>

typedef struct Node {
       struct Node * left;
       struct Node * right;
       int data;
} Node;

Node *insert(Node * root, int key) {

      if(root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->left= NULL;
        root->right = NULL;
        root->data = key;
      } else {
        if(root->data < key) {
          root->right = insert(root->right, key);
        } else if(root->data > key) {
          root->left = insert(root->left, key);
        }
      }

      return root;
}

Node *mostlyLeft(Node *root) {
      if(root->left) {
        root = root->left;
      }
      return root;
}

Node *delete(Node *root, int key) {

     if(root == NULL) {

       return root;

     } else if(root->data > key) {

       root->left = delete(root->left, key);

     } else if(root->data < key) {

       root->right = delete(root->right, key);

     } else {

       if(root->left == NULL && root->right == NULL) {

          free(root);
          return NULL;

       } else if(root->left == NULL) {

          Node *temp = root->right;
          free(root);
          return temp;

       } else if(root->right == NULL) {
         
          Node *temp = root->left;
          free(root);
          return temp;

       } else if (root->left != NULL && root->right != NULL)  {

         Node *temp = mostlyLeft(root->right);
               root->data = temp->data;
               root->right = delete(root->right, temp->data);
       }


     }

     return root;
}

int search(Node *root, int key) {
    if(root == NULL) {
       return 0;
    } else if(root->data > key) {
      return search(root->left, key);
    } else if(root->data < key) {
      return search(root->right, key);
    } else {
      return 1;
    }
}

void inorder(Node*node) {
     if(node) {
       inorder(node->left);
       printf("%d ", node->data);
       inorder(node->right);
     }
}

void preorder(Node*node) {
     if(node) {
       printf("%d ", node->data);
       inorder(node->left);
       inorder(node->right);
     }
}

void postorder(Node*node) {
     if(node) {
       inorder(node->left);
       inorder(node->right);
       printf("%d ", node->data);
     }
}

int main(int argc, char const *argv[]) {

  Node *root = NULL;

  root = insert(root, 10);
  insert(root, 5);
  insert(root, 4);
  insert(root, 18);
  insert(root, 1);
  insert(root, 5);
  insert(root, 19);
  insert(root, 23);
  insert(root, 22);
  insert(root, 14);
  printf("%s", "Inorder Traversal: ");
  inorder(root);
  printf("\n%s", "Preorder Traversal: ");
  preorder(root);
  printf("\n%s", "Postorder Traversal: ");
  postorder(root);
  int keysearch = 111, r;
  r = search(root, keysearch);
  if(r == 1) {
    printf("\nThe key %d Found in BST.", keysearch);
  } else {
    printf("\nThe key %d Not Found in BST.", keysearch);
  }
  int keydelete = 10;
  printf("\nDelete %d and inorder\n", keydelete);
  delete(root, keydelete);
  inorder(root);
  return 0;
}
