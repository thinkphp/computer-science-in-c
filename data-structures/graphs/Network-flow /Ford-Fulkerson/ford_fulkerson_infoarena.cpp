#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#define DIM 1010
#define file_in "maxflow.in"
#define file_out "maxflow.out"
#define INF 314700000

using namespace std;

inline int Minim(int x,int y){ return x<y ? x:y; }

vector<int> Graph[DIM];
vector<int>::iterator it;
queue<int> Q;
int Capacity[DIM][DIM], Flow[DIM][DIM];
int pre[DIM], explored[DIM];
int flowmax, flowmin, x;
int nodes, edges;

int bfs() {

    int node;

    memset(explored, 0, sizeof(explored));

    Q.push(1);

    explored[1] = 1;

    while( !Q.empty() ) {

            node = Q.front();

            if(node != nodes) {

               for(it = Graph[ node ].begin(); it != Graph[ node ].end(); ++it)

                  if(!explored[*it] && Capacity[node][*it] > Flow[node][*it]) {
                      explored[*it] = 1;
                      pre[*it] = node;
                      Q.push(*it);
                   }
             }
            Q.pop();

    }

    return explored[nodes];
}

int fulkerson() {

  while( bfs() )

    for(it = Graph[nodes].begin(); it!=Graph[nodes].end(); ++it)

             if(explored[*it]) {

                flowmin = INF;

                pre[nodes] = *it;

                for(x = nodes; flowmin != 0 && x!=1; x = pre[x]) {
                         flowmin = Minim(flowmin, Capacity[ pre[x] ][x] - Flow[ pre[x] ][x]);
                }

                if(flowmin==0) continue;

                for(x = nodes; x != 1; x = pre[x]) {
                    Flow[ pre[x] ][x] += flowmin;
                    Flow[x][ pre[x] ] -= flowmin;
                }

                flowmax += flowmin;
             }

    return flowmax;
}

int main(int argc, char const *argv[]) {

  int x, y, c;

  freopen(file_in,"r",stdin);
	freopen(file_out,"w",stdout);
  scanf("%d %d", &nodes, &edges);
  while(edges--){
    scanf("%d %d %d", &x, &y, &c);
      Capacity[x][y] = c;
      Graph[x].push_back(y);
      Graph[y].push_back(x);
  }

  printf("%d", fulkerson());
  return 0;
}
