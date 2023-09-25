#include <stdio.h>
#include <time.h>
#include <malloc.h>

void readMatrix(int *p, int l, int c) {

  for(int i = 0; i < l; ++i) {
    for(int j = 0; j < c; ++j) {
      *(p + (i * c) + j) = rand() % 10;
    }
  }
}

void writeMatrix(int *p, int l, int c) {

  printf("Matrix:\n");
  for(int i = 0; i < l; ++i) {
    for(int j = 0; j < c; ++j) {
      printf("%5d ", *(p + (i * c) + j));
    }
    printf("\n");
  }
  printf("\n");
}

void writeLinear(int *p,int line,int col) {

     printf("\nMatrix Linear:\n");
     for(int i = 0; i < line * col; ++i, p++) {
       printf("%d ", *p);
     }
     printf("\n");
}

void multiply(int *p1, int *p2, int *p3, int l, int c) {

  /*for(int i = 0; i < l; ++i) {
    for(int j = 0; j < c; ++j) {
      *(p3 +(i*c + j)) = 0;
    }
   }
   */

   //or
   for(int i = 0; i < l*c; ++i) { *(p3+i) = 0;}

   for(int i = 0; i < l; ++i) {
     for(int j = 0; j < c; ++j) {
       for(int k = 0; k < c; ++k) {
         *(p3 +(i*c) + j) += *(p1 + (i*c) + k) * (*(p2 + (k*c) + j) );
         //printf("%d * %d \n",*(p1 + (i*c) + k), (*(p2 + (k*c) + j) ));
       }
     }
   }

}

int main(int argc, char const *argv[]) {

  int *mat, line, col,*mat2,
      *mat3;
  srand(time(NULL));
  line = 3;
  col = 3;


  mat = (int*)malloc(line*col*sizeof(int));
  mat2 = (int*)malloc(line*col*sizeof(int));
  mat3 = (int*)malloc(line*col*sizeof(int));

  readMatrix(mat, line, col);
  readMatrix(mat2, line, col);

  writeMatrix(mat, line, col);
  writeMatrix(mat2, line, col);
  writeLinear(mat, line, col);
  writeLinear(mat2, line, col);

  multiply(mat, mat2, mat3, line, col);
  writeMatrix(mat3, line, col);
  writeLinear(mat3, line, col);

  free(mat);
  free(mat2);
  free(mat3);

  return 0;
}
