#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include<time.h>
 
struct TreapNode {
       int key,
           priority;
       struct TreapNode *left;
       struct TreapNode *right;
};
 
struct TreapNode *create(int key) {
 
      struct TreapNode *node = (struct TreapNode*)malloc(sizeof(struct TreapNode));
                        node->key = key;
                        node->priority = rand()%100;
                        node->left = NULL;
                        node->right = NULL;
              return node;
}
 
struct TreapNode* leftRotate(struct TreapNode*root) {
 
  struct TreapNode* x = root->right;
  struct TreapNode* y = x->left;
 
  x->left = root;
  root->right = y;
  return x;
}
 
struct TreapNode* rightRotate(struct TreapNode*root) {
 
       struct TreapNode* x = root->left;
       struct TreapNode* y = x->right;
       x->right = root;
       root->left = y;
       return x;
}
 
struct TreapNode * insert(struct TreapNode *root, int key) {
 
     if(!root) {
 
       return create(key);
     }
     //if the key is smaller than root
     if(key <= root->key) {
 
        root->left = insert(root->left, key);
 
        if(root->left->priority > root->priority) {
          root = rightRotate(root);
        }
 
     } else {
 
       root->right = insert(root->right, key);
 
       if(root->right->priority > root->priority) {
 
         root = leftRotate(root);
       }
     }
     return root;
}
 
void inorder(struct TreapNode *root) {
 
     if(root->left) {
 
       inorder(root->left);
 
     }
 
     printf("(%d)", root->key);
 
     if(root->right) {
 
           inorder(root->right);
     }
}
 
 
struct TreapNode* search(struct TreapNode* root, int key) {
 
           if(root == NULL || root->key == key) {
              return root;
           } else if(root->key < key) {
             return search(root->right, key);
           } else {
             return search(root->left, key);
           }
}
 
int main(int argc, char const *argv[]) {
 
  srand(time(0));
  struct TreapNode* root = NULL;
  root = insert(root, 41);
  root = insert(root, 10);
  root = insert(root, 43);
  root = insert(root, 13);
  root = insert(root, 23);
  inorder(root);
  int key = 10;
  struct TreapNode*ans = search(root, key);
  if(ans == NULL) {
    printf("%s", "Not Found");
  } else {
    printf("%s", "Is Found");
  }
  return 0;
}
