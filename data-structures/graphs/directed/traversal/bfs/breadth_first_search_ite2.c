/**
 *  Breadth First Search - Non-Recursive Approach
 */
#include <stdio.h>
#include <memory.h>
#define FIN "graph_matrix.in"

int mat[100][100],i,j,nodes;

void bfs(int node) {

     int queue[100], 
         visited[100],//an array to hold the visited vertices
         front,//pointer to front queue
         rear;//pointer to rear queue

     front = rear = 0; 
     queue[ front ] = node; //push start node into the queue
 
     memset(visited,0,sizeof(visited)); 

     //marked as visited
     visited[ node ] = 1; 

     int i,j;

     while(front <= rear) {
              
           int nod = queue[front++];         

           //for each neibours non visited do
           for(j = 0; j < nodes; j++) {

               if(!visited[ j ] && 1 == mat[nod][j]) {

                   rear++; 

                   queue[rear] =  j;  

                   visited[ j ] = 1;
               }
           }  
     }     
 
     for(j = 0; j < nodes; j++) printf("%d ",queue[j]+1);    
}

int main() {

 freopen(FIN, "r",stdin);

 scanf("%d", &nodes);

 for(i = 0; i < nodes; i++) {

     for(j = 0; j < nodes; j++) {

         scanf("%d", &mat[i][j]);
     } 
 }

 bfs(0); 

 return(0);
}