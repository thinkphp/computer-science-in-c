#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

#include <iostream>
#include <queue>
using namespace std;

enum COLOR { RED, BLACK };

class Node {
public:
    int val;
    COLOR color;
    Node *left, *right, *parent;

    explicit Node(int val) : val(val) {
        parent = left = right = nullptr;

        // Node is created during insertion
        // Node is red at insertion
        color = RED;
    }
    void in_order(int x, int y, std::ofstream& fout)
    {
        if( x < val )
        {
            if(left != nullptr)
                left->in_order(x,y,fout);
        }
        if ( x<= val && val<=y )
        {
            fout<<val<<" ";
        }
        if (val < y)
        {
            if(right != nullptr)
                right->in_order(x,y,fout);
        }
    }

    // returns pointer to uncle
    Node *uncle() const {
        // If no parent or grandparent, then no uncle
        if (parent == nullptr or parent->parent == nullptr)
            return nullptr;

        if (parent->isOnLeft())
            // uncle on right
            return parent->parent->right;
        else
            // uncle on left
            return parent->parent->left;
    }

    // check if node is left child of parent
    bool isOnLeft() { return this == parent->left; }

    // returns pointer to sibling
    Node *sibling() {
        // sibling null if no parent
        if (parent == nullptr)
            return nullptr;

        if (isOnLeft())
            return parent->right;

        return parent->left;
    }

    // moves node down and moves given node in its place
    void moveDown(Node *nParent) {
        if (parent != nullptr) {
            if (isOnLeft()) {
                parent->left = nParent;
            } else {
                parent->right = nParent;
            }
        }
        nParent->parent = parent;
        parent = nParent;
    }

    bool hasRedChild() {
        return (left != nullptr and left->color == RED) or
               (right != nullptr and right->color == RED);
    }
};

class RBTree {
    Node *root;

    // left rotates the given node
    void leftRotate(Node *x) {
        // new parent will be node's right child
        Node *nParent = x->right;

        // update root if current node is root
        if (x == root)
            root = nParent;

        x->moveDown(nParent);

        // connect x with new parent's left element
        x->right = nParent->left;
        // connect new parent's left element with node
        // if it is not null
        if (nParent->left != nullptr)
            nParent->left->parent = x;

        // connect new parent with x
        nParent->left = x;
    }

    void rightRotate(Node *x) {
        // new parent will be node's left child
        Node *nParent = x->left;

        // update root if current node is root
        if (x == root)
            root = nParent;

        x->moveDown(nParent);

        // connect x with new parent's right element
        x->left = nParent->right;
        // connect new parent's right element with node
        // if it is not null
        if (nParent->right != nullptr)
            nParent->right->parent = x;

        // connect new parent with x
        nParent->right = x;
    }

    void swapColors(Node *x1, Node *x2) {
        COLOR temp;
        temp = x1->color;
        x1->color = x2->color;
        x2->color = temp;
    }

    void swapValues(Node *u, Node *v) {
        int temp;
        temp = u->val;
        u->val = v->val;
        v->val = temp;
    }

    // fix red red at given node
    void fixRedRed(Node *x) {
        // if x is root color it black and return
        if (x == root) {
            x->color = BLACK;
            return;
        }

        // initialize parent, grandparent, uncle
        Node *parent = x->parent, *grandparent = parent->parent,
                *uncle = x->uncle();

        if (parent->color != BLACK) {
            if (uncle != nullptr && uncle->color == RED) {
                // uncle red, perform recoloring and recurse
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                fixRedRed(grandparent);
            } else {
                // Else perform LR, LL, RL, RR
                if (parent->isOnLeft()) {
                    if (x->isOnLeft()) {
                        // for left right
                        swapColors(parent, grandparent);
                    } else {
                        leftRotate(parent);
                        swapColors(x, grandparent);
                    }
                    // for left left and left right
                    rightRotate(grandparent);
                } else {
                    if (x->isOnLeft()) {
                        // for right left
                        rightRotate(parent);
                        swapColors(x, grandparent);
                    } else {
                        swapColors(parent, grandparent);
                    }

                    // for right right and right left
                    leftRotate(grandparent);
                }
            }
        }
    }

    // find node that do not have a left child
    // in the subtree of the given node
    Node *successor(Node *x) {
        Node *temp = x;

        while (temp->left != nullptr)
            temp = temp->left;

        return temp;
    }

    // find node that replaces a deleted node in BST
    Node *BSTreplace(Node *x) {
        // when node have 2 children
        if (x->left != nullptr and x->right != nullptr)
            return successor(x->right);

        // when leaf
        if (x->left == nullptr and x->right == nullptr)
            return nullptr;

        // when single child
        if (x->left != nullptr)
            return x->left;
        else
            return x->right;
    }

    // deletes the given node
    void deleteNode(Node *v) {
        Node *u = BSTreplace(v);

        // True when u and v are both black
        bool uvBlack = ((u == nullptr or u->color == BLACK) and (v->color == BLACK));
        Node *parent = v->parent;

        if (u == nullptr) {
            // u is nullptr therefore v is leaf
            if (v == root) {
                // v is root, making root null
                root = nullptr;
            } else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v->sibling() != nullptr)
                        // sibling is not null, make it red"
                        v->sibling()->color = RED;
                }

                // delete v from the tree
                if (v->isOnLeft()) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            }
            delete v;
            return;
        }

        if (v->left == nullptr or v->right == nullptr) {
            // v has 1 child
            if (v == root) {
                // v is root, assign the value of u to v, and delete u
                v->val = u->val;
                v->left = v->right = nullptr;
                delete u;
            } else {
                // Detach v from tree and move u up
                if (v->isOnLeft()) {
                    parent->left = u;
                } else {
                    parent->right = u;
                }
                delete v;
                u->parent = parent;
                if (uvBlack) {
                    // u and v both black, fix double black at u
                    fixDoubleBlack(u);
                } else {
                    // u or v red, color u black
                    u->color = BLACK;
                }
            }
            return;
        }

        // v has 2 children, swap values with successor and recurse
        swapValues(u, v);
        deleteNode(u);
    }

    void fixDoubleBlack(Node *x) {
        if (x == root)
            // Reached root
            return;

        Node *sibling = x->sibling(), *parent = x->parent;
        if (sibling == nullptr) {
            // No sibling, double black pushed up
            fixDoubleBlack(parent);
        } else {
            if (sibling->color == RED) {
                // Sibling red
                parent->color = RED;
                sibling->color = BLACK;
                if (sibling->isOnLeft()) {
                    // left case
                    rightRotate(parent);
                } else {
                    // right case
                    leftRotate(parent);
                }
                fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling->hasRedChild()) {
                    // at least 1 red children
                    if (sibling->left != nullptr and sibling->left->color == RED) {
                        if (sibling->isOnLeft()) {
                            // left left
                            sibling->left->color = sibling->color;
                            sibling->color = parent->color;
                            rightRotate(parent);
                        } else {
                            // right left
                            sibling->left->color = parent->color;
                            rightRotate(sibling);
                            leftRotate(parent);
                        }
                    } else {
                        if (sibling->isOnLeft()) {
                            // left right
                            sibling->right->color = parent->color;
                            leftRotate(sibling);
                            rightRotate(parent);
                        } else {
                            // right right
                            sibling->right->color = sibling->color;
                            sibling->color = parent->color;
                            leftRotate(parent);
                        }
                    }
                    parent->color = BLACK;
                } else {
                    // 2 black children
                    sibling->color = RED;
                    if (parent->color == BLACK)
                        fixDoubleBlack(parent);
                    else
                        parent->color = BLACK;
                }
            }
        }
    }

    // prints level order for given node
    void levelOrder(Node *x) {
        if (x == nullptr)
            // return if node is null
            return;

        // queue for level order
        queue<Node *> q;
        Node *curr;

        // push x
        q.push(x);

        while (!q.empty()) {
            // while q is not empty
            // dequeue
            curr = q.front();
            q.pop();

            // print node value
            cout << curr->val << " ";

            // push children to queue
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }

    // prints inorder recursively
    void inorder(Node *x) {
        if (x == nullptr)
            return;
        inorder(x->left);
        cout << x->val << " ";
        inorder(x->right);
    }

public:
    // constructor
    // initialize root
    RBTree() { root = nullptr; }

    Node *getRoot() { return root; }

    // searches for given value
    // if found returns the node (used for delete)
    // else returns the last node while traversing (used in insert)

    bool contains(int key)
    {
        Node* current=root;
        while(current != nullptr)
        {
            int current_value = current->val;
            if (current_value == key) {
                return true;
            }
            if (current_value > key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }
    Node *search(int n) {
        Node *temp = root;
        while (temp != nullptr) {
            if (n < temp->val) {
                if (temp->left == nullptr)
                    break;
                else
                    temp = temp->left;
            } else if (n == temp->val) {
                break;
            } else {
                if (temp->right == nullptr)
                    break;
                else
                    temp = temp->right;
            }
        }

        return temp;
    }
    int maxkey(int key){
        int max=INT_MIN;
        Node* current=root;
        while(current != nullptr)
        {
            int current_value = current->val;
            if( current_value <= key && current_value > max)
                max = current_value;
            if (current_value == key) {
                break;
            }
            if (current_value > key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return max;
    }
    int minkey(int key){
        int min=INT_MAX;
        Node* current=root;
        while(current != nullptr)
        {
            int current_value = current->val;
            if( current_value >= key && current_value < min)
                min = current_value;
            if (current_value == key) {
                break;
            }
            if (current_value > key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return min;
    }
    // inserts the given value to tree
    void insert(int n) {
        Node *newNode = new Node(n);
        if (root == nullptr) {
            // when root is null
            // simply insert value at root
            newNode->color = BLACK;
            root = newNode;
        } else {
            Node *temp = search(n);

            if (temp->val == n) {
                // return if value already exists
                return;
            }

            // if value is not found, search returns the node
            // where the value is to be inserted

            // connect new node to correct node
            newNode->parent = temp;

            if (n < temp->val)
                temp->left = newNode;
            else
                temp->right = newNode;

            // fix red red violation if exists
            fixRedRed(newNode);
        }
    }

    // utility function that deletes the node with given value
    void deleteByVal(int n) {
        if (root == nullptr)
            // Tree is empty
            return;

        Node *v = search(n), *u;

        if (v->val != n) {
            cout << "No node found to delete with value:" << n << endl;
            return;
        }

        deleteNode(v);
    }

    // prints inorder of the tree
    void printInOrder() {
        cout << "Inorder: " << endl;
        if (root == nullptr)
            cout << "Tree is empty" << endl;
        else
            inorder(root);
        cout << endl;
    }

    // prints level order of the tree
    void printLevelOrder() {
        cout << "Level order: " << endl;
        if (root == nullptr)
            cout << "Tree is empty" << endl;
        else
            levelOrder(root);
        cout << endl;
    }
    void in_order(int x, int y, std::ofstream& fout)
    {
        root->in_order(x,y,fout);
    }
};

int main() {

    std::ifstream fin("abce.in");
    std::ofstream fout("abce.out");
    int n,q,x,y;
    fin>>n;
    RBTree rb;
    for(int i=1;i<=n;i++)
    {
        fin >> q;
        fin >> x;
        switch (q) {
            case 1: {
                rb.insert(x);
                break;
            }
            case 2: {
                rb.deleteByVal(x);
                break;
            }
            case 3:{
                fout<<rb.contains(x)<<"\n";
                break;
            }
            case 4:{
                fout<<rb.maxkey(x)<<"\n";
                break;
            }
            case 5:{
                fout<<rb.minkey(x)<<"\n";
                break;
            }
            case 6: {
                fin >> y;
                rb.in_order(x, y, fout);
                fout<<"\n";
                break;
            }
            default: {
                break;
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}
