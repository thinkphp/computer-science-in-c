#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * Laborator 3 - Lista dublu inlantuita (SDA)
 *
 *   first                                              last
 *     |                                                  |
 *   NULL <- [prev|key|next] <-> [prev|key|next] <-> [prev|key|next] -> NULL
 */

/* ---------- STRUCTURI ---------- */

typedef struct _DLL_NODE {
    int key;
    struct _DLL_NODE *next;     /* succesor   */
    struct _DLL_NODE *prev;     /* predecesor */
} DLL_NODE;

typedef struct {
    DLL_NODE *first;
    DLL_NODE *last;
} DL_LIST;


/* ---------- CREARE / DISTRUGERE ---------- */

static DLL_NODE *dll_create_node(int value) {

    DLL_NODE *node = NULL;

    node = (DLL_NODE *)malloc(sizeof(DLL_NODE));

    if (node == NULL) {
        fprintf(stderr, "Err: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    memset(node, 0, sizeof(DLL_NODE));   /* next = prev = NULL */
    node->key = value;

    return node;
}

DL_LIST *dll_create(void) {

    DL_LIST *list = NULL;

    list = (DL_LIST *)malloc(sizeof(DL_LIST));

    if (list == NULL) {
        fprintf(stderr, "Err: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    memset(list, 0, sizeof(DL_LIST));    /* first = last = NULL */

    return list;
}


/* ---------- CAUTARE ---------- */

/* returneaza adresa nodului cu cheia givenKey, sau NULL daca nu exista */
DLL_NODE *dll_search(const DL_LIST *list, int givenKey) {

    DLL_NODE *crt_node = list->first;

    while (crt_node != NULL) {
        if (crt_node->key == givenKey) return crt_node;
        crt_node = crt_node->next;
    }

    return NULL;
}


/* ---------- INSERARE ---------- */

void dll_insert_first(DL_LIST *list, int givenKey) {

    DLL_NODE *node = dll_create_node(givenKey);

    if (list->first == NULL) {           /* lista vida */
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first->prev = node;        /* NOU fata de lista simpla */
        list->first = node;
    }
}

void dll_insert_last(DL_LIST *list, int givenKey) {

    DLL_NODE *node = dll_create_node(givenKey);

    if (list->first == NULL) {           /* lista vida */
        list->first = node;
        list->last = node;
    } else {
        node->prev = list->last;         /* NOU */
        list->last->next = node;
        list->last = node;
    }
}

/* insereaza givenKey dupa nodul cu cheia afterKey (nu face nimic daca nu exista) */
void dll_insert_after_key(DL_LIST *list, int afterKey, int givenKey) {

    DLL_NODE *q = dll_search(list, afterKey);

    if (q == NULL) return;               /* cheia nu exista */

    DLL_NODE *node = dll_create_node(givenKey);

    node->prev = q;
    node->next = q->next;

    if (q->next != NULL)
        q->next->prev = node;            /* NOU */

    q->next = node;

    if (q == list->last)                 /* am inserat dupa ultimul nod */
        list->last = node;
}

void dll_insert_before_key(DL_LIST *list, int beforeKey, int givenKey) {

    DLL_NODE *q = dll_search(list, beforeKey);

    if (q == NULL) return;

    DLL_NODE *node = dll_create_node(givenKey);

    node->next = q;
    node->prev = q->prev;

    if (q->prev != NULL)
        q->prev->next = node;
    else
        list->first = node;              /* am inserat inainte de primul */

    q->prev = node;
}



/* ---------- PARCURGERE ---------- */

void dll_print_forward(const DL_LIST *list) {

    if (list->first == NULL) {
        printf("Lista este GOALA! {}\n");
        return;
    }

    printf("NULL <- ");
    for (DLL_NODE *p = list->first; p != NULL; p = p->next) {
        printf("%d", p->key);
        if (p->next) printf(" <-> ");
    }
    printf(" -> NULL\n");
}

void dll_print_backward(const DL_LIST *list) {

    if (list->first == NULL) {
        printf("Lista este GOALA! {}\n");
        return;
    }

    printf("NULL <- ");
    for (DLL_NODE *p = list->last; p != NULL; p = p->prev) {
        printf("%d", p->key);
        if (p->prev) printf(" <-> ");
    }
    printf(" -> NULL\n");
}


/* ---------- STERGERE ---------- */

/* sterge nodul p (se presupune ca p apartine listei) - pseudocodul din PDF */
static void dll_delete_node(DL_LIST *list, DLL_NODE *p) {

    if (p->prev != NULL)
        p->prev->next = p->next;
    else
        list->first = p->next;           /* p era primul */

    if (p->next != NULL)
        p->next->prev = p->prev;
    else
        list->last = p->prev;            /* p era ultimul */

    free(p);
}

void dll_delete_first(DL_LIST *list) {

    if (list->first == NULL) return;     /* lista vida */

    dll_delete_node(list, list->first);
}

void dll_delete_last(DL_LIST *list) {

    if (list->last == NULL) return;      /* lista vida */

    dll_delete_node(list, list->last);   /* O(1): nu mai parcurgem lista */
}

void dll_delete_key(DL_LIST *list, int givenKey) {

    DLL_NODE *p = dll_search(list, givenKey);

    if (p == NULL) return;               /* cheia nu exista */

    dll_delete_node(list, p);
}


void dll_delete_after_key(DL_LIST *list, int afterKey) {

    DLL_NODE *q = dll_search(list, afterKey);

    if (q == NULL || q->next == NULL) return;

    dll_delete_node(list, q->next);
}

void dll_delete_before_key(DL_LIST *list, int beforeKey) {

    DLL_NODE *q = dll_search(list, beforeKey);

    if (q == NULL || q->prev == NULL) return;

    dll_delete_node(list, q->prev);
}


void dll_delete_all(DL_LIST *list, int givenKey) {

    DLL_NODE *p = list->first;

    while (p != NULL) {
        DLL_NODE *next = p->next;        /* salvat inainte de free */
        if (p->key == givenKey) dll_delete_node(list, p);
        p = next;
    }
}

void dll_reverse(DL_LIST *list) {

    DLL_NODE *p = list->first;

    while (p != NULL) {
        DLL_NODE *tmp = p->next;
        p->next = p->prev;
        p->prev = tmp;
        p = tmp;                         /* tmp = vechiul next */
    }

    DLL_NODE *aux = list->first;
    list->first = list->last;
    list->last = aux;
}

void dll_clear(DL_LIST *list) {

    while (list->first != NULL) dll_delete_first(list);
}

void dll_destroy(DL_LIST **list) {

    if (*list == NULL) return;

    dll_clear(*list);

    free(*list);
    *list = NULL;
}



bool dll_is_empty(const DL_LIST *list) {
    return list->first == NULL;
}

size_t dll_size(const DL_LIST *list) {
    size_t n = 0;
    for (DLL_NODE *p = list->first; p != NULL; p = p->next) n++;
    return n;
}

/* ---------- MAIN ---------- */

static void show(const char *msg, const DL_LIST *list) {
    printf("%s\n", msg);
    printf("  Forward : ");  dll_print_forward(list);
    printf("  Backward: ");  dll_print_backward(list);
    printf("  Size    : %zu\n\n", dll_size(list));
}

int main(void) {

    DL_LIST *list = dll_create();

    /* ---- lista vida: nicio operatie nu trebuie sa crape ---- */
    printf("Lista vida? %s\n\n", dll_is_empty(list) ? "da" : "nu");
    dll_delete_first(list);
    dll_delete_last(list);
    dll_delete_key(list, 1);
    dll_delete_all(list, 1);
    dll_delete_after_key(list, 1);
    dll_delete_before_key(list, 1);
    dll_insert_before_key(list, 1, 2);
    dll_reverse(list);
    show("Dupa operatii pe lista vida:", list);       /* GOALA, size 0 */

    /* ---- inserari ---- */
    dll_insert_first(list, 4);
    dll_insert_first(list, 1);
    dll_insert_last(list, 3);
    dll_insert_after_key(list, 4, 22);
    show("Dupa inserari de baza:", list);             /* 1 4 22 3 */

    dll_insert_before_key(list, 1, 0);                /* inainte de primul */
    dll_insert_before_key(list, 3, 25);               /* la mijloc */
    dll_insert_before_key(list, 99, 7);               /* inexistenta: nimic */
    show("Dupa insert_before_key:", list);            /* 0 1 4 22 25 3, size 6 */

    /* ---- reverse ---- */
    dll_reverse(list);
    show("Dupa reverse:", list);                      /* 3 25 22 4 1 0 */
    dll_reverse(list);
    show("Dupa al doilea reverse (revenim):", list);  /* 0 1 4 22 25 3 */

    /* ---- stergeri relative la o cheie ---- */
    dll_delete_after_key(list, 3);                    /* 3 e ultimul: nimic */
    dll_delete_before_key(list, 0);                   /* 0 e primul: nimic */
    show("Dupa delete_after(3) si delete_before(0) (fara efect):", list);

    dll_delete_after_key(list, 0);                    /* sterge 1 */
    show("Dupa delete_after_key(0):", list);          /* 0 4 22 25 3 */

    dll_delete_before_key(list, 3);                   /* sterge 25 (ultimul-1) */
    show("Dupa delete_before_key(3):", list);         /* 0 4 22 3 */

    dll_delete_before_key(list, 4);                   /* sterge 0 (primul) */
    show("Dupa delete_before_key(4):", list);         /* 4 22 3 */

    /* ---- delete_all (chei duplicate, la capete si la mijloc) ---- */
    dll_insert_first(list, 22);
    dll_insert_last(list, 22);
    dll_insert_last(list, 22);
    show("Inainte de delete_all(22):", list);         /* 22 4 22 3 22 22 */

    dll_delete_all(list, 22);
    show("Dupa delete_all(22):", list);               /* 4 3 */

    /* ---- un singur nod ---- */
    dll_clear(list);
    dll_insert_first(list, 5);
    dll_delete_before_key(list, 5);                   /* nimic */
    dll_delete_after_key(list, 5);                    /* nimic */
    dll_reverse(list);
    show("Lista cu un singur nod (dupa reverse):", list);   /* 5 */

    dll_delete_last(list);
    show("Dupa delete_last pe singurul nod:", list);  /* GOALA */
    printf("Lista vida? %s\n", dll_is_empty(list) ? "da" : "nu");

    dll_destroy(&list);
    return 0;
}
