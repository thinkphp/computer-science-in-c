#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define push push_back

typedef unsigned int uint;

    std::vector<uint> vec; 
    uint N;

      void _s(int x, int y) {

           int aux;

               aux = vec[ x ] ^ vec[ y ];

               vec[ x ] = aux ^ vec[ x ];

               vec[ y ] = aux ^ vec[ y ]; 
      };

      void qsort(int low, int high) {

           int i = low,

               j = high,

               piv = vec[ (low + high) >> 1 ];

               while(i <= j) {

                     while(vec[ i ] < piv) i++;

                     while(vec[ j ] > piv) j--;

                     if( i <= j ) {_s(i, j); i++; j--;}
               }

               if(low < j) qsort(low, j); 

               if(i < high) qsort(i, high);
      };

char str[5500000];

int main() {

    freopen(FIN, "r", stdin);

    scanf("%d\n",&N); 

    gets( str );

    str[strlen(str)] = ' ';

    int j = 0;

    for(int i = 0; i < N; i++) {

        int num = 0;
         
        while(str[ j ] != ' ') {

              num = num * 10 + str[ j ] - '0';

              j++;
        }

        vec.push(num);

        j++;
    }  

    fclose( stdin );

    qsort(0, N - 1);

    std::ofstream fout( FOUT );

    for(std::vector<uint>::iterator it = vec.begin(); it != vec.end(); ++it) fout<<*it<<" "; 

    fout.close();
 
  return(0); 
};