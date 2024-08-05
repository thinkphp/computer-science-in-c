/*
Arborele partial de cost minim
------------------------------


Fie G = (V, E) un graf neorientat , conex, ponderat.
Fiecare muchie (i, j) are asociata un cost c(i,j) >=0. Se cere un arbore partial al lui G
, astfel incat suma constului muchiilor sale sa fie minima.

Un asemenea arbore se numeste arbore partial de cost minim.

Algorimul lui Kruskal:

- initial, fiecare nod va constitui un ARBORE. prin urmare vom avea o padure alcatuita
din n arbori. Apoi se executa de n-1 ori pasul urmator.
- se cauta muchia de cost minim care uneste noduri care apartin la doi arbori diferiti.
se selecteaza muchia respectiva.

Dupa selectarea celor n-1 muchii, se obtine un arbore partial de cost minim.

Selectam muchia (2,4)
selectam muchia (1,2)
selectam muchia (1,5)
selectam muchia (4,3)

Costul arborelui partial = 2 + 3 + 1 + 4 = 10


#endif /* end of includ o padure alcatuita
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define FIN "apm.in"
#define FOUT "apm.out"

using namespace std;

struct Edge {
     int u,
         v,
         cost;
};

//functie de compare dupa cost in ordine ascendenta
bool comparaEdges(const Edge &a, const Edge &b) {

     return a.cost < b.cost;
};

class UnionFind {

      public:
      UnionFind(int n) {

          parent.resize(n);
          rank.resize(n,0);
          for(int i = 0; i < n; ++i) {
            parent[i] = i;
          }
      }

      int find(int u) {
         if(u!=parent[u]) {
           parent[u] = find(parent[u]);
         }
         return parent[u];
      }

      void Union(int x, int y) {
           int rootX = find(x);
           int rootY = find(y);

           if(rootX != rootY) {
             if(rank[rootX] > rank[rootY]) {
                   parent[rootY] = rootX;
             } else if(rank[rootX] < rank[rootY]) {
                   parent[rootX] = rootY;
             } else {
                 parent[rootY] = rootX;
                 rank[rootX]++;
             }
           }
      }

        private:
        vector<int> parent;
        vector<int> rank;


};

int main(int argc, char const *argv[]) {

  ifstream infile(FIN);
  ofstream outfile(FOUT);

  int N, M;
  infile>>N>>M;

  vector<Edge> edges(M);//declaram un vector de muchii asociate unui cost

  for(int i = 0; i < M; ++i) infile >> edges[i].u >> edges[i].v >> edges[i].cost;

  for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {

            cout<<"muchia ["<<(*it).u<<","<<(*it).v<<"] si COST="<<(*it).cost<<"\n";
  }

  //sortam
  sort(edges.begin(), edges.end(), comparaEdges);

  cout<<"\n-----------------------------------------\n";

  for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {

            cout<<"muchia ["<<(*it).u<<","<<(*it).v<<"] si COST="<<(*it).cost<<"\n";
  }

  UnionFind uf(N+1);

  vector<Edge> mst;//mst = Minimum Spanning Tree

  int totalCost = 0;

  //step 2: selectam muchii de cost minim care au nodurile in arbori diferiti
  for(auto &edge : edges) {

            //sa fie in arbori diferiti, UNION
            if(uf.find(edge.u) != uf.find(edge.v)) {

                   uf.Union(edge.u, edge.v);
                   mst.push_back(edge);
                   totalCost += edge.cost;
            }
  }

  cout<<totalCost<<endl;
  cout<<mst.size()<<endl;
  for(const Edge &edge: mst) {
        cout<<edge.v<<" "<<edge.u << "\n";
  }
  return 0;
}
