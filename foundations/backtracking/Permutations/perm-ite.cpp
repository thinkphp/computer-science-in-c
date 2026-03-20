#include <iostream>
#include <fstream>
#define FOUT "perm.out"
#define FIN  "perm.in"

using namespace std;

const int MAX = 100;
int n, perm[MAX];

int readInput(const string& filename) {
    ifstream fin(filename);
    int val;
    fin >> val;
    return val;
}

bool isValid(int level) {
    for (int i = 1; i < level; i++) {
        if (perm[i] == perm[level]) return false;
    }
    return true;
}

void printSolution(ofstream& fout) {
    for (int i = 1; i <= n; i++) {
        cout << perm[i] << " ";
        fout << perm[i] << " ";
    }
    cout << "\n";
    fout << "\n";
}

void solve(ofstream& fout) {
    int level = 1;
    perm[level] = 0;

    while (level > 0) {
        bool found = false;
        while (perm[level] < n) {
            perm[level]++;
            if (isValid(level)) {
                found = true;
                break;
            }
        }
        if (found) {
            if (level == n) {
                printSolution(fout);
            } else {
                level++;
                perm[level] = 0;
            }
        } else {
            perm[level] = 0;
            level--;
        }
    }
}

int main() {
    n = readInput(FIN);
    ofstream fout(FOUT);
    solve(fout);
    fout.close();
    return 0;
}
