/**
 *  @author      Adrian Statescu <mergesortv@gmail.com>
 *  @description Merge Sort in Action.
 *  @License     MIT 
 */

#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int vec[ MAXN ],
    N;

void read() {

     int i;
 
     freopen(FIN, "r", stdin);

     scanf("%d", &N); 

     for(i = 0; i < N; i++) scanf("%d ", &vec[ i ]);

     fclose( stdin );      
};    

void _merge(int p1, int q1, int p2, int q2) {

     int newvec[q1 - p1 + 1],
         i,
         j;

     for(i = p1; i <= q1; i++) newvec[i-p1] = vec[i];

     j = q1 - p1; 

     i = 0;

     while(i<=j && p2 <= q2) {

           if(newvec[i] < vec[p2]) vec[p1++] = newvec[i++];

                 else

                                   vec[p1++] = vec[p2++];
     } 

     while(i<=j) vec[p1++] = newvec[i++]; 

};

void _mergesort(int left, int right) {

     if(left == right) return;

     else {

          int middle = (left + right) >> 1;

          _mergesort(left, middle);    

          _mergesort(middle + 1, right);

          _merge(left, middle, middle+1,right);
     }
};

void sort() {

     _mergesort(0, N - 1); 
}; 

void write() {

     int i;
 
     freopen(FOUT, "w", stdout);

     scanf("%d", &N); 

     for(i = 0; i < N; i++) printf("%d ", vec[ i ]);

     fclose( stdout );      
};

int main() {

    read();
    sort();
    write();               
 
    return(0);         
};

