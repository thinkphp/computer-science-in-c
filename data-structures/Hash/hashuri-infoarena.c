#include <stdio.h>
#include <stdlib.h>

#define MOD 700001

typedef struct Node {
    long long value;
    struct Node *next;
} Node;

Node *ListNode[MOD];

long long hashValue(long long value) {
    return value % MOD;
}

long long searchElement(long long value) {
    long long index = hashValue(value);

    Node *currentHead = ListNode[index];
    while (currentHead != NULL) {
        if (currentHead->value == value) {
            return 1;
        }
        currentHead = currentHead->next;
    }

    return 0;
}

void insert(long long value) {
    if (searchElement(value) == 1) {
        return;
    }
    long long index = hashValue(value);
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = ListNode[index];

    ListNode[index] = newNode;
}

void deleteElement(long long value) {
    long long indexHash = hashValue(value);

    Node *currentHead = ListNode[indexHash];
    Node *prevNode = NULL;

    long long index = 0, foundAt = -1;
    while (currentHead != NULL) {
        if (currentHead->value == value) {
            foundAt = index;
            break;
        }
        ++index;
        prevNode = currentHead;
        currentHead = currentHead->next;
    }
    if (foundAt == -1) {
        return;
    }

    if (prevNode == NULL) {
        ListNode[indexHash] = currentHead->next;
    } else {
        prevNode->next = currentHead->next;
    }

    free(currentHead);
}

int main() {
    FILE *fin = fopen("hashuri.in", "r");
    FILE *fout = fopen("hashuri.out", "w");
    
    if (fin == NULL || fout == NULL) {
        printf("Eroare la deschiderea fisierelor!\n");
        return 1;
    }

    long long n;

    fscanf(fin, "%lld", &n);

    for (long long i = 0; i < MOD; ++i) {
        ListNode[i] = NULL;
    }

    for (long long i = 0; i < n; ++i) {
        long long type;
        long long value;
        fscanf(fin, "%lld %lld", &type, &value);

        if (type == 1) {
            insert(value);
        } else if (type == 2) {
            deleteElement(value);
        } else if (type == 3) {
            fprintf(fout, "%lld\n", searchElement(value));
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
