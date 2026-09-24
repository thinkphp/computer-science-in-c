/*
Problem. Write a C program that reads an integer n and then a sequence of n integers into an array. Using a traversal pointer (not array indexing in the search loop), count how many elements are nonzero and print that count.

Input

First, an integer n: the length of the array. n must be between 1 and MAX (use MAX = 20). If n is missing, not an integer, less than 1, or greater than MAX, print an error and stop.
Then n integers, one by one. If any value is invalid, print an error and stop.
Processing

Set a pointer p to the first element of the array.
Walk the array with p from the start to one past the last element (p < a + n).
Whenever *p is not 0, increment a counter.
Do not use a[i] in this counting loop; advance the pointer (p++) and dereference it (*p).
Output

Print the number of nonzero elements.
If every element is 0, print 0.
Example
Input: n = 5, array 0 3 0 7 0
Output: 2
*/

#include <stdio.h>
#include <malloc.h>
#define MAX 20

int main( void ) {

    int *p;
    int n;
    int a[MAX];
    int count = 0;
    
    printf("%s","Enter the size N = ");

    if(scanf("%d", &n) != 1 || n > MAX || n < 0) {

       printf("Invalid size"); 

       return 1;   
    }

    for(int i = 0; i < n; ++i) {

        printf("a[%d] = ", i);

        if( scanf("%d", a + i) != 1) {

            printf("Invalid number");
            return 1;
        }
    }

    p = a;

    while(p < a + n) {
        if(*p != 0) count++;
        p++;
    }

    printf("Numar de elemente nenule este: %d", count);


      
}
