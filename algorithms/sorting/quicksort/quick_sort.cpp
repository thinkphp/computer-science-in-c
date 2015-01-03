/**
 *  @author      Adrian Statescu <mergesortv@gmail.com>
 *  @description Quick Sort in Action.
 *  @License     MIT 
 */
#include <stdio.h>
#include <string.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005
#define MAXSTR 5500000

int  vec[ MAXN ],
     N;
char str[ MAXSTR ];

void swap(int x, int y) {

     int res;
 
         res = vec[ x ] ^ vec[ y ];

         vec[ x ] = res ^ vec[ x ];     

         vec[ y ] = res ^ vec[ y ];
};

int getpivot(int lo, int hi) {

    int piv = vec[ (lo + hi) >> 1 ];

    while(lo <= hi) {

          while(vec[ lo ] < piv) lo++; 

          while(vec[ hi ] > piv) hi--;

          if(lo <= hi) {

             swap(lo,hi);

             lo++;

             hi--; 
          }
    }

    return lo; 
};

void qsort(int lo, int hi) {

     if(lo < hi) {

        int p;

            p = getpivot(lo, hi);

                qsort(lo, p - 1);

                qsort(p, hi);
     }   
};

void sort() {

     qsort(0, N - 1);
};

int main() {

    freopen(FIN, "r", stdin);

    scanf("%d\n", &N);

    gets(str);

    fclose( stdin );

    str[ strlen( str ) ] = ' ';

    int j = 0;  

    for(int i = 0; i < N; ++i) {

        int num = 0;

        while(str[ j ] != ' ') {
          
              num = num * 10 + str[ j++ ] - '0';
        } 

        j++;

        vec[ i ] = num; 
    } 

    sort(); 

    freopen(FOUT, "w", stdout);

    for(int i = 0; i < N; ++i) printf("%d ", vec[ i ]);

    fclose( stdout );
   
    return(0); 
};