/*
Input:
Sa se scrie un program care citeste un numar de relatii de forma (i,j)
Semnificatia este: triunghiul i este asemenea cu triunghiul j,
Apoi se vor citi din nou doua numere (i,j) cu Semnificatia de triunghiuri.

Ouput:
Se cere sa se determine daca triunghiurile sunt asemenea sau nu.

Solutii:
Daca se afla i si j pe aceeasi componenta conexa atunci sunt asemenea,
altfel nu sunt asemenea
- solutia 1 BFS
- solutia 2 DFS
- solutia 3 Union-Find (paduri de multimi disjuncte)

*/
//Depth First Search DFS
//codul este asemanator cu cel din BFS
#include <iostream>
#include <vector>
using namespace std;

void read_input(vector<vector<int>> &graph, int& i, int& j) {

     int n, m;
     cout<<"Numarul de triunghiuri:";
     cin>>n;
     cout<<"Numarul de relatii:";
     cin>>m;
     /*
     numarul de triunghiuri: 5
     numarul de relatii: 4
     1 2
     2 3
     3 4
     4 5

     1 5
     Output: triunghiul 1 este asemenea cu triunghiul 5
     */

     graph.resize(n);

     cout<<"Introduceti relatiile de asemenare(i,j)"<<endl;

     for(int k = 0; k < m; k++) {

        int u, v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
     }

     cout<<"Introduceti triunghiurile de verificat (i,j)";

     cin>>i>>j;

    //folosim de la 0 indecsi...
    i--;j--;
}

//parcurgea in latime foloseste o Coada (FIFO) First - in - first out
//exploram cat mai adanc fiecare ramura a grafului inainte de a reveni si a explora alte ramuri
void DFS(const vector<vector<int>> &graph, int node, vector<bool> &visited) {

    visited[ node ] = true;

    for(int neighbor: graph[ node ])  {

            if(!visited[neighbor]) {

                DFS(graph, neighbor, visited);

            }
    }

}

/*
functia are_similar seamana cu cea din versiunea BFS, dar in loc sa apeleze BFS , apeleaza
DFS pentru a verifica daca triunghiul i este asemenea cu triunghiul j.
*/
bool are_similar(const vector<vector<int>> &graph, int i, int j) {

  vector<bool> visited(graph.size(), false);

  DFS(graph, i, visited);

  return visited[ j ];

}

int main(int argc, char const *argv[]) {

  //declaram graful
  vector<vector<int>> Graph;

  int i, j;

  read_input(Graph, i, j);

  //cout<<i<<"-"<<j;

  if(are_similar(Graph, i, j)) {

     cout<<"triunghiurile "<<i+1<<" si "<<j+1<<"sunt asemenea!";

  } else {

     cout<<"triunghiurile "<<i+1<<" si "<<j+1<<" nu sunt asemenea!";
  }

  return 0;
}
