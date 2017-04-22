#include<iostream>
#include<fstream>
#include<list>
#define FIN "graph_adjacency.in"
 
using namespace std;
 
class Graph {

    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists

public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V+1];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int start_node)
{
    int node;
 
 // Mark all the vertices as not visited
    bool *visited = new bool[this->V];

    for(int i = 0; i < this->V; i++) visited[i] = false;
  
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[start_node] = true;
  
    queue.push_back(start_node);
  
    while(!queue.empty())
    {
        node = queue.front();
      
        cout << node << " ";
      
        queue.pop_front();
 
        for(list<int>::iterator i = adj[node].begin(); i != adj[node].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
 
}

int main() {

 int nodes, 
     edges, 
     a, b;

 freopen(FIN, "r", stdin);
  
 cin>>nodes>>edges;

 Graph g(nodes);

 while(edges--) {

       cin>>a>>b; 
       g.addEdge(a,b); 
 }

 g.BFS(1);

return(0);
}