#include <iostream>
#define FIN "graph.in"
#define FOUT "cycles.out"

const int N = 50;
int n;

int path[N];

bool used[N];

int matrix[N][N];    

int start_node;

void print_solution() {

	for(int i = 1; i <= n; ++i) std::cout<<path[i]<<" ";  

         std::cout<<start_node;	
         std::cout<<std::endl;	

}

void hamilton(int k) {

     if( k == n + 1 ) {

         if(matrix[start_node][path[k-1]] == 1) {

                  print_solution();
         }
         

     } else {

         for(int v = 1; v <= n; ++v) {

             if(!used[v] && matrix[path[k-1]][v]) {

             	path[ k ] = v;
             	used[v] = true;
             	hamilton(k + 1);
             	used[v] = false;
             }   

         }  
     }
}

int main(int argc, char const *argv[])
{

	freopen(FIN,"r",stdin);
	//freopen(FOUT,"w",stdout);
 
    std::cin>>n>>start_node;

    path[1] = start_node;

    for(int i = 1; i <= n; ++i) used[i] = false;

    used[start_node] = true;

    for(int i = 1; i <= n; ++i) {
    	for(int j = 1; j <= n; ++j) {
    		std::cin>>matrix[i][j];
    	}
    }
    

	hamilton(2);
	
	return 0;
}