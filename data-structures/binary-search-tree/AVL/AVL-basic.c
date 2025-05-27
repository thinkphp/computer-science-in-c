explica linie cu linie codul AVL data structure #include <stdio.h>
#include <stdlib.h>
// Structura nodului AVL
typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;
// Funcție pentru crearea unui nod nou
AVLNode* createNode(int data) {
    AVLNode* node = (AVLNode)malloc(sizeof(AVLNode));
    if (!node) {
        printf("Eroare: Nu s-a putut aloca memoria!\n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Nodul nou este frunză
    return node;
}
// Funcție pentru obținerea înălțimii unui nod
int getHeight(AVLNode node) {
    return node ? node->height : 0;
}
// Funcție pentru calcularea factorului de echilibru
int getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}
// Funcție pentru actualizarea înălțimii unui nod
void updateHeight(AVLNode* node) {
    if (node) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}
// Rotația la dreapta (pentru cazul LL)
AVLNode* rotateRight(AVLNode* y) {
    printf("Efectuez rotația dreapta la nodul %d\n", y->data);

    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Efectuez rotația
    x->right = y;
    y->left = T2;

    // Actualizez înălțimile
    updateHeight(y);
    updateHeight(x);

    return x; // Noua rădăcină
}
// Rotația la stânga (pentru cazul RR)
AVLNode* rotateLeft(AVLNode* x) {
    printf("Efectuez rotația stânga la nodul %d\n", x->data);

    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Efectuez rotația
    y->left = x;
    x->right = T2;

    // Actualizez înălțimile
    updateHeight(x);
    updateHeight(y);

    return y; // Noua rădăcină
}
// Funcția de inserare în AVL
AVLNode* insert(AVLNode* node, int data) {
    // Pas 1: Inserare BST normală
    if (!node) {
        printf("Inserez %d ca nod nou\n", data);
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        // Valoarea există deja
        printf("Valoarea %d există deja în arbore\n", data);
        return node;
    }

    // Pas 2: Actualizez înălțimea nodului curent
    updateHeight(node);

    // Pas 3: Obțin factorul de echilibru
    int balance = getBalance(node);
    printf("Nodul %d: înălțime=%d, factor echilibru=%d\n", 
           node->data, node->height, balance);

    // Pas 4: Dacă nodul este neechilibrat, efectuez rotații

    // Cazul LL (Left Left)
    if (balance > 1 && data < node->left->data) {
        printf("Caz LL detectat la nodul %d\n", node->data);
        return rotateRight(node);
    }

    // Cazul RR (Right Right)
    if (balance < -1 && data > node->right->data) {
        printf("Caz RR detectat la nodul %d\n", node->data);
        return rotateLeft(node);
    }

    // Cazul LR (Left Right)
    if (balance > 1 && data > node->left->data) {
        printf("Caz LR detectat la nodul %d\n", node->data);
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Cazul RL (Right Left)
    if (balance < -1 && data < node->right->data) {
        printf("Caz RL detectat la nodul %d\n", node->data);
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // Returnez nodul nemodificat
    return node;
}
// Parcurgere în INORDINE (stânga - rădăcină - dreapta)
void inorderTraversal(AVLNode* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
// Parcurgere în PREORDINE (rădăcină - stânga - dreapta)
void preorderTraversal(AVLNode* root) {
    if (root) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
// Parcurgere în POSTORDINE (stânga - dreapta - rădăcină)
void postorderTraversal(AVLNode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
// Funcție pentru eliberarea memoriei
void freeTree(AVLNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
// Funcție pentru meniu interactiv
void printMenu() {
    printf("\n=== AVL Tree - Inserare și Parcurgeri ===\n");
    printf("1. Inserare număr\n");
    printf("2. Parcurgere în inordine\n");
    printf("3. Parcurgere în preordine\n");
    printf("4. Parcurgere în postordine\n");
    printf("5. Toate parcurgerile\n");
    printf("6. Demo (inserare secvență)\n");
    printf("0. Ieșire\n");
    printf("Alegerea ta: ");
}
int main() {
    AVLNode* root = NULL;
    int choice, value;

    printf("=== AVL Tree - Implementare pentru Inserare și Parcurgeri ===\n");

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Introdu numărul de inserat: ");
                scanf("%d", &value);
                printf("\n=== INSERARE %d ===\n", value);
                root = insert(root, value);
                printf("Operația completă!\n");
                break;

            case 2:
                printf("\n=== PARCURGERE INORDINE ===\n");
                if (root) {
                    printf("Inordine (stânga-rădăcină-dreapta): ");
                    inorderTraversal(root);
                    printf("\n");
                } else {
                    printf("Arborele este gol\n");
                }
                break;

            case 3:
                printf("\n=== PARCURGERE PREORDINE ===\n");
                if (root) {
                    printf("Preordine (rădăcină-stânga-dreapta): ");
                    preorderTraversal(root);
                    printf("\n");
                } else {
                    printf("Arborele este gol\n");
                }
                break;

            case 4:
                printf("\n=== PARCURGERE POSTORDINE ===\n");
                if (root) {
                    printf("Postordine (stânga-dreapta-rădăcină): ");
                    postorderTraversal(root);
                    printf("\n");
                } else {
                    printf("Arborele este gol\n");
                }
                break;

            case 5:
                printf("\n=== TOATE PARCURGERILE ===\n");
                if (root) {
                    printf("Inordine:   ");
                    inorderTraversal(root);
                    printf("\n");

                    printf("Preordine:  ");
                    preorderTraversal(root);
                    printf("\n");

                    printf("Postordine: ");
                    postorderTraversal(root);
                    printf("\n");
                } else {
                    printf("Arborele este gol\n");
                }
                break;

            case 6:
                printf("\n=== DEMO - Inserare secvența 10,20,30,40,50,25 ===\n");
                int demo[] = {10, 20, 30, 40, 50, 25};
                int demo_size = sizeof(demo) / sizeof(demo[0]);

                for (int i = 0; i < demo_size; i++) {
                    printf("\n--- Inserez %d ---\n", demo[i]);
                    root = insert(root, demo[i]);
                }
                printf("\nDemo complet! Folosește opțiunile 2-5 pentru a vedea parcurgerile.\n");
                break;

            case 0:
                printf("Eliberez memoria și ies...\n");
                freeTree(root);
                exit(0);

            default:
                printf("Opțiune invalidă!\n");
        }
    }

    return 0;
}
