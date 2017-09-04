#include <stdio.h>
#define BSEARCH_NOT_FOUND

int bsearch_iterative(int arr[], int size, int key) {

    int lo, hi, middle;

    lo = 0;

    hi = size - 1;

    while( lo <= hi ) {

          middle = (lo + hi)>>1;

          if(key < arr[ middle ]) hi = middle - 1;

             else if(key > arr[ middle ] ) lo = middle + 1;

             else return middle;    
    } 

    return -1; 
};

void BinarySearchTest() {

    int arr[] = {1,3,5,7,9,13,15,17};

    printf("Your number was found in position %d. Should be 0\n", bsearch_iterative(arr, sizeof(arr)/sizeof(int), 1));
    printf("Your number was found in position %d. Should be 1\n", bsearch_iterative(arr, sizeof(arr)/sizeof(int), 3));
    printf("Your number was found in position %d. Should be 2\n", bsearch_iterative(arr, sizeof(arr)/sizeof(int), 5));
    printf("Your number was found in position %d. Should be 3\n", bsearch_iterative(arr, sizeof(arr)/sizeof(int), 7));
    printf("Your number was found in position %d. Should be 4\n", bsearch_iterative(arr, sizeof(arr)/sizeof(int), 9));
    printf("Your number was found in position %d. Should be 5\n", bsearch_iterative(arr, sizeof(arr)/sizeof(int), 13));
    printf("Your number was found in position %d. Should be 6\n", bsearch_iterative(arr, sizeof(arr)/sizeof(int), 15));
    printf("Your number was found in position %d. Should be 7\n", bsearch_iterative(arr, sizeof(arr)/sizeof(int), 17));

    printf("Your number was found in position %d. Should be -1\n", bsearch_iterative(arr, sizeof(arr)/sizeof(int), 117));

};

int main() {

    BinarySearchTest();

 return(0);
};