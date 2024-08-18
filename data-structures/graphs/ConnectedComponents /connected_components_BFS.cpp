#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void read_input(vector<vector<int>>& graph) {
    int n, m;
    cout << "Numărul de noduri: ";
    cin >> n;
    cout << "Numărul de relații: ";
    cin >> m;
    
    graph.resize(n);
    
    cout << "Introduceți relațiile (i, j):" << endl;
    for (int k = 0; k < m; ++k) {
        int u, v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
}

void bfs(const vector<vector<int>>& graph, int start, vector<bool>& visited, vector<int>& component) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    component.push_back(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                component.push_back(neighbor);
                q.push(neighbor);
            }
        }
    }
}

vector<vector<int>> find_connected_components(const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    vector<vector<int>> components;
    
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            vector<int> component;
            bfs(graph, i, visited, component);
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

