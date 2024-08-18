#include <iostream>
#include <vector>

using namespace std;

void read_input(vector<vector<int>>& graph) {
    int n, m;
    cout << "Numărul de triunghiuri: ";
    cin >> n;
    cout << "Numărul de relații: ";
    cin >> m;
    
    graph.resize(n);
    
    cout << "Introduceți relațiile de asemănare (i, j):" << endl;
    for (int k = 0; k < m; ++k) {
        int u, v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
}

void dfs(const vector<vector<int>>& graph, int node, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited, component);
        }
    }
}

vector<vector<int>> find_connected_components(const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    vector<vector<int>> components;
    
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(graph, i, visited, component);
            components.push_back(component);
        }
    }
    
    return components;
}

int main() {
    vector<vector<int>> graph;
    
    read_input(graph);
    
    vector<vector<int>> components = find_connected_components(graph);
    
    cout << "Componentele conexe sunt:" << endl;
    for (const auto& component : components) {
        for (int node : component) {
            cout << node + 1 << " ";  // Afișăm nodurile 1-based
        }
        cout << endl;
    }
    
    return 0;
}

