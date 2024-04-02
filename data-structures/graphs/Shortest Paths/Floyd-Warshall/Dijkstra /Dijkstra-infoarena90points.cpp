#include <iostream>
#include <fstream>

#include <vector>
#include <queue>
#include <list>

#include <algorithm>

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

#define NDEBUG

#ifdef NDEBUG
#define dbg	0 && (*((ostream *) 0))
#else
#define dbg cout
#endif

namespace Global {
	const uint Infinity = 1 << 30;
	const uint MaxNodes = 50000;
}

struct NeighbourVerticesOf {
	NeighbourVerticesOf(uint nodeIndex, uint costOfEdge)
		:	index(nodeIndex), edgeCost(costOfEdge) {}
	uint index;
	uint edgeCost;
};

int main(int argc, char * argv[]) {
	dbg << "Infinity: " << Global::Infinity << endl;
	
	const char * inFile = "dijkstra.in";
	const char * outFile = "dijkstra.out";
	
	ifstream fin(inFile);
	ofstream fout(outFile);
	
	#ifndef NDEBUG
		if(!fin || !fout) {
			cerr << "Error opening one of \"" << inFile << "\" or \"" << outFile << "\"" << endl;
			return -1;
		}
	#endif
	
	
	//	Read in the number of nodes and the number of edges
	ulong nNodes, nEdges;	
	fin >> nNodes >> nEdges;
	
	//	Allocate big enough data structures for...
	vector<uint> 	distance(nNodes+1, Global::Infinity);	//	distance[i] holds the min. distance from the source vertex to vertex i
	queue<uint>		remainingVertices;						//	queue will store the next vertices whose neighbours are going to be relaxed	
	vector<bool>	isInQueue(nNodes+1, false);				//	isInQueue[i] is true when vertex i is in the queue and false when it's not
	//	We need isInQueue because we're not gonna add all the vertices to the queue because that would be a massive overhead...
	
	//	This one is a little weird...
	//	So neighboursOf[i] is an array of "NeighbourVerticesOf" structs.
	//	"Each NeighbourVerticesOf" struct stores a neighbour of "i" and the cost of the edge connecting "i" to that neighbour
	//	This will make it really easy to access all the neighbours of a node "i" by just indexing the "neighboursOf" array
	//	and going through the linked list of neighbours
	vector<NeighbourVerticesOf> neighboursOf[nNodes+1];
		
	//	Read in the data...
	uint x1, x2, cost;
	for(ulong i = 0; i < nEdges; i++) {
		fin >> x1 >> x2 >> cost;
		//	We read a directed edge connecting x1 to x2 with a cost of 'cost'
		//	So the 'neighboursOf[x1]' list needs to be updated with this new edge and vertex
		//	Since the edge is directed (from x1 to x2 not from x2 to x1), we're not going to update
		//	'neighboursOf[x2]'
		neighboursOf[x1].push_back(NeighbourVerticesOf(x2, cost));
	}
	
	dbg << "nNodes: " << nNodes << "\nnEdges: " << nEdges << endl;
	
	//	Start Dijkstra!
	
	//	The source vertex in this problem is vertex number ONE
	uint sourceVertex = 1;
	//	Dijkstra's algorithm will set the distance from the source to the source to 0, obviously
	distance[sourceVertex] = 0;
	//	Push the source vertex into the queue
	remainingVertices.push(sourceVertex);
	isInQueue[sourceVertex] = true;
	
	while(!remainingVertices.empty()) {
		//	Pop the cheapeste vertex (the vertex that is closest to the source out of all the remaining vertices)
		uint cheapestVertex = remainingVertices.front(); remainingVertices.pop();
		//	Indicate that the vertex is not in queue anymore
		isInQueue[cheapestVertex] = false;
		
		//	Iterate through the neighbours of the cheapest vertex
		vector<NeighbourVerticesOf>::iterator neighbours = neighboursOf[cheapestVertex].begin();
		
		while(neighbours != neighboursOf[cheapestVertex].end()) {
			//	Get the current neighbour of the cheapest vertex
			NeighbourVerticesOf neighbour = (*neighbours);
			
			//	Check if the distance from this neighbour is bigger than it should be...
			if(distance[neighbour.index] > distance[cheapestVertex] + neighbour.edgeCost) {
				
				//	If that's the case update the distance
				distance[neighbour.index] = distance[cheapestVertex] + neighbour.edgeCost;
				
				//	And add the node to the queue if it's not in there already...
				if(!isInQueue[neighbour.index]) {
					isInQueue[neighbour.index] = true;
					remainingVertices.push(neighbour.index);
				}
				
			}
			
			neighbours++;
		}
	}
	
	//	Output the results...
	for(uint i = 2; i <= nNodes; i++) {
		if(distance[i] != Global::Infinity) {
			fout << distance[i] << " ";
		} else {
			fout << 0 << " ";
		}
	}
	fout << "\n";
	
	fout.close();
	fin.close();
	
	return 0;

}
