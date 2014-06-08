#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Node{
	int info;
	struct Node *left;
	struct Node *right;
};

struct Node *root = NULL;

/**
 *
 * Sorting using Binary Tree Search and Inorder Traversal
 *
 */

void read(const char *filename);
void display();
void write(const char *filename);
void insertTree(int val);
void inorder(struct Node *root);
void sort();
void push(int val);

FILE *fin, *fout;

int output[50], ind = 0;

//declare an array of integers
int v[30],
    //store the number of elements
    n;

//main function
void main() {

     //clear screen
     //clrscr();
     ind = 0;

     read("c:\\file.in");

     printf("Sorting using Binary Tree Search and Inorder Traversal\n------------------------------------------------------\n\n%s:\n","Input");
     display();

     printf("\n\n\n%s:\n","Output");
     sort();

     write("c:\\file.out");

     printf("\n\nCheck file out\nPress any key for exit!\nhttp:\\thinkphp.ro\n");
     getch();
}

void read(const char *filename) {

     fin = fopen(filename,"r");

     fscanf(fin,"%d",&n);

     int i = 0;

     while(!feof(fin)) {

	   fscanf(fin,"%d",&v[i++]);
     }

     fclose(fin);
}

void display() {
     int i;
     for(i = 0; i < n; i++) {

	 printf("%d ", v[ i ]);
     }
}

void insertTree(int val) {

     struct Node *curr, *newNode;

     if(root == NULL) {

	root = (struct Node*)malloc(sizeof(struct Node));

	root->info = val;
	root->left = NULL;
	root->right = NULL;

     } else {


       curr = root;

     while(1) {

       if(val < curr->info) {

	  if(curr->left) {

	     curr = curr->left;

	  } else {

	     newNode = (struct Node*)malloc(sizeof(struct Node));

	     newNode->info = val;
	     newNode->left = NULL;
	     newNode->right = NULL;

	     curr->left = newNode;
	     break;
	  }

       } else {


	  if(curr->right) {

	     curr = curr->right;

	  } else {

	     newNode = (struct Node*)malloc(sizeof(struct Node));

	     newNode->info = val;
	     newNode->left = NULL;
	     newNode->right = NULL;

	     curr->right = newNode;
	     break;
	  }


       }

     }//endwhile


   }//endif
}


void inorder(struct Node *node) {

     if(node->left) {

	inorder(node->left);
     }

     printf("%d ",node->info);

     push(node->info);

     if(node->right) {

	inorder(node->right);
     }
}

void write(const char *filename) {

     int i;

     fout = fopen(filename, "w");

     for(i = 0;i < n;i++) {

	 fprintf(fout,"%d ",output[i]);
     }

     fclose(fout);

}

void sort() {

     int i;

     for(i = 0; i < n; i++) {

	 insertTree( v[ i ] );
     }

     inorder( root );
}

void push(int val) {

     output[ind] = val;
     ind = ind + 1;
}