#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void addToFront(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void removeNode(int delval) {
        if (head == nullptr) return;

        if (head->data == delval) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != delval) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void addAfterNode(int afterNode, int val) {
        Node* current = head;
        while (current != nullptr && current->data != afterNode) {
            current = current->next;
        }

        if (current != nullptr) {
            Node* newNode = new Node(val);
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void addBeforeNode(int beforeNode, int val) {
        if (head == nullptr) return;

        if (head->data == beforeNode) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != beforeNode) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* newNode = new Node(val);
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void sort() {
        if (head == nullptr || head->next == nullptr) return;

        // Convert to array for sorting
        Node* current = head;
        int arr[20];  // Assuming max size of 20
        int k = 0;

        while (current != nullptr) {
            arr[k++] = current->data;
            current = current->next;
        }

        // Simple bubble sort
        for (int i = 0; i < k - 1; i++) {
            for (int j = 0; j < k - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        // Rebuild the sorted linked list
        current = head;
        for (int i = 0; i < k; i++) {
            current->data = arr[i];
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;
    int arr[] = {9, 8, 7, 6, 25, 4, 3, 23, -11, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        list.addToFront(arr[i]);
    }

    cout << "Original list: ";
    list.display();

    int delval;
    cout << "Remove Node = ";
    cin >> delval;
    list.removeNode(delval);
    cout << "After removal: ";
    list.display();

    list.reverse();
    cout << "Reversed list: ";
    list.display();

    int afterNode, val;
    cout << "After node; what value = ";
    cin >> afterNode >> val;
    list.addAfterNode(afterNode, val);
    cout << "After adding after node: ";
    list.display();

    int beforeNode;
    cout << "Insert before node; what value = ";
    cin >> beforeNode >> val;
    list.addBeforeNode(beforeNode, val);
    cout << "After adding before node: ";
    list.display();

    cout << "Sorted list: ";
    list.sort();
    list.display();

    return 0;
}
