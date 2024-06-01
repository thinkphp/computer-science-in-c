#include <iostream>
#include <fstream>
using namespace std;

ofstream f("abce.out");
ifstream in("abce.in");

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* node1;
int op, key, stop;

void printRange(Node* root) {
    if (root != nullptr) {
        printRange(root->left);
        if (root->key >= key && root->key <= stop)
            f << root->key << " ";
        printRange(root->right);
    }
}

void printInorder(Node* root) {
    if (root != nullptr) {
        printInorder(root->left);
        cout << root->key << " ";
        printInorder(root->right);
    }
}

Node* rotateLeft(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node* rotateRight(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node* splay(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root;

    if (root->key > key) {
        if (root->left == nullptr)
            return root;
        if (root->left->key > key) {
            root->left->left = splay(root->left->left, key);
            if (root->left->left != nullptr)
                root->left = rotateLeft(root->left);
        } else if (root->left->key < key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != nullptr)
                root->left = rotateRight(root->left);
        }
        if (root->left == nullptr)
            return root;
        return rotateLeft(root);
    } else {
        if (root->right == nullptr)
            return root;
        if (root->right->key > key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = rotateLeft(root->right);
        } else if (root->right->key < key) {
            root->right->right = splay(root->right->right, key);
            if (root->right->right != nullptr)
                root->right = rotateRight(root->right);
        }
        if (root->right == nullptr)
            return root;
        return rotateRight(root);
    }
}

bool search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->key == key)
        return true;
    if (root->key > key)
        return search(root->left, key);
    return search(root->right, key);
}

Node* deletion(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    if (search(root, key))
        root = splay(root, key);
    else
        return root;

    if (root->left == nullptr)
        return root->right;
    else {
        Node* aux = root->right;
        root = splay(root->left, key);
        root->right = aux;
    }

    return root;
}

Node* insert(Node* root, int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = newNode->right = nullptr;

    if (root == nullptr)
        return newNode;

    root = splay(root, key);

    if (root->key == key)
        return root;

    if (root->key > key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }
    return newNode;
}

int getSmallest(Node* root, int key) {
    Node* aux;

    if (search(root, key))
        return key;
    root = insert(root, key);
    if (root->left == nullptr) {
        node1 = deletion(root, key);
        return 0;
    }
    aux = root->left;

    while (aux->right != nullptr)
        aux = aux->right;
    node1 = deletion(root, key);
    return aux->key;
}

int getBiggest(Node* root, int key) {
    Node* aux;
    if (search(root, key))
        return key;
    root = insert(root, key);
    if (root->right == nullptr) {
        node1 = deletion(root, key);
        return 0;
    }
    aux = root->right;

    while (aux->left != nullptr)
        aux = aux->left;
    node1 = deletion(root, key);
    return aux->key;
}

int main() {
    Node* root = nullptr;
    node1 = root;
    int q;
    in >> q;
    for (int i = 0; i < q; ++i) {
        in >> op >> key;
        if (op == 1) {
            node1 = insert(node1, key);
        } else if (op == 2) {
            node1 = deletion(node1, key);
        } else if (op == 3) {
            f << search(node1, key) << endl;
        } else if (op == 4) {
            f << getSmallest(node1, key) << endl;
        } else if (op == 5) {
            f << getBiggest(node1, key) << endl;
        } else if (op == 6) {
            in >> stop;
            printRange(node1);
            f << endl;
        }
    }
    return 0;
}
