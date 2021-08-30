#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
 
typedef struct bst {
       int data;
       struct bst *left;
       struct bst *right;
} tree;
 
 
tree *insert(int value, tree *t) {
 
     if(t == NULL) {
 
       t = (tree*)malloc(sizeof(tree));
       t->data = value;
       t->left = NULL;
       t->right = NULL;
 
     } else if(value < t->data) {
 
       t->left = insert(value, t->left);
 
     } else if(value >= t->data) {
 
       t->right = insert(value, t->right);
     }
 
     return t;
}
 
void inorder(tree *t) {
 
     if(t != NULL)
     inorder(t->left),
     printf("%d ", t->data),
     inorder(t->right);
}
 
int main(int argc, char const *argv[]) {
 
  freopen(FIN, "r", stdin);
 
  freopen(FOUT, "w", stdout);
 
  tree *root = NULL;
 
  int n, x;
 
  scanf("%d", &n);
 
  for(int i = 0; i < n; ++i)
 
      scanf("%d", &x),
 
      root = insert( x, root );
 
  inorder( root );
 
  return 0;
  }
