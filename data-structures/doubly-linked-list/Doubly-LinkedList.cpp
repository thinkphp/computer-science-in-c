#include <iostream>
using namespace std;

class DoublyLinkedList {

    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* head = nullptr;

public:

    void addToLinkedList(int val) {

        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addAfterNode(int afterNode, int value) {

        Node* c = head;

        while (c != nullptr && c->data != afterNode) {
            c = c->next;
        }

        if (c == nullptr) {
            cout << "Nodul cu info value nu este in lista d. in" << endl;
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = c->next;
        newNode->prev = c;

        if (c->next != nullptr) {
            c->next->prev = newNode;
        }

        c->next = newNode;
    }

    void addBeforeNode(int beforeNode, int value) {

        Node* newNode = new Node(value);

        if (head != nullptr && head->data == beforeNode) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node* c = head;

        while (c != nullptr && c->next != nullptr && c->next->data != beforeNode) {
            c = c->next;
        }

        if (c == nullptr || c->next == nullptr) {
            cout << "Nodul nu este gasit" << endl;
            return;
        }

        newNode->next = c->next;
        newNode->prev = c;

        if (c->next != nullptr) {
            c->next->prev = newNode;
        }

        c->next = newNode;
    }

    void removeNode(int delNode) {

        if (head == nullptr) {
            cout << "Lista este goala" << endl;
            return;
        }

        if (head->data == delNode) {
            Node* toDelete = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete toDelete;
            return;
        }

        Node* c = head;

        while (c->next != nullptr && c->next->data != delNode) {
            c = c->next;
        }

        if (c->next == nullptr) {
            cout << "Nodul cu valoare delNode nu exista" << endl;
            return;
        }

        Node* nodeToDelete = c->next;
        c->next = nodeToDelete->next;

        if (nodeToDelete->next != nullptr) {
            nodeToDelete->next->prev = c;
        }

        delete nodeToDelete;
    }

    Node* reverse() {

        Node* curr = head;
        Node* temp = nullptr;

        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }

        return head;
    }

    void sort() {

        if (head == nullptr || head->next == nullptr) return;

        bool swapped;

        do {
            swapped = false;
            Node* c = head;

            while (c->next != nullptr) {

                if (c->data > c->next->data) {
                    int temp = c->data;
                    c->data = c->next->data;
                    c->next->data = temp;
                    swapped = true;
                }

                c = c->next;
            }

        } while (swapped);
    }

    void display() {

        Node* c = head;

        while (c != nullptr) {
            cout << c->data;
            if (c->next != nullptr) cout << " <-> ";
            c = c->next;
        }

        cout << endl;
    }

    void displayReverse() {

        Node* c = head;

        if (c == nullptr) {
            cout << endl;
            return;
        }

        while (c->next != nullptr) {
            c = c->next;
        }

        while (c != nullptr) {
            cout << c->data;
            if (c->prev != nullptr) cout << " <-> ";
            c = c->prev;
        }

        cout << endl;
    }
};

int main() {

    DoublyLinkedList list;

    int arr[] = {1, 22, 3, 4, 53, 6, 7, 8, 10, 101, 53};

    for (int val : arr) {
        list.addToLinkedList(val);
    }

    list.display();

    cout << "Adaugare dupa NODE" << endl;
    list.addAfterNode(53, 11);
    list.display();

    cout << "Adaugare inainte NODE" << endl;
    list.addBeforeNode(1, -1);
    list.display();

    cout << "STERGERE NODE: " << endl;
    list.removeNode(6);
    list.display();

    cout << "\nLista Sortata: " << endl;
    list.sort();
    list.display();

    cout << "AFISARE INVERSA (fara reverse): " << endl;
    list.displayReverse();

    cout << "REVERSE: " << endl;
    // We need a way to traverse after reverse — use a temp pointer via a helper
    // Since reverse() returns Node* (private type), we expose traversal via display()
    list.reverse();
    list.display();

    return 0;
}
