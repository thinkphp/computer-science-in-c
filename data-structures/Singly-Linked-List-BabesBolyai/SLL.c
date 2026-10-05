#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//
// SLL
//
// node1(data, next) ---> node2(data, next) ---> node3(data, next) ---> NULL
// Fiecare nod are 2 campuri: data (cheia) si next (adresa urmatorului nod)
//

typedef struct Node {
    int data;           // key
    struct Node *next;  // referinta catre urmatorul nod
} Node;


/* ---------- CREARE ---------- */

Node *createNode(int value) {

    // alocam spatiu in HEAP pentru un nod
    Node *n = (Node *)malloc(sizeof(Node));

    if (!n) {
        fprintf(stderr, "Err: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    n->data = value;
    n->next = NULL;

    return n;
}


/* ---------- INSERARE ---------- */

void addToFront(Node **head, int value) {

    Node *n = createNode(value);

    n->next = *head;   // functioneaza si pe lista goala (next = NULL)
    *head = n;
}

void addToBack(Node **head, int value) {

    Node *n = createNode(value);

    // lista goala
    if (*head == NULL) {
        *head = n;
        return;
    }

    Node *c = *head;

    while (c->next != NULL) c = c->next;

    c->next = n;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

int length(Node *head) {

    int count = 0;

    for (Node *c = head; c != NULL; c = c->next) count++;

    return count;
}

// insereaza pe pozitia pos (0 = inceput, length = sfarsit)
// returneaza false daca pos este invalid
bool insertAt(Node **head, int pos, int value) {

    if (pos < 0 || pos > length(*head)) return false;

    if (pos == 0) {
        addToFront(head, value);
        return true;
    }

    Node *c = *head;

    for (int i = 0; i < pos - 1; ++i) c = c->next;

    Node *n = createNode(value);

    n->next = c->next;
    c->next = n;

    return true;
}

// insereaza `value` dupa prima aparitie a lui `key`
// returneaza false daca `key` nu exista
// (nu are nevoie de Node **head: capul nu se schimba niciodata)
bool insertAfterKey(Node *head, int key, int value) {

    Node *c = head;

    while (c != NULL && c->data != key) c = c->next;

    if (c == NULL) return false;   // key negasit

    Node *n = createNode(value);

    n->next = c->next;   // intai legam noul nod de restul listei
    c->next = n;         // apoi legam nodul gasit de noul nod

    return true;
}

// insereaza `value` inaintea primei aparitii a lui `key`
// returneaza false daca `key` nu exista
bool insertBeforeKey(Node **head, int key, int value) {

    if (*head == NULL) return false;

    // cazul 1: key este chiar capul listei
    if ((*head)->data == key) {
        addToFront(head, value);
        return true;
    }

    // cazul 2: ne oprim pe nodul DINAINTEA lui key
    Node *c = *head;

    while (c->next != NULL && c->next->data != key) c = c->next;

    if (c->next == NULL) return false;   // key negasit

    Node *n = createNode(value);

    n->next = c->next;
    c->next = n;

    return true;
}


/* ---------- CITIRE / CAUTARE / MODIFICARE ---------- */

// citeste valoarea de pe pozitia pos; returneaza false daca pos este invalid
bool getAt(Node *head, int pos, int *out) {

    if (pos < 0) return false;

    for (Node *c = head; c != NULL; c = c->next, pos--) {

        if (pos == 0) {
            *out = c->data;
            return true;
        }
    }

    return false;
}

// returneaza pozitia primei aparitii sau -1 daca nu exista
int search(Node *head, int value) {

    int pos = 0;

    for (Node *c = head; c != NULL; c = c->next, pos++) {
        if (c->data == value) return pos;
    }

    return -1;
}

// actualizeaza prima aparitie a lui oldValue; false daca nu exista
bool update(Node *head, int oldValue, int newValue) {

    for (Node *c = head; c != NULL; c = c->next) {

        if (c->data == oldValue) {
            c->data = newValue;
            return true;
        }
    }

    return false;
}

// inverseaza lista pe loc (modifica doar legaturile)
void reverse(Node **head) {

    Node *prev = NULL;
    Node *curr = *head;

    while (curr != NULL) {
        Node *next = curr->next;   // salvam urmatorul
        curr->next = prev;         // inversam legatura
        prev = curr;               // avansam
        curr = next;
    }

    *head = prev;   // prev este noul cap
}

void display(Node *head) {

    if (head == NULL) {
        printf("Lista este GOALA! {}\n");
        return;
    }

    for (Node *c = head; c != NULL; c = c->next) {

        printf("%d", c->data);

        if (c->next) printf(" -> ");
    }

    printf(" -> NULL\n");
}


/* ---------- STERGERE ---------- */

bool removeFront(Node **head) {

    if (*head == NULL) return false;

    Node *tmp = *head;

    *head = (*head)->next;

    free(tmp);

    return true;
}

bool removeBack(Node **head) {

    if (*head == NULL) return false;

    // un singur nod
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return true;
    }

    // ne oprim pe penultimul nod
    Node *c = *head;

    while (c->next->next != NULL) c = c->next;

    free(c->next);
    c->next = NULL;

    return true;   // lipsea in varianta initiala
}

// sterge prima aparitie a valorii; false daca nu exista
bool removeNode(Node **head, int removeKey) {

    if (*head == NULL) return false;

    if ((*head)->data == removeKey) return removeFront(head);

    Node *c = *head;

    while (c->next != NULL && c->next->data != removeKey) c = c->next;

    if (c->next == NULL) return false;   // key negasit (evita crash)

    Node *temp = c->next;

    c->next = temp->next;

    free(temp);

    return true;
}

void freeList(Node **head) {

    Node *c = *head;

    while (c != NULL) {
        Node *next = c->next;
        free(c);
        c = next;
    }

    *head = NULL;
}


/* ---------- MAIN ---------- */

int main(void) {

    Node *head = NULL;   // lista este goala

    int keys[] = {3, 8, 15, 22, 30, 41, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; ++i) addToBack(&head, keys[i]);

    printf("Lista initiala:\n");
    display(head);

    // --- inserari ---
    printf("\ninsertAt(4, -1):\n");
    if (insertAt(&head, 4, -1)) display(head);

    printf("\ninsertAfterKey(15, 99):\n");
    if (insertAfterKey(head, 15, 99)) display(head);

    printf("\ninsertBeforeKey(3, 0)  [key = cap]:\n");
    if (insertBeforeKey(&head, 3, 0)) display(head);

    printf("\ninsertBeforeKey(30, 77):\n");
    if (insertBeforeKey(&head, 30, 77)) display(head);

    if (!insertAfterKey(head, 1000, 5))
        printf("\nCheia 1000 nu exista (insertAfterKey)\n");

    if (!insertBeforeKey(&head, 1000, 5))
        printf("Cheia 1000 nu exista (insertBeforeKey)\n");

    // --- citire / cautare / update ---
    int val;
    if (getAt(head, 2, &val)) printf("\ngetAt(2) = %d\n", val);

    printf("search(41) = %d\n", search(head, 41));

    if (update(head, 99, 100)) {
        printf("\nupdate(99 -> 100):\n");
        display(head);
    }

    // --- reverse ---
    reverse(&head);
    printf("\nDupa reverse:\n");
    display(head);

    reverse(&head);   // revenim la ordinea initiala

    // --- stergeri ---
    printf("\n");
    if (removeFront(&head)) printf("Primul nod s-a sters\n");
    else printf("Lista este goala, nu exista primul nod\n");

    if (removeBack(&head)) printf("Ultimul nod s-a sters\n");
    else printf("Lista este goala, nu exista ultimul nod\n");

    if (removeNode(&head, 22)) printf("S-a sters nodul cu key 22\n");
    else printf("Nodul cu key 22 nu a fost gasit\n");

    if (removeNode(&head, 8)) printf("S-a sters nodul cu key 8\n");
    else printf("Nodul cu key 8 nu a fost gasit\n");

    if (!removeNode(&head, 1000)) printf("Nodul cu key 1000 nu a fost gasit\n");

    printf("\nLista cu cheile ramase:\n");
    display(head);

    // --- stergere totala ---
    freeList(&head);
    printf("\nS-a sters toata lista\n");
    display(head);

    return 0;
}
