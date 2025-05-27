#include <stdio.h>
#include <stdlib.h>

// Structura pentru un nod al BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Funcție pentru crearea unui nod nou
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inserarea unui nod în BST
Node* insert(Node* root, int value) {
    // Dacă arborele este gol, creăm primul nod
    if (root == NULL) {
        return createNode(value);
    }
    
    // Inserăm în subarborele stâng dacă valoarea este mai mică
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Inserăm în subarborele drept dacă valoarea este mai mare
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Dacă valoarea există deja, nu o inserăm din nou
    
    return root;
}

// Căutarea unei valori în BST
Node* search(Node* root, int value) {
    // Cazul de bază: rădăcina este NULL sau valoarea este găsită
    if (root == NULL || root->data == value) {
        return root;
    }
    
    // Căutăm în subarborele stâng
    if (value < root->data) {
        return search(root->left, value);
    }
    
    // Căutăm în subarborele drept
    return search(root->right, value);
}

// Găsirea nodului cu valoarea minimă (cel mai din stânga)
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Ștergerea unui nod din BST
Node* delete(Node* root, int value) {
    // Cazul de bază
    if (root == NULL) {
        return root;
    }
    
    // Dacă valoarea de șters este mai mică decât rădăcina
    if (value < root->data) {
        root->left = delete(root->left, value);
    }
    // Dacă valoarea de șters este mai mare decât rădăcina
    else if (value > root->data) {
        root->right = delete(root->right, value);
    }
    // Dacă valoarea de șters este egală cu rădăcina
    else {
        // Nodul cu un singur copil sau fără copii
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Nodul cu doi copii: găsim succesorul inorder (cel mai mic din subarborele drept)
        Node* temp = findMin(root->right);
        
        // Copiem conținutul succesorului inorder în acest nod
        root->data = temp->data;
        
        // Ștergem succesorul inorder
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Parcurgerea în inordine (stânga, rădăcină, dreapta)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Parcurgerea în preordine (rădăcină, stânga, dreapta)
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Parcurgerea în postordine (stânga, dreapta, rădăcină)
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Funcție pentru eliberarea memoriei
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Funcția main pentru demonstrație
int main() {
    Node* root = NULL;
    
    printf("=== BINARY SEARCH TREE DEMO ===\n\n");
    
    // Inserăm valori în BST
    printf("1. Inserăm valorile: 50, 30, 70, 20, 40, 60, 80\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    // Afișăm parcurgerile
    printf("\n2. Parcurgeri ale BST:\n");
    
    printf("   Inordine (sortată crescător): ");
    inorderTraversal(root);
    printf("\n");
    
    printf("   Preordine: ");
    preorderTraversal(root);
    printf("\n");
    
    printf("   Postordine: ");
    postorderTraversal(root);
    printf("\n");
    
    // Căutăm valori
    printf("\n3. Căutare în BST:\n");
    int searchValues[] = {40, 25, 80};
    int numSearchValues = sizeof(searchValues) / sizeof(searchValues[0]);
    
    for (int i = 0; i < numSearchValues; i++) {
        Node* result = search(root, searchValues[i]);
        if (result != NULL) {
            printf("   Valoarea %d a fost găsită în BST\n", searchValues[i]);
        } else {
            printf("   Valoarea %d NU a fost găsită în BST\n", searchValues[i]);
        }
    }
    
    // Ștergem valori
    printf("\n4. Ștergere din BST:\n");
    
    printf("   Înainte de ștergere - Inordine: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("   Ștergem valoarea 20 (nod cu un copil)\n");
    root = delete(root, 20);
    printf("   După ștergere - Inordine: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("   Ștergem valoarea 30 (nod cu doi copii)\n");
    root = delete(root, 30);
    printf("   După ștergere - Inordine: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("   Ștergem valoarea 50 (rădăcina)\n");
    root = delete(root, 50);
    printf("   După ștergere - Inordine: ");
    inorderTraversal(root);
    printf("\n");
    
    // Eliberăm memoria
    freeTree(root);
    
    printf("\n=== DEMO TERMINAT ===\n");
    
    return 0;
}
