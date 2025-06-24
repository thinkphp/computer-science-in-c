#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm> // pentru std::fill, std::begin, std::end

#define MAX_VERTICES 100

using namespace std;

struct QueueNode {
    int vertex;
    int distance;
};

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int n_vertices;

bool read_graph_from_file(const string& filename, int& start_vertex, int& end_vertex) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Eroare: Nu pot deschide fisierul " << filename << endl;
        return false;
    }

    if (!(fin >> n_vertices >> start_vertex >> end_vertex)) {
        cout << "Eroare: Format invalid in fisier\n";
        fin.close();
        return false;
    }

    cout << "Numar de noduri: " << n_vertices << endl;
    cout << "Caut calea de la nodul " << start_vertex << " la nodul " << end_vertex << "\n\n";
    cout << "Matricea de adiacenta:\n";

    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            if (!(fin >> graph[i][j])) {
                cout << "Eroare: Nu pot citi matricea de adiacenta\n";
                fin.close();
                return false;
            }
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    fin.close();
    return true;
}

void write_result_to_file(const string& filename, int start_vertex, int end_vertex, int distance) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cout << "Eroare: Nu pot crea fisierul " << filename << endl;
        return;
    }

    fout << "=== REZULTAT SHORTEST PATH ===\n\n";
    fout << "Graf cu " << n_vertices << " noduri\n";
    fout << "Calea cautata: de la nodul " << start_vertex << " la nodul " << end_vertex << "\n\n";

    if (distance == -1) {
        fout << "REZULTAT: Nu exista cale intre nodul " << start_vertex << " si nodul " << end_vertex << "\n";
        cout << "Nu exista cale intre nodul " << start_vertex << " si nodul " << end_vertex << "\n";
    } else {
        fout << "REZULTAT: Cea mai scurta cale are lungimea: " << distance << "\n";
        cout << "Cea mai scurta cale de la nodul " << start_vertex << " la nodul " << end_vertex << ": " << distance << " muchii\n";
    }

    fout.close();
}

int shortest_path_bfs(int start_vertex, int end_vertex) {
    if (start_vertex == end_vertex) return 0;
    if (start_vertex < 0 || start_vertex >= n_vertices || end_vertex < 0 || end_vertex >= n_vertices) {
        cout << "Eroare: Noduri invalide (start=" << start_vertex << ", end=" << end_vertex << ", max=" << n_vertices - 1 << ")\n";
        return -1;
    }

    queue<QueueNode> q;
    fill(begin(visited), end(visited), false);

    q.push({start_vertex, 0});
    visited[start_vertex] = true;

    cout << "Incep BFS de la nodul " << start_vertex << "...\n";

    while (!q.empty()) {
        QueueNode current = q.front();
        q.pop();

        cout << "Vizitez nodul " << current.vertex << " (distanta " << current.distance << ")\n";

        for (int neighbor = 0; neighbor < n_vertices; neighbor++) {
            if (graph[current.vertex][neighbor] == 1 && !visited[neighbor]) {
                if (neighbor == end_vertex) {
                    cout << "Gasit nodul destinatie " << end_vertex << "!\n";
                    return current.distance + 1;
                }

                visited[neighbor] = true;
                q.push({neighbor, current.distance + 1});
                cout << "  -> Adaug vecinul " << neighbor << " in coada (distanta " << current.distance + 1 << ")\n";
            }
        }
    }

    cout << "BFS terminat - nu s-a gasit cale\n";
    return -1;
}

void display_menu() {
    cout << "\n=== SHORTEST PATH cu BFS ===\n\n";
    cout << "Acest program calculeaza cea mai scurta cale intr-un graf neponderat\n";
    cout << "folosind algoritmul Breadth-First Search (BFS).\n\n";
    cout << "Format fisier de intrare 'graph.txt':\n";
    cout << "Prima linie: n start_vertex end_vertex\n";
    cout << "Urmatoarele n linii: matricea de adiacenta n x n\n\n";
    cout << "Exemplu:\n";
    cout << "5 0 4\n";
    cout << "0 1 1 0 0\n";
    cout << "1 0 0 1 1\n";
    cout << "1 0 0 0 1\n";
    cout << "0 1 0 0 1\n";
    cout << "0 1 1 1 0\n\n";
}

int main() {
    display_menu();

    int start_vertex, end_vertex;

    if (!read_graph_from_file("graph.txt", start_vertex, end_vertex)) {
        return 1;
    }

    cout << "Calculez cea mai scurta cale...\n\n";
    int distance = shortest_path_bfs(start_vertex, end_vertex);

    write_result_to_file("shortest_path_result.txt", start_vertex, end_vertex, distance);

    cout << "\nRezultatul a fost salvat in 'shortest_path_result.txt'\n";

    return 0;
}

