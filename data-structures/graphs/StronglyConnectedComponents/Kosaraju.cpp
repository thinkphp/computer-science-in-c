#include <fstream>
#include <vector>
#include <stack>
#define MAXN 10001
using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

class Kosaraju {

  // constructor-ul clasei
  public:
    Kosaraju(int N, int M): nodes( N ),
                            edges( M ),
                            comp( 0 ),
                            Graph(2 * N + 1),
                            Graph_reverse(2 * N + 1),
                            isVisited(2 * N + 1),
                            Results(2 * N + 1){}

  void addEdges(int x, int y) {
    Graph[x].push_back(y);
    Graph_reverse[y].push_back(x);
  }

  void DFS(int node) {
    isVisited[node] = 1;
    for (vector<int>::iterator it = Graph[node].begin(); it != Graph[node].end(); ++it) {
      if (!isVisited[*it]) {
        DFS(*it);
      }
    }
    Stack.push(node);
  }

  void DFS_Reverse(int node) {
    isVisited[node] = 1;
    Results[comp].push_back(node);
    for (vector<int>::iterator it = Graph_reverse[node].begin(); it != Graph_reverse[node].end(); ++it) {
      if (!isVisited[*it]) {
        DFS_Reverse(*it);
      }
    }
    Stack.push(node);
  }

  // kosaraju in action
  void solve() {
    int vertex = 0;
    for (int i = 1; i <= nodes; i++)
      if (!isVisited[i]) {
        DFS(i);
      }
    for (int v = 1; v <= nodes + 1; v++) isVisited[v] = 0;
    while (!Stack.empty()) {
      vertex = Stack.top();
      Stack.pop();
      if (!isVisited[vertex]) {
        comp++;
        DFS_Reverse(vertex);
      }
    }
  }

  void writeData() {
    // Scriem numarul de componente tare conexe
    fout << comp << '\n';

    for (int i = 1; i <= comp; i++) {
      for (vector<int>::iterator it = Results[i].begin(); it != Results[i].end(); ++it) {
        fout << *it << " ";
      }
      fout << '\n';
    }
  }

  private:
    int nodes, edges, comp;
    vector<vector<int>> Graph;
    vector<vector<int>> Graph_reverse;
    vector<vector<int>> Results;
    vector<int> isVisited;
    stack<int> Stack;
}; // end class Kosaraju


int main() {
  int n, // nr de noduri
      m, // nr de arce
      x, // doua noduri
      y; //
  fin >> n >> m;
  Kosaraju ob(n,m);
  for (int i = 1; i <= m; i++) {
    fin >> x >> y;
    ob.addEdges(x,y);
  }

  fin.close();
  ob.solve();
  ob.writeData();
  return 0;
}
