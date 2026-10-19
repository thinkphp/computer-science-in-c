#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 256

typedef struct Node {
    char *word;
    int freq;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} List;

static Node *new_node(const char *w) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) return NULL;
    n->word = (char *)malloc(strlen(w) + 1);
    if (!n->word) { free(n); return NULL; }
    strcpy(n->word, w);
    n->freq = 1;
    n->prev = n->next = NULL;
    return n;
}

/* Insereaza cuvantul pastrand lista ordonata alfabetic.
 * Daca exista deja, doar creste frecventa. Returneaza 0 la eroare de memorie. */
static int insert_word(List *l, const char *w) {
    Node *p = l->head;
    while (p && strcmp(p->word, w) < 0)   /* primul nod cu cuvant >= w */
        p = p->next;

    if (p && strcmp(p->word, w) == 0) {   /* cuvant deja existent */
        p->freq++;
        return 1;
    }

    Node *n = new_node(w);
    if (!n) return 0;

    if (!p) {                             /* inserare la sfarsit (sau lista goala) */
        n->prev = l->tail;
        if (l->tail) l->tail->next = n; else l->head = n;
        l->tail = n;
    } else {                              /* inserare inaintea lui p */
        n->next = p;
        n->prev = p->prev;
        if (p->prev) p->prev->next = n; else l->head = n;
        p->prev = n;
    }
    return 1;
}

static void print_asc(const List *l) {
    for (Node *p = l->head; p; p = p->next)
        printf("%s: %d\n", p->word, p->freq);
}

static void print_desc(const List *l) {
    for (Node *p = l->tail; p; p = p->prev)
        printf("%s: %d\n", p->word, p->freq);
}

static void free_list(List *l) {
    Node *p = l->head;
    while (p) {
        Node *next = p->next;
        free(p->word);
        free(p);
        p = next;
    }
    l->head = l->tail = NULL;
}

int main(void) {
    List l = { NULL, NULL };
    int n;
    char w[MAX_WORD];

    printf("n = ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Valoare invalida pentru n\n");
        return 1;
    }

    printf("Introduceti %d cuvinte:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%255s", w) != 1) {
            printf("Intrare incompleta\n");
            break;
        }
        if (!insert_word(&l, w)) {
            printf("Memorie insuficienta\n");
            free_list(&l);
            return 1;
        }
    }

    printf("\na) Ordine alfabetica crescatoare:\n");
    print_asc(&l);

    printf("\nb) Ordine alfabetica descrescatoare:\n");
    print_desc(&l);

    free_list(&l);
    return 0;
}
