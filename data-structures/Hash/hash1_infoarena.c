#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 100003  // Număr prim pentru a reduce coliziunile

// Structura pentru nodurile din lista înlănțuită
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Tabela de hash
Node* hash_table[HASH_SIZE];

// Funcția de hash
int hash_function(int x) {
    return x % HASH_SIZE;
}

// Operația 1: Adaugă elementul x în mulțime
void insert(int x) {
    int index = hash_function(x);
    Node* current = hash_table[index];
    
    // Verifică dacă elementul există deja
    while (current != NULL) {
        if (current->value == x) {
            return; // Elementul există deja
        }
        current = current->next;
    }
    
    // Adaugă elementul la începutul listei
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = x;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

// Operația 2: Șterge elementul x din mulțime
void delete(int x) {
    int index = hash_function(x);
    Node* current = hash_table[index];
    Node* prev = NULL;
    
    while (current != NULL) {
        if (current->value == x) {
            if (prev == NULL) {
                // Elementul este primul din listă
                hash_table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Operația 3: Verifică dacă elementul x este în mulțime
int search(int x) {
    int index = hash_function(x);
    Node* current = hash_table[index];
    
    while (current != NULL) {
        if (current->value == x) {
            return 1; // Elementul a fost găsit
        }
        current = current->next;
    }
    
    return 0; // Elementul nu a fost găsit
}

// Funcție pentru eliberarea memoriei
void cleanup() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* current = hash_table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        hash_table[i] = NULL;
    }
}

int main() {
    FILE* input = fopen("hashuri.in", "r");
    FILE* output = fopen("hashuri.out", "w");
    
    if (input == NULL || output == NULL) {
        printf("Eroare la deschiderea fișierelor!\n");
        return 1;
    }
    
    // Inițializează tabela de hash
    for (int i = 0; i < HASH_SIZE; i++) {
        hash_table[i] = NULL;
    }
    
    int n;
    fscanf(input, "%d", &n);
    
    for (int i = 0; i < n; i++) {
        int op, x;
        fscanf(input, "%d %d", &op, &x);
        
        switch (op) {
            case 1:
                insert(x);
                break;
            case 2:
                delete(x);
                break;
            case 3:
                fprintf(output, "%d\n", search(x));
                break;
        }
    }
    
    // Curăță memoria
    cleanup();
    
    fclose(input);
    fclose(output);
    
    return 0;
}
