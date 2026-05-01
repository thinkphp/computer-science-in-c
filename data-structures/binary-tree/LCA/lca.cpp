#include <iostream>

using namespace std;

struct Node {
	int value;
	struct Node*left;
	struct Node*right;
	Node(int v):value(v), left(nullptr), right(nullptr){}
};

struct Node* buildTree() {

	struct Node* root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

    return root;
}

struct Node* LCA(struct Node *root, int a, int b) {

	   if(!root) return nullptr;//case 1

	   if(root->value == a || root->value == b) return root;

	   struct Node* left = LCA(root->left, a, b);
	   struct Node* right = LCA(root->right, a, b);

	   if(left && right) return root;

	   return left ? left : right;
}

void testLCA(struct Node *root, int a, int b, int expected) {

	 struct Node *result = LCA(root, a, b);

	 int got = result ? result->value : -1;

	 cout<<"LCA("<<a<<","<<b<<") = "<<got<<" ";

	 if(got == expected) {

	 	cout<<"OK"<<endl;

	 } else {

	 	cout<<"Fail!"<<" "<<"expected "<<expected<<endl;
	 }

}

int main(int argc, char const *argv[])
{
	struct Node *root = buildTree();
	
	cout<<"Tree:\n";
	cout<<"        1\n";
	cout<<"       /  \\ \n";
	cout<<"      2     3 \n";
	cout<<"     / \\   / \\ \n"; 
	cout<<"    4   5  6  7  \n";
	
	testLCA(root, 4, 5, 2);
	testLCA(root, 4, 6, 2);
	testLCA(root, 3, 7, 3);
	testLCA(root, 2, 4, 2);
	testLCA(root, 1, 7, 1);
	return 0;
}
