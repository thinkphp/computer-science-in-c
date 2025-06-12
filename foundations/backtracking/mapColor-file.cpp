#include <iostream>
#include <fstream>
#define SIZE 100

using namespace std;

int stack[SIZE];
int A[SIZE][SIZE];
int level, n;

int sol() {
    return level == n;
}

void init() {
    stack[level] = 0;
}

int succ() {
    if (stack[level] < 4) {
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
    for (int i = 1; i <= n; ++i) {
        cout << "tara " << i << " are culoarea: " << stack[i] << endl;
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
    ifstream fin("graf.txt");
    if (!fin) {
        cerr << "Eroare la deschiderea fisierului graf.txt\n";
        return 1;
    }

    fin >> n;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> A[i][j];

    fin.close();

    backtracking();
}
