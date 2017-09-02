#include <stdio.h>

#define BINARY_SEARCH_NOT_FOUND -1

typedef int TypeArray;

int binary_search(TypeArray arr[], TypeArray key, int first, int last) {

    if(first > last) return BINARY_SEARCH_NOT_FOUND;

    int middleIndex = (first+last)>>1;

    TypeArray middleValue = arr[ middleIndex ];

        if( key < middleValue)  {

            return binary_search(arr, key, first, middleIndex - 1);
        }

        else if(key > middleValue) { 

            return binary_search(arr, key, middleIndex + 1, last);

        }

        else return middleIndex+1;
};

void BinarySearchTest() {

    int containingMiddle[] = {1,2,3,4,5,6,7,8,9}; 
    int emptyArray[] = {};

    printf("Should be 1: %d\n", binary_search(containingMiddle, 1, 0, sizeof(containingMiddle)/ sizeof(TypeArray) - 1));
    printf("Should be 2: %d\n", binary_search(containingMiddle, 2, 0, sizeof(containingMiddle)/ sizeof(TypeArray) - 1));
    printf("Should be 3: %d\n", binary_search(containingMiddle, 3, 0, sizeof(containingMiddle)/ sizeof(TypeArray) - 1));
    printf("Should be 4: %d\n", binary_search(containingMiddle, 4, 0, sizeof(containingMiddle)/ sizeof(TypeArray) - 1));
    printf("Should be 5: %d\n", binary_search(containingMiddle, 5, 0, sizeof(containingMiddle)/ sizeof(TypeArray) - 1));
    printf("Should be 6: %d\n", binary_search(containingMiddle, 6, 0, sizeof(containingMiddle)/ sizeof(TypeArray) - 1));
    printf("Should be 7: %d\n", binary_search(containingMiddle, 7, 0, sizeof(containingMiddle)/ sizeof(TypeArray) - 1));
    printf("Should be 8: %d\n", binary_search(containingMiddle, 8, 0, sizeof(containingMiddle)/ sizeof(TypeArray) - 1));
    printf("Should be 9: %d\n", binary_search(containingMiddle, 9, 0, sizeof(containingMiddle)/ sizeof(TypeArray) - 1));

    printf("Should be -1: %d\n", binary_search(containingMiddle, 19, 0, sizeof(containingMiddle)/ sizeof(TypeArray) - 1));
    printf("Should be -1: %d\n", binary_search(emptyArray, 2, 0, sizeof(emptyArray)/ sizeof(TypeArray) - 1));


}

int main() {

    BinarySearchTest();
 
 return(0);
}