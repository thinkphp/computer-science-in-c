#include <iostream.h>
#include <conio.h>
#include <fstream.h>

//Binary Tree Search with Inorder Traversal = Sorting

//define a Node
typedef struct Node{

       int info;//info
       Node *left;//left subtree
       Node *right;//right subtree

} Node;


//prototypes functions
void  read();
void  display();
void  sort(Node *root);
void insert(Node *&root,int val);
void inorder(Node *p);

int n,

    v[100];

fstream fin("c:\\file.in",ios::in),

	fout("c:\\file.out",ios::out);



void main() {

     Node *root = NULL;
 
     //firstly, clear screen
     clrscr();

     cout<<"\n\n\nBinary Search Tree Inorder\n\n\n";

     //read the vector
     read();

     //display the vector
     cout<<"Input:";
     display();

     //then display the sorted array
     cout<<"\n\nOutput:\n";

     sort( root );


     //press any key for exit
     cout<<"\n\n\nPress any key for exit!";
     getch();
}

void read() {

     int i;

     fin>>n;

     for(i = 0; i < n; i++) {

	 fin>>v[i];
     }

     fin.close();
}

void display() {

     int i;

     cout<<"\n";

     for(i = 0; i < n; i++) {

	 cout<<v[i]<<" ";
     }

     cout<<"\n";
}

void sort(Node *root) {

     //for each item from array execute the following instructions
     for(int i = 0; i < n; i++) {

	 //insert one by one the elements into Binary Tree Search
	 insert(root, v[i]);
     }

     //walk inorder and finally the array is sorted
     inorder( root );
}


void insert(Node* &root, int val) {

     Node *current, *newNode;

     if( root ) {

	current = root;

	while(1){

	     if(val < current->info) {

		if(current->left) {

		   current = current->left;

		} else {

		   //allocation space in heap for newNode
		   newNode = new Node;

		   newNode->info = val;
		   newNode->left = 0;
		   newNode->right = 0;

		   current->left = newNode;

		   break;

		}

	     } else {

		if(current->right) {

		   current = current->right;

		} else {

		   newNode = new Node;
		   newNode->info = val;
		   newNode->left = 0;
		   newNode->right = 0;

		   current->right = newNode;

		   break;
		}
	     }
	}

     } else {

       root = new Node;

       root->info = val;
       root->left = 0;
       root->right = 0;

     }
}


void inorder(Node *p){

     if(p->left) {
       inorder(p->left);
     }

     cout<<p->info<<" ";
     fout<<p->info<<" ";

     if(p->right){
       inorder(p->right);
     }
}
