#include <bits/stdc++.h>

using namespace std;

ifstream fin("abce.in");
ofstream fout("abce.out");

struct node {
    node *leftNode, *rightNode, *parentNode;
    int data;
};

class splayTree {
   private:
    node* rootNode;

    void rotateLeft(node* Node) {
        node* curr = Node->rightNode;

        if (curr != NULL) {
            Node->rightNode = curr->leftNode;

            if (curr->leftNode != NULL) {
                curr->leftNode->parentNode = Node;
            }

            curr->parentNode = Node->parentNode;
        }

        if (Node->parentNode == NULL) {
            this->rootNode = curr;
        } else if (Node == Node->parentNode->leftNode) {
            Node->parentNode->leftNode = curr;
        } else {
            Node->parentNode->rightNode = curr;
        }

        if (curr != NULL) {
            curr->leftNode = Node;
        }

        Node->parentNode = curr;
    }

    void rotateRight(node* Node) {
        node* curr = Node->leftNode;

        if (curr != NULL) {
            Node->leftNode = curr->rightNode;

            if (curr->rightNode != NULL) {
                curr->rightNode->parentNode = Node;
            }

            curr->parentNode = Node->parentNode;
        }

        if (Node->parentNode == NULL) {
            this->rootNode = curr;
        } else if (Node == Node->parentNode->leftNode) {
            Node->parentNode->leftNode = curr;
        } else {
            Node->parentNode->rightNode = curr;
        }

        if (curr != NULL) {
            curr->rightNode = Node;
        }

        Node->parentNode = curr;
    }

    void splay(node* node) {
        while (node->parentNode != NULL) {
            // ZIG
            if (node->parentNode->parentNode == NULL) {
                if (node->parentNode->leftNode == node) {
                    rotateRight(node->parentNode);
                } else {
                    rotateLeft(node->parentNode);
                }
            }

            // ZIG-ZIG or ZAG-ZAG
            else if (node->parentNode->leftNode == node && node->parentNode->parentNode->leftNode == node->parentNode) {
                rotateRight(node->parentNode->parentNode);
                rotateRight(node->parentNode);
            } else if (node->parentNode->rightNode == node && node->parentNode->parentNode->rightNode == node->parentNode) {
                rotateLeft(node->parentNode->parentNode);
                rotateLeft(node->parentNode);
            }

            // ZIG-ZAG or ZAG-ZIG
            else if (node->parentNode->leftNode == node && node->parentNode->parentNode->rightNode == node->parentNode) {
                rotateRight(node->parentNode);
                rotateLeft(node->parentNode);
            } else {
                rotateLeft(node->parentNode);
                rotateRight(node->parentNode);
            }
        }
    }

    void inOrderPrint(node* node, int x, int y) {
    if (node == NULL) {
        return;
    }

    if (node->data >= x && node->data <= y) {
        inOrderPrint(node->leftNode, x, y);
        fout << node->data << " ";
        inOrderPrint(node->rightNode, x, y);
    } else if (node->data < x) {
        inOrderPrint(node->rightNode, x, y);
    } else {
        inOrderPrint(node->leftNode, x, y);
    }
}

   public:
    splayTree() { rootNode = NULL; }

    void insertNode(int data) {
        node* newNode = new node;
        newNode->data = data;
        newNode->leftNode = NULL;
        newNode->rightNode = NULL;
        newNode->parentNode = NULL;

        if (this->rootNode == NULL) {
            this->rootNode = newNode;
        } else {
            node* temp = this->rootNode;
            node* parent = NULL;
            while (temp != NULL) {
                parent = temp;
                if (data > temp->data) {
                    temp = temp->rightNode;
                } else {
                    temp = temp->leftNode;
                }
            }

            newNode->parentNode = parent;
            if (parent->data < data) {
                parent->rightNode = newNode;
            } else {
                parent->leftNode = newNode;
            }
        }
        splay(newNode);
    }

    node* searchNode(int data) {
        node* temp = this->rootNode;

        while (temp != NULL) {
            if (data > temp->data) {
                temp = temp->rightNode;
            } else if (data < temp->data) {
                temp = temp->leftNode;
            } else {
                splay(temp);
                return temp;
            }
        }
        return NULL;
    }

    void deleteNode(int data) {
        // Search for nodeToDelete and splay it to the root
        node* nodeToDelete = searchNode(data);
        if (nodeToDelete == NULL) {
            return;
        }
        splay(nodeToDelete);

        // If the node has both left and right children, find its successor
        // and replace it with nodeToDelete
        if (nodeToDelete->leftNode != NULL && nodeToDelete->rightNode != NULL) {
            node* successor = nodeToDelete->rightNode;
            while (successor->leftNode != NULL) {
                successor = successor->leftNode;
            }
            nodeToDelete->data = successor->data;
            nodeToDelete = successor;
        }

        // Get the child node of nodeToDelete
        node* child = NULL;
        if (nodeToDelete->leftNode != NULL) {
            child = nodeToDelete->leftNode;
        } else if (nodeToDelete->rightNode != NULL) {
            child = nodeToDelete->rightNode;
        }

        // Remove nodeToDelete
        if (nodeToDelete->parentNode == NULL) {
            // nodeToDelete is the root node
            rootNode = child;
        } else if (nodeToDelete == nodeToDelete->parentNode->leftNode) {
            nodeToDelete->parentNode->leftNode = child;
        } else {
            nodeToDelete->parentNode->rightNode = child;
        }
        if (child != NULL) {
            child->parentNode = nodeToDelete->parentNode;
        }

        delete nodeToDelete;
    }

    void inOrderPrint(int x, int y) {
    if (this->rootNode != NULL) {
        inOrderPrint(this->rootNode, x, y);
        fout << "\n";
    }
}

    void getMin(int x) {
    if (this->rootNode == NULL) {
        return;
    }

    node* current = this->rootNode;
    node* result = NULL;

    while (current != NULL) {
        if (current->data >= x) {
            result = current;
            current = current->leftNode;
        } else {
            current = current->rightNode;
        }
    }

    if (result != NULL) {
        fout << result->data << "\n";
    }
}


    void getMax(int x) {
    if (this->rootNode == NULL) {
        return;
    }

    node* current = this->rootNode;
    node* result = NULL;

    while (current != NULL) {
        if (current->data <= x) {
            result = current;
            current = current->rightNode;
        } else {
            current = current->leftNode;
        }
    }

    if (result != NULL) {
        fout << result->data << "\n";
    } 
}

};

int main() {
    splayTree* tree = new splayTree;
    int option, x, n, y;

    fin >> n;

    for(int i = 0; i < n; i++){
      fin >> option;
      if(option == 1){
        fin >> x;
        tree->insertNode(x);
      } else if(option == 2){
        fin >> x;
        tree->deleteNode(x);
      } else if(option == 3){
        fin >> x;
        node* N = tree->searchNode(x);
        if(N != NULL){
          fout << 1 << "\n";
        } else{
          fout << 0 << "\n";
        }
      } else if(option == 4){
        fin >> x;
        tree->getMax(x);
      } else if(option == 5){
        fin >> x;
        tree->getMin(x);
      } else{
        fin >> x >> y;
        tree->inOrderPrint(x, y);
      }
    }
    return 0;
}
