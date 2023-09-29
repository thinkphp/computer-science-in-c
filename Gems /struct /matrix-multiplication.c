#include <stdio.h>
#define DIM 100

typedef struct {
        int n, m;
        int M[DIM][DIM];
} Matrix;

int multiply(Matrix A, Matrix B, Matrix *C) {

    if(A.n - B.m) return 0;

     for(int i = 0; i < A.n; ++i) {

       for(int j = 0; j < B.m; ++j) {

           C->M[ i ][ j ] = 0;
       }
     }

     C->n = A.n;
     C->m = B.m;

     for(int i = 0; i < A.n; ++i) {

       for(int j = 0; j < B.m; ++j) {

         for(int k = 0; k < A.n; ++k) {

           C->M[i][j] += A.M[i][k] * B.M[k][j];
         }
       }
     }

     printf("Matrix Multiplication:\n");
     return 1;
}

void read(Matrix *mat) {
     int n, m;
     printf("Lines = ");
     scanf("%d", &n);
     mat->n = n;
     printf("Cols = ");
     scanf("%d", &m);
     mat->m = m;
     for(int i = 0; i < n; ++i) {
       for(int j = 0; j < m; ++j) {
         printf("mat[%d][%d]=",i,j);
         scanf("%d", &mat->M[i][j]);
       }
     }

}

void display(Matrix mat) {

     for(int i = 0; i < mat.n; ++i) {
       for(int j = 0; j < mat.m; ++j) {
         printf("%d ",mat.M[i][j]);
       }
       printf("\n");
     }
}


int main(int argc, char const *argv[]) {

  Matrix A, B, C;
  read(&A);
  display(A);
  read(&B);
  display(B);

  if( multiply(A,B,&C) == 1)

      display(C);

  else printf("No Multiplication!");

  return 0;
}
