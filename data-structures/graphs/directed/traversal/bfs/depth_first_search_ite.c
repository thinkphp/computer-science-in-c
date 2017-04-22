/**
 *  Depth First Search - Non-Recursive Approach
 */
#include <stdio.h>
#include <memory.h>
#define FIN "graph_matrix.in"

int mat[100][100],i,j,n;

void dfs(int n, int i) {

     int vis[ 100 ], 
         stack[ 100 ], ps, 
         j, node,
         found;

     memset(vis, 0, sizeof(vis));

     //pointer stack
     ps = 0;

     //first item in stack 
     stack[ ps ] = i;

     //node i is visited
     vis[ i ] = 1;

     printf("%d ", i+1);
                      
     while( ps >= 0 ) {

            node = stack[ ps ];

            found = 0;

            for( j = 0; j < n && !found; j++ ) {

                  if(mat[node][j] == 1 && !vis[j]) found = 1;  
            }

            if( found ) {

                printf("%d ", j); 

                vis[j-1] = 1;

                stack[++ps] = j-1;  

            } else ps--;
            
     }   

}

int main() {

 freopen(FIN, "r",stdin);

 scanf("%d", &n);

 for(i = 0; i < n; i++) {

     for(j = 0; j < n; j++) {

         scanf("%d", &mat[i][j]);
     } 
 }

 dfs(n,0); 

 return(0);
}