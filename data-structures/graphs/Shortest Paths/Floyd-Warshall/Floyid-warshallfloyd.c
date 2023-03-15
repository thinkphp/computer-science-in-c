#include <stdio.h>
#define DIM 100
#define FIN "floyd.in"

const float PINF = 1.e20;
float matrixCosts[DIM][DIM];
int nodes,
    edges;

void readMatrixCost() {
     int x,y,c;
     freopen(FIN,"r",stdin);
     scanf("%d %d", &nodes,&edges);
     for(int i=1;i<=nodes;++i)
       for(int j=1;j<=nodes;++j) {
         if(i==j){
           matrixCosts[i][j]=0;
         }else {
           matrixCosts[i][j]=PINF;
         }
       }
     while(edges--) {
       scanf("%d %d %d",&x,&y,&c);
       matrixCosts[x][y] = c;
     }
}

void displayMatrixCost() {
  for(int i=1;i<=nodes;++i) {
    for(int j=1;j<=nodes;++j){
      printf("%.2f ", matrixCosts[i][j]);
    }
    printf("\n");
  }
}

void RoyFloyd() {
 for(int k=1;k<=nodes;++k) {
   for(int i=1;i<=nodes;++i) {
    for(int j=1;j<=nodes;++j) {
            if(matrixCosts[i][j] > matrixCosts[i][k] + matrixCosts[k][j]) {
               matrixCosts[i][j] = matrixCosts[i][k] + matrixCosts[k][j];
            }
        }
    }
  }
}

void road(int i, int j) {

     int k=1, found=0;
    
     
     while(k <= nodes && !found) {
                
           if(i != k && j != k && matrixCosts[ i ][ j ] == matrixCosts [i ][ k ] + matrixCosts[ k ] [ j ]) {

               printf(" --> %d", k);	         
               
               road( i, k );
               
               road( k, j );
               
               found = 1;        
               
            }   	
                     
           k++;    
     }         
}

void search(int startPoint, int endPoint) {

     if(matrixCosts[startPoint][endPoint] < PINF) {

        printf("Shortest path from the point %d to the point %d has the length = %.3f", startPoint, endPoint, matrixCosts[startPoint][endPoint]);
        
        printf("\nPath: %d", startPoint);
        
        road(startPoint, endPoint);
        
        printf(" --> %d\n", endPoint);
        
     } else {

        printf("Does not exist path!");

     }
}

int main(int argc, char const *argv[]) {

  int startPoint, endPoint;
    
  readMatrixCost();
    
  RoyFloyd();
    
  startPoint = 2;
    
  endPoint = 5;
    
  search(startPoint, endPoint);
    
  return 0;
}
