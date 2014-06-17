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

//global pointer root that is initial NULL
Node *root = NULL;


//prototypes functions
void  read();
void  display();
void  sort();
void insert(int val);
void inorder(Node *p);

//number of items from array
int n,

    //defined an array of 100 items integers
    v[100];

//input output file
fstream fin("c:\\file.in",ios::in),

	fout("c:\\file.out",ios::out);



//main program
void main() {

     //firstly, clear screen
     clrscr();

     //display on screen
     cout<<"\n\n\nBinary Search Tree Inorder\n\n\n";

     //read the input vector
     read();

     //display the vector
     cout<<"Input:";
     display();

     //then display the sorted array
     cout<<"\n\nOutput:\n";

     //insert into Binary Tree Search and then walk inorder to get sorted
     sort();

     //press any key for exit
     cout<<"\n\n\nPress any key for exit!";
     getch();
}


//read input data
void read() {

     int i;

     fin>>n;

     for(i = 0; i < n; i++) {

	 fin>>v[i];
     }

     fin.close();
}

//display the data on screen
void display() {

     int i;

     cout<<"\n";

     for(i = 0; i < n; i++) {

	 cout<<v[i]<<" ";
     }

     cout<<"\n";
}

//sorting by Binary Tree Search
void sort() {

     //for each item from array execute the following instructions
     for(int i = 0; i < n; i++) {

	 //insert one by one the elements into Binary Tree Search
	 insert( v[i] );
     }

     //walk inorder and finally the array is sorted
     inorder( root );
}


void insert(int val) {

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
