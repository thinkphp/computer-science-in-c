#include <stdio.h>
#include <malloc.h>
#include <time.h>

struct ExecutionTimer {
    clock_t startTime;
    int useFile;
};

void initTimer(struct ExecutionTimer *timer, int useFile) {
    timer->startTime = clock();
    timer->useFile = useFile;
    if (useFile) {
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
}

double getExecutionTime(const struct ExecutionTimer *timer) {
    return ((double)(clock() - timer->startTime)) / CLOCKS_PER_SEC;
}

void printExecutionTime(const struct ExecutionTimer *timer) {
    printf("\nExecution Time: %.6f seconds\n", getExecutionTime(timer));
}

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;  // Added previous pointer for doubly linked list
} Node;

Node *head = NULL;

void addToDoublyLinkedList(int val) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;  // Set previous pointer of old head
        head = new_node;
    }
}

void displayLinkedList(Node *head) {
    printf("Forward traversal: ");
    Node *c = head;
    while (c != NULL) {
        printf("%d ", c->data);
        c = c->next;
    }
    printf("\n");

    // Traverse to the last node
    c = head;
    while (c != NULL && c->next != NULL) {
        c = c->next;
    }

    printf("Backward traversal: ");
    while (c != NULL) {
        printf("%d ", c->data);
        c = c->prev;
    }
    printf("\n");
}

void addAfterNode(int afternode, int val) {
    Node *c = head;
    while (c != NULL && c->data != afternode) {
        c = c->next;
    }

    if (c != NULL) {
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->data = val;
        new_node->next = c->next;
        new_node->prev = c;

        if (c->next != NULL) {
            c->next->prev = new_node;
        }
        c->next = new_node;
    }
}

void addBeforeNode(int beforenode, int val) {
    if (head == NULL) return;

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;

    if (head->data == beforenode) {
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        head = new_node;
    } else {
        Node *c = head;
        while (c != NULL && c->data != beforenode) {
            c = c->next;
        }

        if (c != NULL) {
            new_node->next = c;
            new_node->prev = c->prev;
            c->prev->next = new_node;
            c->prev = new_node;
        } else {
            free(new_node);  // Node not found
        }
    }
}

Node* reverse(Node *head) {
    Node *temp = NULL;
    Node *current = head;

    while (current != NULL) {
        // Swap next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (which is now in prev due to swapping)
        current = current->prev;
    }

    // Update head (last node is new head)
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

void removeNode(int delNode) {
    if (head == NULL) return;

    Node *ptr = head;

    // If head is to be deleted
    if (head->data == delNode) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(ptr);
        return;
    }

    // Search for node to be deleted
    while (ptr != NULL && ptr->data != delNode) {
        ptr = ptr->next;
    }

    // If node was found
    if (ptr != NULL) {
        // Update next pointer of previous node
        if (ptr->prev != NULL) {
            ptr->prev->next = ptr->next;
        }
        // Update prev pointer of next node
        if (ptr->next != NULL) {
            ptr->next->prev = ptr->prev;
        }
        free(ptr);
    }
}

int main(int argc, char const *argv[]) {
    struct ExecutionTimer timer;
    initTimer(&timer, 0);

    int arr[] = {9, 8, 7, 15, 88, 123, -20, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create initial list
    for (int i = 0; i < n; ++i) {
        addToDoublyLinkedList(arr[i]);
    }

    printf("Initial list:\n");
    displayLinkedList(head);

    printf("\nAdding 100 after 88:\n");
    addAfterNode(88, 100);
    displayLinkedList(head);

    printf("\nAdding -50 before 15:\n");
    addBeforeNode(15, -50);
    displayLinkedList(head);

    printf("\nRemoving 123:\n");
    removeNode(123);
    displayLinkedList(head);

    printf("\nReversing the list:\n");
    head = reverse(head);
    displayLinkedList(head);

    printExecutionTime(&timer);
    return 0;
}
