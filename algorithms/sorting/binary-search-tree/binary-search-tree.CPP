#include <iostream.h>
#include <conio.h>
#include <fstream.h>

struct Node{
       int info;
       Node *left;
       Node *right;

} *root;

int index=0;


//prototypes functions
void  read();
void  display();

void  sort();

void insert(Node* &v,int val);
void inorder(Node* &p);
void traversal(Node* &p);

int n,

    v[100];

fstream fin("c:\\file.in",ios::in),

	fout("c:\\file.out",ios::out);



void main() {


     //firstly, clear screen
     clrscr();

     cout<<"\n\n\nBinary Search Tree Inorder\n\n\n";

     //read the vector
     read();

     //display the vector
     cout<<"Input:";
     display();

     //method merge sort in action
     //then display the sorted array
     cout<<"\n\nOutput:\n";
     sort();


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

void sort() {

     for(int i=0;i<n;i++) {

	 insert(root,v[i]);
     }

     traversal(root);
}


void insert(Node* &v,int val) {

     Node *current, *newNode;

     if(root) {

	current = root;

	while(1){

	     if(val < current->info) {

		if(current->left) {

		   current = current->left;

		} else {

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


void traversal(Node* &p){

     if(p->left) {
       traversal(p->left);
     }

     cout<<p->info<<" ";
     fout<<p->info<<" ";

     if(p->right){
       traversal(p->right);
     }

}
