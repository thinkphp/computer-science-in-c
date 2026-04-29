#include <iostream>
#include <climits>
#define FIN "graph.in"
#define FOUT "tsp.out"

using namespace std;

const int SIZE = 100;

int path[SIZE];
int matrixCosts[ SIZE ][ SIZE ];
int bestPath[SIZE];
bool used[ SIZE ];
int nodes, start_node, bestCost=INT_MAX, currentCost;

void printSol() {
	
	 cout<<"Costul minim: "<<bestCost<<"\n";
	 cout<<"Drumul optim: ";
     for(int i = 1; i <= nodes; ++i) {
     	cout<<bestPath[i]<<" ";
     }
     cout<<start_node;
}

void saveSol() {
     for(int i = 1; i <= nodes; ++i) {
     	bestPath[i] = path[i];
     } 
}


void hamilton(int k) {

	 if(k == nodes + 1) {
         
         //check for cycle
	 	 if( matrixCosts[path[nodes]][start_node] > 0 ) {

          int totalCost = currentCost + matrixCosts[path[nodes]][start_node];

          if( totalCost < bestCost ) {

          	bestCost = totalCost;

          	saveSol();
          }

         } 
          
	 } else {

	 	for(int v = 1; v <= nodes; ++v) {

           //if the node is not used and the cost from the node k-1 and v is greater than zero
           if(!used[v] && matrixCosts[ path[ k - 1] ][ v ] > 0) {

	 		int newCost = currentCost + matrixCosts[ path[ k - 1 ] ][ v ];

            //branch and bound - prune
	 		if( newCost >= bestCost ) continue;

	 		path[ k ] = v;

	 		currentCost = newCost;

	 		used[ v ] = true;

	 		hamilton(k+1);

            currentCost-=matrixCosts[path[k-1]][v]; 

	 		used[ v ] = false;
	 	  }
            

	 	} 
	 }
}


int main(int argc, char const *argv[])
{
	freopen(FIN,"r",stdin);
	//freopen(FOUT,"w",stdout);
    cin>>nodes;

    for(int i = 1; i <= nodes; ++i) {

    	for(int j = 1; j <= nodes; ++j) {

    		cin>>matrixCosts[i][j];
    	}	
    }

    start_node = 1;

    path[ 1 ] = start_node;
 
    used[ start_node ] = true;

    hamilton( 2 );    
	
    printSol();

	return 0;
}
