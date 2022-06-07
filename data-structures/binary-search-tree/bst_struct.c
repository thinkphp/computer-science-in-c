#include <stdio.h>
#include <malloc.h>
 
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
 
struct Node* insert(struct Node *root, int data) {
 
      if(root == NULL) {
          root = (struct Node*)malloc(sizeof(struct Node));
          root->data = data;
          root->left = NULL;
          root->right = NULL;
      } else {
        if(root->data > data) {
          root->left = insert(root->left, data);
        } else if(root->data < data) {
          root->right = insert(root->right, data);
        }
      }
      return root;
}
 
int search(struct Node *root, int key) {
 
   if(root != NULL) {
 
        if(root->data == key) {
           return 1;
        } else if(root->data > key) {
           return search(root->left, key);
        } else {
           return search(root->right, key);
        }
 
  }
   return 0;
}
 
void inorder(struct Node*root) {
     if(root != NULL) {
       inorder(root->left);
       printf("%d ", root->data);
       inorder(root->right);
     }
}
int main(int argc, char const *argv[]) {
 
  struct Node *root = NULL;
  root = insert(root, 101);
  for(int i = 10; i >= 0; i--)
         insert(root, i)  ;
  inorder(root)           ;
  int keysearch = 1011;
  printf("%d", search(root, keysearch));
  return 0;
}
 
