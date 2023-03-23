#include <stdio.h>
#include <malloc.h>
typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;
int j,
       pri[100],
       p[100],
    i, n;

char expression[ 100 ],
     expr[100];

Node* treebin(int lo, int hi, char e[100], int p[100]) {
           int i,j, min;
           min = p[hi];
           i = hi;
           for(j = hi; j >= lo; j--) {
             if(p[j]<min){
               min = p[j];
               i = j;
             }
           }
           Node *c = (Node*)malloc(sizeof(Node));
           c->data = e[i];
           if(lo == hi) c->left = c->right = 0;
           else {
             c->left = treebin(lo, i - 1, e, p);
             c->right = treebin(i + 1, hi, e, p);
           }
           return c;
}

void postorder(Node *root) {
  if(root->left) {
    postorder(root->left);
  }
  if(root->right) {
    postorder(root->right);
  }
  printf("%c ", root->data);
}

//we'll transform (a+b)*c => ab+c*
int str_length(char* str) {

    // initializing count variable (stores the length of the string)
    int count;

    // incrementing the count till the end of the string
    for (count = 0; str[count] != '\0'; ++count);

    // returning the character count of the string
    return count;
};

int main() {

       scanf( "%s", expression );

       n = str_length( expression );

       j = 0;

       for( int i = 0; i < n; ++i ) {

            char x = expression[ i ];

            switch( x ) {
               case '(': j += 10;
               break;
               case ')': j -= 10;
               break;
               case '+':
               pri[i] = j + 1;
               break;
               case '-':
               pri[i] = j + 1;
               break;
               case '*':
               pri[i] = j + 10;
               break;
               case '/':
               pri[i] = j + 10;
               break;
               default:
               pri[i] = 1000;
            }
       }

       j = 0;
       for( int k = 0; k < n; ++k ) {
         if(expression[k] != '(' && expression[k] != ')') {
            expr[j] = expression[k];
            p[j] = pri[k];
            j++;
         }
       }

       for( int k = 0; k < j; ++k ) {

           printf("%c-%d\n", expr[k], p[k]);
       }

       Node *root = treebin(0, j-1, expr, p);

       postorder(root);
}
