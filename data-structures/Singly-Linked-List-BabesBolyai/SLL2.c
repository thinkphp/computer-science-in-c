#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * Laborator 2 - Lista simplu inlantuita (SDA)
 *
 *   first                                         last
 *     |                                             |
 *   [key|next] -> [key|next] -> ... -> [key|NULL]
 */

/* ---------- STRUCTURI  ---------- */

typedef struct _SLL_NODE {
    int key;                    /* key field */
    struct _SLL_NODE *next;     /* reference / pointer to next node */
} SLL_NODE;

typedef struct {
    SLL_NODE *first;            /* reference / pointer to the first node */
    SLL_NODE *last;             /* reference / pointer to the last node  */
} SL_LIST;


/* ---------- CREARE / DISTRUGERE ---------- */

/* regula 3 din PDF: malloc + memset (nu calloc) */
static SLL_NODE *sll_create_node(int value) {

    SLL_NODE *node = NULL;

    node = (SLL_NODE *)malloc(sizeof(SLL_NODE));

    if (node == NULL) {
        fprintf(stderr, "Err: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    memset(node, 0, sizeof(SLL_NODE));   /* next = NULL */
    node->key = value;

    return node;
}

SL_LIST *sll_create(void) {

    SL_LIST *list = NULL;

    list = (SL_LIST *)malloc(sizeof(SL_LIST));

    if (list == NULL) {
        fprintf(stderr, "Err: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    memset(list, 0, sizeof(SL_LIST));    /* first = last = NULL */

    return list;
}


/* ---------- CAUTARE ---------- */

/* returneaza adresa nodului cu cheia givenKey, sau NULL daca nu exista */
SLL_NODE *sll_search(const SL_LIST *list, int givenKey) {

    SLL_NODE *crt_node = list->first;

    while (crt_node != NULL) {
        if (crt_node->key == givenKey) return crt_node;
        crt_node = crt_node->next;
    }

    return NULL;
}


/* ---------- INSERARE (Ex. 2) ---------- */

void sll_insert_first(SL_LIST *list, int given_key) {

    SLL_NODE *node = sll_create_node(given_key);

    if (list->first == NULL) {           /* lista vida */
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first = node;
    }
}

void sll_insert_last(SL_LIST *list, int given_key) {

    SLL_NODE *node = sll_create_node(given_key);

    if (list->first == NULL) {           /* lista vida */
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;         /* O(1) datorita lui last */
        list->last = node;
    }
}

/* insereaza `value` dupa nodul cu cheia `given_key` (nu face nimic daca nu exista) */
void sll_insert_after_key(SL_LIST *list, int given_key, int value) {

    SLL_NODE *crt_node = sll_search(list, given_key);

    if (crt_node == NULL) return;        /* cheia nu exista */

    SLL_NODE *node = sll_create_node(value);

    node->next = crt_node->next;
    crt_node->next = node;

    if (crt_node == list->last)          /* am inserat dupa ultimul nod */
        list->last = node;
}

/* insereaza `value` inaintea nodului cu cheia `before_key`; false daca nu exista */
bool sll_insert_before_key(SL_LIST *list, int before_key, int value) {

    SLL_NODE *crt_node = list->first;
    SLL_NODE *trail = NULL;

    while (crt_node != NULL) {
        if (crt_node->key == before_key) break;
        trail = crt_node;
        crt_node = crt_node->next;
    }

    if (crt_node == NULL) return false;  /* cheia nu exista */

    SLL_NODE *node = sll_create_node(value);

    if (crt_node == list->first) {       /* inserare inaintea primului */
        node->next = list->first;
        list->first = node;
    } else {
        trail->next = node;
        node->next = crt_node;
    }

    return true;
}

int sll_length(const SL_LIST *list) {

    int count = 0;

    for (SLL_NODE *c = list->first; c != NULL; c = c->next) count++;

    return count;
}

/* insereaza pe pozitia pos (0 = inceput, length = sfarsit); false daca pos invalid */
bool sll_insert_at(SL_LIST *list, int pos, int value) {

    if (pos < 0 || pos > sll_length(list)) return false;

    if (pos == 0) {
        sll_insert_first(list, value);
        return true;
    }

    if (pos == sll_length(list)) {
        sll_insert_last(list, value);
        return true;
    }

    SLL_NODE *c = list->first;

    for (int i = 0; i < pos - 1; ++i) c = c->next;

    SLL_NODE *node = sll_create_node(value);

    node->next = c->next;
    c->next = node;

    return true;
}


/* ---------- CITIRE / MODIFICARE ---------- */

/* citeste cheia de pe pozitia pos; false daca pos este invalid */
bool sll_get_at(const SL_LIST *list, int pos, int *out) {

    if (pos < 0) return false;

    for (SLL_NODE *c = list->first; c != NULL; c = c->next, pos--) {
        if (pos == 0) {
            *out = c->key;
            return true;
        }
    }

    return false;
}

/* actualizeaza prima aparitie a lui oldKey; false daca nu exista */
bool sll_update(SL_LIST *list, int oldKey, int newKey) {

    SLL_NODE *node = sll_search(list, oldKey);

    if (node == NULL) return false;

    node->key = newKey;

    return true;
}

/* inverseaza lista pe loc */
void sll_reverse(SL_LIST *list) {

    SLL_NODE *prev = NULL;
    SLL_NODE *curr = list->first;

    list->last = list->first;            /* fostul prim devine ultim */

    while (curr != NULL) {
        SLL_NODE *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    list->first = prev;
}

void sll_print(const SL_LIST *list) {

    if (list->first == NULL) {
        printf("Lista este GOALA! {}\n");
        return;
    }

    for (SLL_NODE *c = list->first; c != NULL; c = c->next) {
        printf("%d", c->key);
        if (c->next) printf(" -> ");
    }

    printf(" -> NULL\n");
}


/* ---------- STERGERE (Ex. 4) ---------- */

void sll_delete_first(SL_LIST *list) {

    SLL_NODE *node = list->first;

    if (node == NULL) return;            /* lista vida */

    list->first = list->first->next;

    free(node);
    node = NULL;

    if (list->first == NULL)             /* lista a devenit vida */
        list->last = NULL;
}

void sll_delete_last(SL_LIST *list) {

    SLL_NODE *crt_node = list->first;
    SLL_NODE *trail = NULL;

    if (crt_node == NULL) return;        /* lista vida */

    while (crt_node != list->last) {     /* avansam spre final */
        trail = crt_node;
        crt_node = crt_node->next;
    }

    if (crt_node == list->first) {       /* un singur nod */
        list->first = NULL;
        list->last = NULL;
    } else {
        trail->next = NULL;
        list->last = trail;
    }

    free(crt_node);
    crt_node = NULL;
}

void sll_delete_key(SL_LIST *list, int givenKey) {

    SLL_NODE *crt_node = list->first;
    SLL_NODE *trail = NULL;

    while (crt_node != NULL) {
        if (crt_node->key == givenKey) break;
        trail = crt_node;
        crt_node = crt_node->next;
    }

    if (crt_node == NULL) return;        /* cheia nu exista */

    if (crt_node == list->first) {       /* primul nod */
        list->first = list->first->next;
        if (list->first == NULL) list->last = NULL;
    } else {
        trail->next = crt_node->next;
        if (crt_node == list->last) list->last = trail;
    }

    free(crt_node);
    crt_node = NULL;
}

/* stergere completa: stergem primul element in mod repetat */
void sll_clear(SL_LIST *list) {

    while (list->first != NULL) sll_delete_first(list);
}

/* elibereaza si structura listei; pune pointerul pe NULL (regula 3) */
void sll_destroy(SL_LIST **list) {

    if (*list == NULL) return;

    sll_clear(*list);

    free(*list);
    *list = NULL;
}


/* ---------- MAIN ---------- */

int main( void ) {

    SL_LIST *list = sll_create();

    /* ===== Ex. 3 ===== */
    sll_insert_first(list, 4);
    sll_insert_first(list, 1);
    sll_insert_last(list, 3);

    printf("Cautare cheia 2: %s\n", sll_search(list, 2) ? "gasita" : "negasita");
    printf("Cautare cheia 3: %s\n", sll_search(list, 3) ? "gasita" : "negasita");

    sll_insert_after_key(list, 4, 22);
    sll_insert_after_key(list, 3, 25);

    printf("\nLista dupa Ex. 3:\n");
    sll_print(list);                     /* 1 -> 4 -> 22 -> 3 -> 25 */

    /* ===== functii suplimentare ===== */
    printf("\ninsert_before_key(4, 99):\n");
    sll_insert_before_key(list, 4, 99);
    sll_print(list);

    printf("\ninsert_before_key(1, 0)  [key = first]:\n");
    sll_insert_before_key(list, 1, 0);
    sll_print(list);

    printf("\ninsert_at(3, 77):\n");
    sll_insert_at(list, 3, 77);
    sll_print(list);

    int val;
    if (sll_get_at(list, 2, &val)) printf("\nget_at(2) = %d\n", val);

    sll_update(list, 99, 100);
    printf("\nupdate(99 -> 100):\n");
    sll_print(list);

    sll_reverse(list);
    printf("\nDupa reverse:\n");
    sll_print(list);
    sll_reverse(list);                   /* revenim la ordinea initiala */

    /* ===== Ex. 5 ===== */
    sll_delete_first(list);
    sll_delete_last(list);
    sll_delete_key(list, 22);
    sll_delete_key(list, 8);             /* nu exista: nu se intampla nimic */

    printf("\nLista dupa stergeri:\n");
    sll_print(list);

    sll_clear(list);
    printf("\nDupa stergerea completa:\n");
    sll_print(list);

    sll_destroy(&list);                  /* list == NULL dupa apel */

    return 0;
}
