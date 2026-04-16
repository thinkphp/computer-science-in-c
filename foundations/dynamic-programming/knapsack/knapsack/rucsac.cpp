#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ifstream fin("rucsac.in");
    ofstream fout("rucsac.out");

    int n, G;
    fin >> n >> G;

    vector<int> g(n + 1), p(n + 1);

    for (int i = 1; i <= n; i++) {
        fin >> g[i] >> p[i];
    }

    vector<vector<int>> DP(n + 1, vector<int>(G + 1, 0));

    // Construire tabel
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= G; j++) {
            if (g[i] > j)
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = max(DP[i - 1][j],
                               DP[i - 1][j - g[i]] + p[i]);
        }
    }

    // 🔹 Afișare tabel DP
    fout << "Tabel Castig (DP):\n\n";

    // header coloane
    fout << "     ";
    for (int j = 0; j <= G; j++)
        fout << setw(3) << j;
    fout << "\n";

    for (int i = 0; i <= n; i++) {
        fout << "i=" << i << " ";
        for (int j = 0; j <= G; j++) {
            fout << setw(3) << DP[i][j];
        }
        fout << "\n";
    }

    fout << "\n";

    // 🔹 Profit maxim
    fout << "Profit maxim: " << DP[n][G] << "\n";

    // 🔹 Reconstruire soluție
    int j = G;
    vector<int> obiecte;

    for (int i = n; i >= 1; i--) {
        if (DP[i][j] != DP[i - 1][j]) {
            obiecte.push_back(i);
            j -= g[i];
        }
    }

    fout << "Obiecte alese: ";
    for (int i = obiecte.size() - 1; i >= 0; i--) {
        fout << obiecte[i] << " ";
    }

    fout << "\n";

    return 0;
}
