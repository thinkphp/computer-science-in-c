#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

int main() {
    ifstream fin("tsp.txt");

    int n;
    fin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> dist[i][j];

    vector<bool> visited(n, false);
    vector<int> path;

    int current = 0;
    visited[current] = true;
    path.push_back(current);

    int totalCost = 0;

    for (int step = 1; step < n; step++) {
        int next = -1;
        int bestDist = numeric_limits<int>::max();

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[current][i] < bestDist) {
                bestDist = dist[current][i];
                next = i;
            }
        }

        visited[next] = true;
        path.push_back(next);
        totalCost += bestDist;
        current = next;
    }

    // întoarcere la start
    totalCost += dist[current][0];
    path.push_back(0);

    // afișare rezultat
    cout << "Drum: ";
    for (int x : path)
        cout << x << " ";

    cout << "\nCost total: " << totalCost << "\n";

    fin.close();
    return 0;
}
