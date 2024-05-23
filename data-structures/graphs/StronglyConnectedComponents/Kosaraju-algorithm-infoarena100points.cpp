#include <bits/stdc++.h>
#define FIN "ctc.in"
#define FOUT "ctc.out"

using namespace std;

class Kosaraju {

      public:
      //constructor clasei
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

           isVisited[ node ] = 1;

           for(vector<int>::iterator it = Graph[node].begin(); it != Graph[node].end(); ++it ) {

               if(!isVisited[*it]) {

                 DFS(*it);
               }
           }

           Stack.push( node );
      }

      void DFS_Reverse(int node) {

           isVisited[ node ] = 1;

           Results[ comp ].push_back( node );

           for(vector<int>::iterator it = Graph_reverse[ node ].begin(); it != Graph_reverse[node].end(); it++) {

               if(!isVisited[ *it ]) {

                 DFS_Reverse( *it );
               }
           }

           Stack.push( node );
      }

      //Kosaraju in Action
      void solve() {

           int vertex = 0;

           for(int i = 1; i <= nodes; ++i) {

               if(!isVisited[ i ]) {

                 DFS( i );
               }
           }

           //reset
           for(int v = 1; v <= nodes + 1; v++) isVisited[ v ] = 0;

           while( !Stack.empty() ) {

                 vertex = Stack.top();

                 Stack.pop();

                 if(!isVisited[ vertex ]) {

                    comp++;

                    DFS_Reverse( vertex );
                 }
           }

      }

      void Write_Strongly_Connected_Components() {

           freopen(FOUT, "w", stdout);

           cout<<comp<<"\n";//numarul total de componente tare conexe

           for(int i = 1; i <= comp; ++i) {

              for(vector<int>::iterator it = Results[i].begin(); it != Results[i].end(); it++) {

                  cout<<(*it)<<" ";
              }

              cout<<'\n';
           }
      }

      //datale private
      private:
      int nodes, edges, comp;
      vector<vector<int>> Graph;
      vector<vector<int>> Graph_reverse;
      vector<vector<int>> Results;
      vector<int> isVisited;
      stack<int> Stack;
};

int main(int argc, char const *argv[]) {

  int n, //numarul de noduri
      m, //numarul de arce
      x, y;//noduri

  freopen(FIN, "r", stdin);

  cin>>n>>m;

  Kosaraju obiect(n, m);

  for(int i = 1; i <= m; ++i) {

      cin>>x>>y;

      obiect.addEdges(x,y);
  }

  fclose( stdin );

  //apelam metoda membra a obiectului Kosaraju
  obiect.solve();

  obiect.Write_Strongly_Connected_Components();

  return 0;
}
