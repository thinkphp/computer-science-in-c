#include <iostream>
#define SIZE 100

using namespace std;

int stack[SIZE];
int A[SIZE][SIZE];
int level, n, k; // n = număr de țări, k = număr de culori

int sol() {
    return level == n;
}

void init() {
    stack[level] = 0;
}

int succ() {
    if (stack[level] < k) {
        stack[level]++;
        return 1;
    }
    return 0;
}

int valid() {
    for (int i = 1; i <= level - 1; ++i) {
        if (stack[i] == stack[level] && A[i][level] == 1)
            return 0;
    }
    return 1;
}

void display_solution() {
    cout << "Solutie gasita:\n";
    for (int i = 1; i <= n; ++i) {
        cout << "Tara " << i << " are culoarea: " << stack[i] << endl;
    }
    cout << endl;
}

void backtracking() {
    int s, v;
    level = 1;

    while (level > 0) {
        s = 1;
        v = 0;

        while (s && !v) {
            s = succ();
            if (s)
                v = valid();
        }

        if (s) {
            if (sol()) {
                display_solution();
            } else {
                level++;
                init();
            }
        } else {
            level--;
        }
    }
}

int main() {
    cout << "Numar de tari: ";
    cin >> n;

    cout << "Numar de culori: ";
    cin >> k;

    // Initializare matrice cu 0
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            A[i][j] = 0;

    // Citire matrice de adiacenta (doar sub diagonala)
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            cout << "Exista granita intre tara " << i << " si tara " << j << "? (1/0): ";
            cin >> A[i][j];
            A[j][i] = A[i][j]; // simetric
        }
    }

    // Inițializare primă poziție
    init();

    // Pornim backtracking
    backtracking();

    return 0;
}

/*
Numar de tari: 4
Numar de culori: 3
Exista granita intre tara 2 si tara 1? (1/0): 1
Exista granita intre tara 3 si tara 1? (1/0): 1
Exista granita intre tara 3 si tara 2? (1/0): 0
Exista granita intre tara 4 si tara 1? (1/0): 1
Exista granita intre tara 4 si tara 2? (1/0): 1
Exista granita intre tara 4 si tara 3? (1/0): 1

*/
