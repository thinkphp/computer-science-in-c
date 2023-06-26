/*
*/
#include <stdio.h>
#include <math.h>

int arr[] = {0,14,23,2,1,4,21},

    n = sizeof(arr)/sizeof(arr[0])-1;

void swap(int *i, int *j) {
     int temp = *i;
         *i = *j;
         *j = temp;
}

int part(int lo, int hi) {

    int piv = arr[hi],
        j = lo - 1,
        i;
        for(i = lo; i <= hi; i++)
          if(arr[i]<=piv) {
            ++j;
            swap(arr+j,arr+i);
          }
    return j;
}

int sel(int k, int lo, int hi) {
    int x = part(lo, hi);
    if(k == x) return arr[k];
    if(k > x) return sel(k, x+1, hi);
    else return sel(k, lo, x-1);
}

int main(int argc, char const *argv[]) {

  for(int i = 1; i <= n; ++i) printf("%d ", arr[i]);
  
  int k = 4;

  printf("\n%d\n",sel(k, 1, n));

  for(int i = 1; i <= n; ++i) printf("%d ", arr[i]);

  return 0;
}
