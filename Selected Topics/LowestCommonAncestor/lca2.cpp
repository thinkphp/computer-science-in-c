#include <iostream>

using namespace std;

struct Node {

	int value;
	struct Node *left;
	struct Node *right;
	Node(int v):value(v),left(nullptr), right(nullptr){}
};

struct Node* build() {
    struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	return root;
}
/*
               1
              / \ 
            2     3
           / \   / \
          4   5 6   7 
         / \  
        8   9  
*/

struct Node* LCA(struct Node* root, int a, int b) {

	   if(!root) return nullptr;

	   if(root->value == a || root->value == b) return root;

	   struct Node* left = LCA(root->left, a, b);

	   struct Node* right = LCA(root->right, a, b);

	   if(left && right) return root;

	   return (left ? left : right);
}

void testLCA(struct Node* root, int a, int b, int expected) {

    struct Node* got = LCA(root, a, b);
    
    string answer = (got->value == expected) ? "OK": "fail";

    cout<<"LCA("<<a<<","<<b<<") = "<<got->value<<" "<<answer;	

    cout<<endl;
}


int main(int argc, char const *argv[])
{

	struct Node *root = build();

    testLCA(root, 8, 5, 2);
    testLCA(root, 4, 9, 4);
    testLCA(root, 9, 2, 2);
    testLCA(root, 6, 7, 3);
   
	
	return 0;
}
