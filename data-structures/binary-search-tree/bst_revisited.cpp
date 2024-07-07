#include <stdio.h>
#include <stdlib.h>
//BST = Binary Search Tree ( insert, search, traversals: inorder, preorder, postorder, remove)
//arbore binar de cautare

//strtok token

typedef struct Node {

       int data;
       struct Node *left;
       struct Node *right;

} Node;

Node *insert(Node *root, int val) {

     if(root == NULL) {

         //root = new Node;aloca spatiu in HEAP pentru Node
         root = (Node*)malloc(sizeof(Node));
         root->data = val;
         root->left = NULL; //0, nullptr
         root->right = NULL; //

     } else {

        if( root->data < val ) {

            root->right = insert(root->right, val);

        } else {

            root->left = insert(root->left, val);
        }

     }

     return root;
}

void inorder(Node *node) {

     if(node) {
       inorder(node->left);
       printf("%d ", node->data);
       inorder(node->right);
     }
}

void preorder(Node *node) {

  if(node) {
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
  }
}

void postorder(Node *node) {

  if(node) {
    printf("%d ", node->data);
    postorder(node->left);
    postorder(node->right);
  }
}

int search(Node *root, int key) {

    if(root == NULL) {

       return 0;

    } else if( root->data > key ) {

       return search(root->left, key);

    } else if(root->data < key ) {

       return search(root->right, key);

    } else {

      return 1;
    }

}

//                  subarborele drept
Node *mostlyLeft(Node *root) {

      while( root->left ) root = root->left;

      return root;
}


//stergerea: se sterge nodul si se inlocuieste cu cel mai din stanga nod din subarborele drept
Node* removeNode(Node *root, int key) {

      if(root == NULL) {

         return root;

      } else if(root->data  > key ) {

          root->left = removeNode(root->left, key);

      } else if(root->data < key ) {

          root->right = removeNode(root->right, key);

      } else {

          if(root->left == NULL && root->right == NULL) {

              free( root );
              return NULL;

          } else if( root->left == NULL) {

            Node *temp = root->right;
            free(root);
            return temp;

          } else if( root->right == NULL)  {

            Node *temp = root->left;
            free(root);
            return temp;

          } else if( root->left != NULL && root->right != NULL ) {

            //cel mai din stanga din subarborele drept
             Node *temp = mostlyLeft( root->right );

             root->data  = temp->data;

             root->right = removeNode(root->right, temp->data);
          }
      }

      return root;
}

int main(int argc, char const *argv[]) {

  Node *root = NULL;

/*
  root = insert(root, 12);
  insert(root, 5);
  insert(root, 4);
  insert(root, 18);
  insert(root, 52);
  insert(root, 22);
  insert(root, 51);
  insert(root, 53);

*/

root = insert(root, 100);
insert(root, 5);
insert(root, 4);
insert(root, 18);
insert(root, 52);
insert(root, 22);
insert(root, 51);
insert(root, 53);

  printf("\nInorder: \n");
  inorder( root );

  printf("\nPreorder: \n");
  preorder( root );

  printf("\nPostorder: \n");
  postorder( root );

  int key_search = 22;

  int answer;

  answer = search( root, key_search );

  if( answer == 1 ) {
    printf("\nThe key: %d Found in BST\n", key_search);
  } else {
    printf("\nThe key: %d Not Found in BST\n", key_search);
  }

  int key_remove = 100;

  if(search(root, key_remove) == 1) {
     printf("\n%s: %d\n", "Stergere Node", key_remove);
     root = removeNode(root, key_remove);
     inorder(root);
  } else {
     printf("\n%s: %d\n", "Nu am cum sa-l sterg pentru ca nu exista in BST", key_remove);
  }

  //free -> elibereaza spatiul de memorie din HEAP
  //malloc - se aloca spatiu in HEAP
  return 0;
}
