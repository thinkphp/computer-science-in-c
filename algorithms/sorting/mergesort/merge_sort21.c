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

void _mergesort(int left, int right) {

     if(left == right) return;

     else {

          int middle = (left + right) >> 1;

          _mergesort(left, middle);    

          _mergesort(middle + 1, right);

          
     int newvec[middle - left + 1],
         i,
         j,p2,q2;

     for(i = left; i <= middle; i++) newvec[i-left] = vec[i];

     j = middle - left; 

     i = 0; p2 = middle + 1; q2 = right;

     while(i<=j && p2 <= q2) {

           if(newvec[i] < vec[p2]) vec[left++] = newvec[i++];

                 else

                                   vec[left++] = vec[p2++];
     } 

     while(i<=j) vec[left++] = newvec[i++]; 

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

