#include <iostream>
#include <ctime>

class ExecutionTimer {
private:
    clock_t startTime;
    bool useFile;

public:
    ExecutionTimer(bool useFile = false) : useFile(useFile) {
        startTime = clock();
        if (useFile) {
            freopen("input.txt", "r", stdin);
            freopen("out.txt", "w", stdout);
        }
    }

    double getExecutionTime() const {
        return static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
    }

    void printExecutionTime() const {
        std::cout << "\nExecution Time: " << getExecutionTime() << " seconds\n";
    }
};

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addToFront(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void display() const {
        std::cout << "Forward traversal: ";
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";

        // Find last node for backward traversal
        current = head;
        while (current != nullptr && current->next != nullptr) {
            current = current->next;
        }

        std::cout << "Backward traversal: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << "\n";
    }

    void addAfterNode(int afterNode, int val) {
        Node* current = head;
        while (current != nullptr && current->data != afterNode) {
            current = current->next;
        }

        if (current != nullptr) {
            Node* newNode = new Node(val);
            newNode->next = current->next;
            newNode->prev = current;

            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }

    void addBeforeNode(int beforeNode, int val) {
        if (head == nullptr) return;

        Node* newNode = new Node(val);

        if (head->data == beforeNode) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            Node* current = head;
            while (current != nullptr && current->data != beforeNode) {
                current = current->next;
            }

            if (current != nullptr) {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            } else {
                delete newNode;  // Node not found
            }
        }
    }

    void reverse() {
        Node* temp = nullptr;
        Node* current = head;

        while (current != nullptr) {
            // Swap next and prev pointers
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            // Move to next node (which is now in prev due to swapping)
            current = current->prev;
        }

        // Update head (last node is new head)
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    void removeNode(int delNode) {
        if (head == nullptr) return;

        Node* ptr = head;

        // If head is to be deleted
        if (head->data == delNode) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete ptr;
            return;
        }

        // Search for node to be deleted
        while (ptr != nullptr && ptr->data != delNode) {
            ptr = ptr->next;
        }

        // If node was found
        if (ptr != nullptr) {
            // Update next pointer of previous node
            if (ptr->prev != nullptr) {
                ptr->prev->next = ptr->next;
            }
            // Update prev pointer of next node
            if (ptr->next != nullptr) {
                ptr->next->prev = ptr->prev;
            }
            delete ptr;
        }
    }
};

int main() {
    ExecutionTimer timer;

    DoublyLinkedList list;
    int arr[] = {9, 8, 7, 15, 88, 123, -20, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create initial list
    for (int i = 0; i < n; ++i) {
        list.addToFront(arr[i]);
    }

    std::cout << "Initial list:\n";
    list.display();

    std::cout << "\nAdding 100 after 88:\n";
    list.addAfterNode(88, 100);
    list.display();

    std::cout << "\nAdding -50 before 15:\n";
    list.addBeforeNode(15, -50);
    list.display();

    std::cout << "\nRemoving 123:\n";
    list.removeNode(123);
    list.display();

    std::cout << "\nReversing the list:\n";
    list.reverse();
    list.display();

    timer.printExecutionTime();
    return 0;
}
