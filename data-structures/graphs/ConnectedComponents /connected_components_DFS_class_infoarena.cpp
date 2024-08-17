#include <iostream>
#include <fstream>
#include <vector>
//#define FIN "dfs.in"
//#define FOUT "dfs.out"

typedef unsigned long ulong;

class ConnectedComponents {

      public:

      	     //constructor of the class
      	     ConnectedComponents(std::vector<std::vector<ulong>* >& adjacencyList, ulong nVertices, ulong nEdges) 
      	                                           : adjList(adjacencyList), 
      	                                             numVertices(nVertices), 
      	                                             numEdges(nEdges),
      	                                             count(0) 
      	          {

      	               isVisited.resize(numVertices + 1, false);  

      	          }

      	     void execute() {

                  for(ulong node = 1; node <= numVertices; ++node) {

                          if(!isVisited[ node ]) {
                                 
                                 dfs(node);

                          	     count++;
                          }

                  } 
      	     } 


      	     void dfs(ulong node) {
 
                  if( !isVisited[node] ) {

                       isVisited[ node ] = true;

                       if( adjList[node] ) {

                       	   for(ulong i = 0; i < adjList[node]->size(); ++i ) {

                               dfs((*adjList[node])[i] );
                           }                          	   
                       }
                  } 

      	     }

      	     ulong getCount() const {

                   return count; 
      	     }            

      private: 
      	     ulong numVertices;
      	     ulong numEdges;
      	     std::vector<std::vector<ulong>* >& adjList;
      	     ulong count;
      	     std::vector<bool> isVisited;  
};

int main(int argc, char const *argv[])
{

    const char *inFile = "dfs.in";  
    const char *outFile = "dfs.out";

    std::ifstream fin(inFile);
    std::ofstream fout(outFile);

    if(!fin || !fout) {

    	std::cerr<<"Error opening one of \""<<inFile<<"\" or \""<<outFile<<"\""<<"\n";

    	return -1;
    }   

    ulong n, 
          m, 
          x, 
          y;

          fin>>n>>m;

          std::vector<std::vector<ulong>* > adjList;

          adjList.resize(n + 1, NULL);

          for(ulong i = 1; i <= m; ++i) {

          	  fin>>x>>y;

              if(adjList[x] == NULL) {
              	 adjList[x] = new std::vector<ulong>();
              }

              if(adjList[y] == NULL) {
              	 adjList[y] = new std::vector<ulong>();
              }

              adjList[x]->push_back(y);
              adjList[y]->push_back(x);
          }
                    	
 
    ConnectedComponents connex(adjList, n, m);          
                        connex.execute();
                        std::cout<<connex.getCount();
                        fout<<connex.getCount();
                        std::cout<<"\n";


    //clean up

    for(ulong i = 0; i < adjList.size(); ++i) {

    	if(adjList[i] != NULL) delete adjList[i]; 
    }                        

    fin.close();

    fout.close();

	return 0;
}
