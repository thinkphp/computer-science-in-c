#include <stdio.h>
#include <malloc.h>

struct Node {

       int data;
       struct Node *left, *right;
};

struct Node* insert(struct Node *root, int data) {

      if(root == NULL) {

         root = (struct Node*)malloc(sizeof(struct Node));

         root->data = data;

         root->left = NULL;           

         root->right = NULL;

      } else if(root->data > data) {
              
         root->left = insert(root->left, data);           

      } else {

         root->right = insert(root->right, data);           
      }

    return root;
};

struct Node *findMin(struct Node *root) {

       while(root->left != NULL) {

             root = root->left;
       }  

   return root;
}

//method to vizit nodes in Inorder
void inorder(struct Node *root) {

     if(root != NULL) {

        inorder(root->left);

        printf("%d ", root->data);

        inorder(root->right);
     } 
}

struct Node* delete(struct Node *root, int x) {

       if(root == NULL) return root;

       else if(root->data > x) root->left = delete(root->left, x); 

            else if(root->data < x) root->right = delete(root->right, x); 

       else { 

            //case 1: no child
            if(root->left == NULL && root->right == NULL) {

                free(root);
          
                root = NULL;

            //case 2: one child
            } else if(root->left == NULL) {

                    struct Node *temp = root;
                           root = root->right;
                           free(temp);

            } else if(root->right == NULL) {

                    struct Node *temp = root;
                           root = root->left;
                           free(temp);

            //case 3: two children
            } else if(root->left != NULL && root->right != NULL) {

                   struct Node *temp = findMin(root->right);
                          root->data = temp->data;
                          root->right = delete(root->right, temp->data);
            }

 
       }

       return root;
};
  

int main() {

    struct Node *root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
         
    inorder(root);

    delete(root, 40);
    printf("\n");

    inorder(root); 
 return(0);

}
