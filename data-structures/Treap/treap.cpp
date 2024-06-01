#include <iostream>
#include <fstream>
#include <random>
#include <climits>

std::ifstream fin("abce.in");
std::ofstream fout("abce.out");

std::random_device rd;
std::mt19937_64 gen64(rd());

struct TreapNode {
    TreapNode(long long key_, long long priority_) : key{key_}, priority{priority_}, left{nullptr}, right{nullptr} {}

    long long key, priority;
    TreapNode *left, *right;
};

void rotateRight(TreapNode *&y) {
    TreapNode *x = y->left, *T2 = x->right;

    x->right = y;
    y->left = T2;
    y = x;
}

void rotateLeft(TreapNode *&x) {
    TreapNode *y = x->right, *T2 = y->left;

    y->left = x;
    x->right = T2;
    x=y;
}

TreapNode* search(TreapNode* root, long long key) {
    if (root == nullptr || root->key == key) {
        return root;
    }

    if (root->key < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

void insert(TreapNode* &root, long long key) {
    if (root == nullptr) {
        root = new TreapNode(key, gen64());
        return;
    }

    if (key <= root->key) {
        insert(root->left, key);

        if (root->left->priority > root->priority) {
            rotateRight(root);
        }
    }
    else {
        insert(root->right, key);

        if (root->right->priority > root->priority) {
            rotateLeft(root);
        }

    }
}

void deleteNode(TreapNode *&root, long long key) {
    if(root == nullptr) return;

    if(key < root->key) {
        deleteNode(root->left, key);
    }
    else if(key > root->key) {
        deleteNode(root->right, key);
    }
    else {
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if(!root->left || !root->right) {
            TreapNode *child;

            if(root->left) child = root->left;
            else child = root->right;

            TreapNode *old = root;
            root = child;

            delete old;
        }
        else {
            if(root->left->priority < root->right->priority) {
                rotateLeft(root);
                deleteNode(root->left, key);
            }
            else {
                rotateRight(root);
                deleteNode(root->right, key);
            }
        }
    }
}

long long maxLessThan(TreapNode *root, long long key) {
    if(root == nullptr) return -1;
    if(root->key == key) return key;

    if(root->key < key) {
        long long k = maxLessThan(root->right, key);

        if(k==-1)
            return root->key;
        return k;
    }
    return maxLessThan(root->left, key);
}

long long minGreaterThan(TreapNode *root, long long key) {
    if(root == nullptr) return -1;
    if(root->key == key) return key;

    if(root->key > key) {
        long long k = minGreaterThan(root->left, key);

        if(k==-1)
            return root->key;
        return k;
    }
    return minGreaterThan(root->right, key);
}

void interval(TreapNode *root, long long left, long long right) {
    if(root == nullptr) return;

    interval(root->left, left, right);
    if(left <= root->key && root->key <= right) {
        fout << root->key << ' ';
    }
    interval(root->right, left, right);
}

int main()
{
    TreapNode *root = nullptr;

    int q;

    fin>>q;
    for(int i = 0; i < q; i++)
    {
        int op, x;
        fin>>op >> x;
        if(op == 1) {
            insert(root, x);
        }
        else if(op == 2) {
            deleteNode(root, x);
        }
        else if(op == 3) {
            fout << (search(root, x) != nullptr) << '\n';
        }
        else if(op == 4) {
            fout << maxLessThan(root, x) <<'\n';
        }
        else if(op == 5) {
            fout<< minGreaterThan(root, x) <<'\n';
        }
        else {
            int y;
            fin>>y;
            interval(root, x, y);
            fout<<'\n';
        }
    }

    fin.close();
    fout.close();

    return 0;
}
