#include <stdio.h>

void stoogesort(int arr[], int lo, int hi) {

     if(lo >= hi) return;

     if(arr[lo] > arr[hi]) {

        int tmp = arr[lo];

            arr[lo] = arr[hi];

            arr[hi] = tmp; 
     }  

     if(hi - lo + 1 > 2) {

        int t = (hi - lo + 1) / 3;

        stoogesort(arr, lo, hi - t);

        stoogesort(arr, lo + t, hi);

        stoogesort(arr, lo, hi - t);
     }
};

int main()
{
    int arr[] = {2, 4, 5, 3, 1};
    int i,n = sizeof(arr)/sizeof(int);
 
    // Calling Stooge Sort function to sort the array
    stoogesort(arr, 0, n-1);
 
    // Display the sorted array
    for (i=0; i<n; i++)
         printf("%d ", arr[ i ]);
 
    return 0;
}