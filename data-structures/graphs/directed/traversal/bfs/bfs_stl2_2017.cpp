#include<iostream>
#include<fstream>
#include<list>
#define FIN "graph_adjacency.in"

typedef struct queue {
        int data;
        struct queue *link;
} Queue;


Queue *Front, 
      *Rear;
 
using namespace std;


//inserts a new element at the end of the queue, after its current last element. 
//the content of the new element is initialized to val.
void push(Queue**rear,int data)
{

     if((*rear) == NULL) {

                (*rear) = new Queue;
                (*rear)->data = data;
                (*rear)->link = NULL;
                 Front = (*rear);

     } else {

                Queue *temp = new Queue;
                temp->data = data;
                temp->link = NULL;
                (*rear)->link = temp;
                (*rear) = temp;
     }
};

//removes the next element in the queue, effectively reducing its size by one.
int pop() {

    Queue *c = Front;

           if(c == NULL) return 0;
  
           if(c->link != NULL) {

               Front = Front->link;
  
               delete c;     

           } else {

             Rear = Front = NULL;

             delete Front;

           }
}


//returns a reference to the next element in the queue.
int front() {

    Queue *c = Front;

    if(c) return c->data;
}



int isEmpty(Queue*queue) {

    if((queue) == NULL) return 1;

           else return 0;
}



 
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
 
    bool *visited = new bool[this->V];  // Mark all the vertices as not visited

    for(int i = 0; i < this->V; i++) visited[ i ] = false;
 
    push(&Rear, start_node);
  
    // Mark the current node as visited and enqueue it
    visited[start_node] = true;
 
 
    while(!isEmpty(Front))
    {

        node = front();  

        cout << node << " ";

        pop();
 
        for(list<int>::iterator i = adj[node].begin(); i != adj[node].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;

                push(&Rear,*i);
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