#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Edge {
    int u, v, cost;
};

bool compareEdges(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                ++rank[rootU];
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    ifstream infile("apm.in");
    ofstream outfile("apm.out");

    int N, M;
    infile >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        infile >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    // Sort edges by their cost
    sort(edges.begin(), edges.end(), compareEdges);

    UnionFind uf(N + 1); // N + 1 because nodes are 1-indexed
    vector<Edge> mst;
    int totalCost = 0;

    for (const Edge &edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unite(edge.u, edge.v);
            mst.push_back(edge);
            totalCost += edge.cost;
        }
    }

    // Output the results
    outfile << totalCost << endl;
    outfile << mst.size() << endl;
    for (const Edge &edge : mst) {
        outfile << edge.u << " " << edge.v << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
