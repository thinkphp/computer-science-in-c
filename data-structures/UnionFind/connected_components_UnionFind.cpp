#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
metoda UnionFind MST
Minimum Spanning Tree = arborele partial de cost minim

Problema:
Cum determinam componentele conexe ale unui graf folosind UnionFind?

Graf:
1 2
2 3
3 4
5 6
6 7

1. DFS

              void DFS(int node) {

                     visited[node] = 1

                     current_component.push_back( node )

                     for(int j = 0; j < ListAdj[node].size(); ++j) {

                       if(!visited[ListAdj[node][j]])

                       DFS(ListAdj[node][j])
                     }
              }


     void solve() {

             for(int node = 1; node <= num_nodes; ++node) {

                   if(!visited[node]) num_components++;

                   current_component.clear();

                   DFS(node);

                   //print components
                   for(int i = 0; i < current_component.size(); ++i)

                   cout<<current_component[i]<<" "
             }
     }
2. BFS

*/

class UnionFind {

      private:
      vector<int> parent;
      vector<int> rank;

      public:
        UnionFind(int size) {

            parent.resize(size);
            rank.resize(size, 0);
            for(int i = 0; i < size; ++i) parent[i] = i;
        }

        int find(int x) {

            if(parent[x]!=x) {
               parent[x] = find(parent[x]); //path compression
            }
            return parent[x];
        }

        void unionfind(int x, int y) {

             int rootX = find(x);

             int rootY = find(y);

             if(rootX != rootY) {

                 if(rank[rootX] > rank[rootY]) {

                   parent[rootY] = rootX;

                 }else if(rank[rootX] < rank[rootY]) {

                   parent[rootX] = rootY;

                 } else {
                   parent[rootY] = rootX;
                   ++rank[rootX];
                 }
             }
        }


};

vector<vector<int>> find_connected_components(int n, const vector<pair<int, int>>& edges) {

    UnionFind uf( n );

     //unim nodurile bazate pe muchiile date

     for(const auto&edge: edges) {

         uf.unionfind(edge.first, edge.second);
     }

     unordered_map<int, vector<int>> components;

     //cream un map pentru a colecta componentele conexe
     for(int i = 0; i < n; ++i) {

         int root = uf.find(i);

         components[root].push_back(i);
     }

     //convertim map-ul intr-un vector de componente

     vector<vector<int>> result;

     for(const auto&component : components) {

            result.push_back(component.second);
     }

     return result;

}

void read_graph(vector<pair<int, int>>&edges, int &n) {

      freopen("graph.in", "r", stdin);

      int m;

      cin>>n>>m;

      for(int k = 0; k < m; ++k) {

            int u, v;

            cin>>u>>v;

            edges.emplace_back(u-1, v-1);//conversie la 0-based index
      }
}

int main(int argc, char const *argv[]) {

  //
  vector<pair<int, int>> edges;

  int n;

  read_graph( edges, n );

  vector<vector<int>>components = find_connected_components(n, edges);


  cout<<"Componentele conexe sunt:\n";

  for(const auto&component: components) {

       for(int node: component) {

           cout<<node + 1<<" ";//afisam nodurile 1-based
       }

       cout<<"\n";
  }
  return 0;
}
