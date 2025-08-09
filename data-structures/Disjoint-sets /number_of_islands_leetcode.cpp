#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> parent, rank;
    int count;  // numărul de seturi disjuncte

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        count = n;
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;  // am unit două seturi, deci scad numărul total
        }
    }

    int getCount() {
        return count;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        UnionFind uf(n * m);

        int waterCount = 0;  // numărăm celulele de apă pentru ajustarea rezultatului

        // convertim coordonate 2D în index 1D: idx = i*m + j
        auto getIndex = [&](int i, int j) {
            return i * m + j;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') {
                    waterCount++;
                    continue;
                }

                // verific vecinii dreapta și jos
                if (j + 1 < m && grid[i][j + 1] == '1') {
                    uf.unite(getIndex(i, j), getIndex(i, j + 1));
                }
                if (i + 1 < n && grid[i + 1][j] == '1') {
                    uf.unite(getIndex(i, j), getIndex(i + 1, j));
                }
            }
        }

        // Numărul de insule = total celule - celule de apă - numărul de uniuni (implicit în count)
        return uf.getCount() - waterCount;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Numarul de insule este: " << sol.numIslands(grid) << "\n";

    return 0;
}

