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

void qsort(int lo, int hi) {

    int piv = vec[ (lo + hi) >> 1 ],
        i = lo,
        j = hi;

    while(i <= j) {

          while(vec[ i ] < piv) i++; 

          while(vec[ j ] > piv) j--;

          if(i <= j) {

             swap(i, j);

             i++;

             j--; 
          }
    }

    if(lo < j) qsort(lo, j);

    if(i < hi) qsort(i, hi); 
};

void sort() {

     qsort(0, N - 1);
};

void read() {

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
};

void write() {

    freopen(FOUT, "w", stdout);

    for(int i = 0; i < N; ++i) printf("%d ", vec[ i ]);

    fclose( stdout );   
};

int main() {

    read(); 
    sort(); 
    write();

    return(0);
};