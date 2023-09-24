/*
Utilizarea unor pointeri care reprezinta o matrice, deplasarea si accesarea elementelor, generarea de numere aleatorii, functii definite de programator.
Se cere popularea unei matrice cu elemente numere aleatorii mai mici decat 1000, matricea fiind reprezentata de un pointer care sa fie alocat( dupa citirea de la tastatura a numaratului de linii si de coloane). Sa se scrie o metoda pentru afisarea in forma patratica aliniata a matricei, dar si o forma de afisare care sa parcurga elementele pointerului liniar de la stanga la dreapta, prin folosirea operatorului de incrementare. Sa se verifice daca alocarea memoriei pentru matrice a fost realizata cu success; in caz contrar sa se scrie un mesaj corespunzator si sa se intrerupa programul.
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
 
void readMatrix(int *p, int n, int m) {
     srand((unsigned)time( NULL ));
     for(int i = 0; i < n; ++i)
       for(int j = 0; j < m; ++j)
           *(p + (i * m) + j) = (rand()* (float)1000/RAND_MAX);
}
 
void writeMatrix(int *p, int n, int m) {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j)
        printf("%5d ", *(p + (i * m) + j));
    printf("\n");
  }
}
 
void writeLinear(int *p, int n, int m) {
    for(int i = 0; i < n*m; ++i, p++)
         printf("%5d ", *(p));
}
 
int main(int argc, char const *argv[]) {
 
  int *mat;
  int n = 3,
      m = 3;
  mat = (int*)malloc((n*m)*sizeof(int));
  if(mat == NULL) {
  printf("Error!");
  } else {
    readMatrix(mat, n, m);
    printf("%s","Matrix:\n");
    writeMatrix(mat, n, m);
    printf("%s","Linear:\n");
    writeLinear(mat, n, m);
    printf("\nOk!");
    free(mat);
  }
  return 0;
}
