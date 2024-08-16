#include <iostream>
#include <fstream>
#include <vector>

#define MAX 100005
#define FIN "dfs.in"
#define FOUT "dfs.out"
#define pb push_back

using namespace std;

vector<int> Adjacency_List[MAX];
vector<int> current_component;  // To store the current connected component
int num_nodes, num_edges, visited[MAX], num_components = 0;

ifstream fin(FIN);
ofstream fout(FOUT);

// function prototypes
void readGraph();
void solve();
void adjacency();
void dfs(int);

int main() {
    readGraph();
    solve();
    return 0;
};

void readGraph() {
    int x, y;
    fin >> num_nodes >> num_edges;

    for (; num_edges; num_edges--) {
        fin >> x >> y;
        Adjacency_List[x].pb(y);
        Adjacency_List[y].pb(x);
    }
};

void dfs(int node) {
    visited[node] = 1;
    current_component.pb(node);  // Add node to the current component

    for (int j = 0; j < Adjacency_List[node].size(); j++) {
        if (!visited[Adjacency_List[node][j]]) {
            dfs(Adjacency_List[node][j]);
        }
    }
}

void solve() {
    for (int node = 1; node <= num_nodes; node++) {
        if (!visited[node]) {
            num_components++;
            current_component.clear();  // Clear the current component before each new DFS
            dfs(node);

            // Print the current component
            for (int i = 0; i < current_component.size(); i++) {
                fout << current_component[i] << " ";
            }
            fout << endl;
        }
    }

    fout << "Number of connected components: " << num_components << endl;      
};

void adjacency() {
    for (int i = 1; i <= num_nodes; i++) {
        cout << i << " =>";

        for (int j = 0; j < Adjacency_List[i].size(); j++)  
            cout << Adjacency_List[i][j] << " ";

        cout << endl;
    }
}
