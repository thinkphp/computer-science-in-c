#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <random>
#include <climits>

using namespace std;

ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

const int MOD = 700001;

struct Node {
    long long value;
    Node *next;
};

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
    Node *newNode = new Node();
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

    delete currentHead;
}

int main() {
    long long n;

    fin >> n;

    for (long long i = 0; i < MOD; ++i) {
        ListNode[i] = NULL;
    }

    for (long long i = 0; i < n; ++i) {
        long long type;
        long long value;
        fin >> type >> value;

        if (type == 1) {
            insert(value);
        } else if (type == 2) {
            deleteElement(value);
        } else if (type == 3) {
            fout << searchElement(value);
            fout << "\n";
        }
    }

    return 0;
}
