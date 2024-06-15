#include <iostream>
#define DIM 100

//vector = {'a','b','c','1','2','3'}
//          1   2  3    4    5   6
//

int n, stack[ DIM ],

       folosit [ DIM ];

void print_permutation() {

       for(int i = 1; i <= n; ++i) printf("%d ", stack[i]);

       printf("\n");
}

void genereazaPermutari(int level) {

          if(level > n) {

             print_permutation();

          } else {

                   for(int i = 1; i <= n; ++i) {

                            //2 este folosit? NU
                          if( !folosit[ i ] ) {

                            stack[ level ] = i;//stack[1] = 1; stack[2] = 2; stack[3] = 3

                            folosit[ i ] = 1;//1 este marcat ca fiind folosit, marcam 2 ca fiind folsoit; marchez 3 folosit

                            genereazaPermutari(level + 1); //trecem la nivelul urmator

                            folosit[ i ] = 0; //demarcam i ca sa-l putem folosit,
                          }
                   }
          }
}


int main(int argc, char const *argv[]) {

  n = 3;

  genereazaPermutari( 1 );

  return 0;
}
