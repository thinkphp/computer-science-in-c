#include <stdio.h>
#include <assert.h>
#define LSEARCH_NOT_FOUND -1

int LinearSearch(int arr[], int size, int key) {

    int i;

    for(i = 0; i < size; ++i) {

        if(arr[i] == key) return i;
    }

    return LSEARCH_NOT_FOUND;
};

void LinearSearchTest() {

     int a[] = {1,3,5,7,9};
     int a_size = sizeof(a)/sizeof(int);
     //or a_size = sizeof(a)/sizeof(a[0]);

     int empty[] = {};
     int empty_size = sizeof(a)/sizeof(int);   

     assert(LinearSearch(a, a_size, 1) == 0);    
     assert(LinearSearch(a, a_size, 5) == 2);
     assert(LinearSearch(a, a_size, 8) == -1);
     assert(LinearSearch(empty, empty_size, 8) == -1);


     printf("Should return 0 = %d\n", LinearSearch(a, a_size, 1));    
     printf("Should return 2 = %d\n", LinearSearch(a, a_size, 5));
     printf("Should return -1 = %d\n", LinearSearch(a, a_size, 8));
     printf("Should return -1 = %d\n", LinearSearch(empty, empty_size, 8));

         
};

int main() {

 LinearSearchTest();

 return(0);
};