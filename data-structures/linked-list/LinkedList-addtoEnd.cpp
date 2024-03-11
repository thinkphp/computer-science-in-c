#include <iostream>

// Define a basic Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// Function to add a node to the end of the linked list
void addToEnd(Node*& head, int value) {
    Node* newNode = new Node(value); // Create a new node with the given value
    
    if (head == nullptr) {
        // If the list is empty, make the new node the head
        head = newNode;
    } else {
        // Traverse the list to find the last node
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        
        // Update the next pointer of the last node to the new node
        current->next = newNode;
    }
}

// Function to print the elements of the linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    Node* head = nullptr; // Initialize an empty linked list
    
    // Add elements to the end of the linked list
    addToEnd(head, 1);
    addToEnd(head, 2);
    addToEnd(head, 3);
    
    // Print the linked list
    std::cout << "Linked List: ";
    printList(head);
    
    return 0;
}
