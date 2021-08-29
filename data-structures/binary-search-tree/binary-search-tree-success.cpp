#include <iostream>

using namespace std;

class BinarySearchTree {

      struct Node {

             int data;

             Node *left;

             Node *right;
      };

      Node *root;

      Node *insert( int value, Node *t) {

            if(t == NULL) {

               t = new Node;

               t->data = value;

               t->left = t->right = NULL;

            } else if( value < t->data ) {

               t->left = insert( value, t->left );

            } else if( value > t->data ) {

               t->right = insert(value, t->right);
            }

          return t;
      }

      Node *findMin(Node *t) {

           if(t == NULL) {

              return NULL;

           } else if( t-> left == NULL ) {

              return t;

           } else {

             return findMin( t->left );
           }
      }

      Node *findMax(Node *t) {

           if(t == NULL) {

              return NULL;

           } else if( t-> right == NULL ) {

              return t;

           } else {

             return findMax( t->right );
           }
      }

      Node* remove(int value, Node *t) {

            Node *temp;

            if(t == NULL) {

               return NULL;

            } else if(value < t->data) {

               t->left = remove(value, t->left);

            } else if(value > t->data) {

              t->right = remove(value, t->right);

            } else if(t->left != NULL && t->right != NULL) {

                temp = findMin(t->right);

                t->data = temp->data;

                t->right = remove(t->data, t->right);

            } else {

                temp = t;

                if(t->left == NULL) {

                   t = t->right;

                } else if(t->right == NULL) {

                   t = t->left;
                }

                delete temp;
            }

            return t;
      }

      void inorder(Node *t) {

           if(t == NULL) return;

           inorder(t->left);

           cout<<t->data<<" ";

           inorder(t->right);
      }

      bool find(int value, Node *t) {

           if(t == NULL) {
             return false;
           } else if(value < t->data) {
             return find(value, t->left);
           } else if(value > t->data) {
             return find(value, t->right);
           } else {
             return true;
           }
      }


      Node* makeEmpty(Node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
      }

      public:

         //constructor
         BinarySearchTree() {

             root = NULL;
         }

         //destructor
         ~BinarySearchTree() {

             root = makeEmpty( root );
         }

         void insert(int value) {

             root = insert(value, root);
         }

         void remove(int value) {

             root = remove(value, root);
         }

         bool search( int value ) {

              return find(value, root);
         }

         void display() {

              inorder( root );

              cout<<"\n";
         }
};

int main(int argc, char const *argv[]) {

   BinarySearchTree bst;

        bst.insert(-8);
        bst.insert(-71);
        bst.insert(117);
        bst.insert(-1);
        bst.insert(2);
        bst.insert(13);
        bst.insert(7);
        bst.insert(8);
        bst.insert(17);
        bst.display();
        //search for the key = 8
        cout<<bst.search( 8 );

  return 0;
}
