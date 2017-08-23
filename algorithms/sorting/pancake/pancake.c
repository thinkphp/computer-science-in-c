/**
 * Given an unsorted array, sort the given array. You are allowed to do only following operation on array:
 * flip(arr, index) -> reverse array from 0 to index.
 * Unlike a traditional sorting algorithm, which attempts to sort with the fewest comparisons possible, the goal
 * of this algorithm is to sort the sequence in as few reversals as possible. We one by one place maximum element at the end
 * and reduce the size of the current array by one.
 
 * 1. Find the index of the largest element in unsorted arr[0...size-1]. Let the index be indexMax
 * 2. Call flip(arr, indexMax)
 * 3. Call flip(arr, size - 1);
 */
#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005

int arr[ SIZE ],

    n ;

void read() {
     int i;
     freopen(FIN, "r", stdin);
     scanf("%d", &n);
     for(i = 0; i < n; ++i) scanf("%d", &arr[i]);
};

int findMax( int n ) {

    int i,

        idxMax = 0;

    for(i = 1; i < n; ++i) {

        if(arr[ i ] > arr[ idxMax ] ) idxMax = i;
    }   
    return idxMax;
};

void flip(int index) {
 
     int start = 0;

     while(start < index) {

           int tmp = arr[start];

               arr[start++] = arr[index];

               arr[index--] = tmp;

     }  
};

void pancake() {

     int curr,
         size = n, 
         iMax;

     for(curr = size; curr > 1; --curr) {

         //find index of the maximum element from unsorted array
         iMax = findMax( curr );

         if(iMax != (curr - 1)) {

            flip( iMax );

            flip( curr - 1 );  
         }
     }
};

void write() {

     int i;
     freopen(FOUT, "w", stdout);
     for(i = 0; i < n; ++i) printf("%d ", arr[i]);
};

int main() {
 read();
 pancake();
 write();

 return(0);
};