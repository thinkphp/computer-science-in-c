#include <bits/stdc++.h>

using namespace std;

int arr[] = {14,4,5,21,1,33,23},

    n = sizeof( arr )/sizeof( arr[ 0 ] );

int partition(int lo, int hi) {

    int j = lo - 1;
    int pivot = arr[hi];
    for(int i = lo; i <= hi; ++i) {
        if(arr[i]<=pivot) {
          j++;
          int temp = arr[j];
          arr[j]=arr[i];
          arr[i] = temp;
        }
    }

    return j;
}

void quicksort(int lo, int hi) {
     int piv = partition(lo, hi);
     if(lo<piv-1) quicksort(lo, piv-1);
     if(piv+1<hi) quicksort(piv+1,hi);
}

int select(int kmin, int lo, int hi) {

    int pivot = partition(lo, hi);

    if(pivot == kmin-1) {

       return arr[pivot];

    } else if(kmin-1 > pivot)

      return select(kmin,pivot+1,hi);

      return select(kmin, lo, pivot-1);


}

int main(int argc, char const *argv[]) {

  for(int i = 0; i < n; ++i) cout<<arr[i]<<" ";

  cout<<endl;

  quicksort(0, n-1);

  for(int i = 0; i < n; ++i) cout<<arr[i]<<" ";

  cout<<"\n"<<select(5, 0, n - 1);

  return 0;
}
