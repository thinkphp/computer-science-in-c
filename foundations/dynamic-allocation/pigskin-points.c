/**
 *  Determines if exists or not pigskins in a given matrix.
 */
#include <stdio.h>
#include <malloc.h>

int** readMatrix(int,int);
void printMatrix(int, int, int**);
void solve(int,int,int**);

FILE *fout;

int main() {

    int n, m;
    int **p; 

    fout  = fopen("points.out","w");

    printf("Number of lines n=");
    scanf("%d",&n);
    printf("Number of cols m=");
    scanf("%d",&m);

    p = readMatrix(n,m); 

    printMatrix(n,m,p);

    solve(n,m,p);

    return (0);
}

int** readMatrix(int n,int m) {

    int i,j;
    int **mat;

    //declare a matrix in Heap and then you can use as previously
    mat = malloc( sizeof( n ) );

    for(j = 0; j < m; j++) {

        mat[j] = malloc( sizeof( m ) ); 
    }
 
    for(i = 0; i < n; i++) {

        for(j = 0; j < m; j++) {

            printf("mat[%d][%d]=",i,j);

            scanf("%d",&mat[i][j]);
        }
    }    

    return mat;
}

void printMatrix(int n,int m, int **p) {

    int i,j;

    for(i=0;i<n;i++) {

        for(j=0;j<m;j++) {
 
            printf("%5d ",p[i][j]);
        }

        printf("\n");       
    }
}

void solve(int n,int m,int** mat) {

     int i,

         j,

         k,

         okay = 1, 

         count = 0;

     for(i = 0; i < n; i++) {

         for(j = 0; j < m; j++) {

                 okay = 1;

                 for(k = 0; k < n; k++) 
        
                     if( mat[ i ][ k ] < mat[ i ][ j ] ) okay = 0;

                 for(k = 0; k < m; k++)

                     if( mat[ k ][ j ] > mat[ i ][ j ] ) okay = 0;

            if( okay == 1 ) {

                  fprintf(fout,"mat[%d][%d] is pigskin point \n", i+1, j+1);
                  printf("mat[%d][%d] is pigskin point \n", i+1, j+1);
                 
                  count++; 
            } 

         }
     }


     for(i = 0; i < n; i++) {

        for(j = 0; j < m; j++) {

            fprintf(fout,"%5d ",mat[i][j]);
        }

        fprintf(fout,"\n");  
     }


     if( count ) { 

         printf("Number of pointes pigskins is %d", count);

         fprintf(fout,"Number of pointes pigskins is %d", count);
     }
            else  {

                  printf("We do not have pigskins points in matrix");
                   
                  fprintf(fout,"We do not have pigskins points in matrix");
            }



     fclose(fout);
}

