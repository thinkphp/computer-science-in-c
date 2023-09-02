/*
#2. Secventa de cautat
Se citeste de la tastatura un numar natural cu cel mult 100 de cifre. Determinati
cea mai lunga secventa de cifre consecutive, pozitia de inceput a acesteia si continutul.
In cazul in care exista mai multe secvente de aceeasi dimensiuni maxima, afisati-o pe prima din sir.

Input: 4321560123456981234423
L = 7
Prima pozitie = 6
Subsirul = 0123456

*/
#include <stdio.h>

int search(char str[], int *lMax) {

    int i = 0, iCurr = 0, iMax, n = strlen2(str);

    *lMax = 1;

    while(i < n) {

      if(i - iCurr > *lMax) {

         iMax = iCurr;

         *lMax = i - iCurr;
      }

      iCurr = i;

      while(str[i] + 1 == str[i+1] && i < n) i++;

      i++;

    }

   return iMax;

}

int strlen2(char str[]) {

    int cnt = 0;

    while( str[ cnt ] != '\0' ) {

      cnt++;

    }

    return cnt;
}

typedef char TNumber[100];

int main(int argc, char const *argv[]) {

  TNumber str;

  int iMax, lMax;

  printf("Number = ");

  gets( str );

  lMax = strlen2( str );

  iMax = search(str, &lMax);

  printf("L = %d\nstart = %d\n", lMax, iMax);

  for(int i = iMax; i < iMax + lMax; ++i) printf("%c", str[ i ]);

  return 0;
}
