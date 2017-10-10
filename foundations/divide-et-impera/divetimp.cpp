#include <iostream>

using namespace std;

void quicksort(int *arr,int lo,int hi) {

     int i = lo,
         j = hi,
         piv = arr[(lo+hi)>>1];

         while(i <= j) {

               while(arr[i]<piv) i++;
               while(arr[j]>piv) j--;

               if(i<=j) {
                  int tmp;
                      tmp = arr[i];
                      arr[i] = arr[j];
                      arr[j] = tmp;  
               }
               i++;
               j--;
         } 

               if(lo < j) quicksort(arr, lo, j);
               if(i < hi) quicksort(arr, i, hi);

};

void hanoi(int n, char a, char b, char c) {

     if(n == 1) cout<<a<<b<<" ";
     else {
          hanoi(n-1, a, c, b);
          cout<<a<<b<<" ";
          hanoi(n-1, c, b, a);
     }
}

void mergesort(int *arr, int lo, int hi) {

     int i, j, k = 0, mi, *tmp;

     if(lo < hi) {

        mi = (lo+hi)>>1;
        mergesort(arr, lo, mi);
        mergesort(arr, mi + 1, hi);

        tmp = new int(hi - lo + 1);
        i = lo; j = mi + 1; 

        while(i <= mi && j <= hi) {
              if(arr[i] < arr[j]) tmp[k++] = arr[i++];
                        else      tmp[k++] = arr[j++];
        }

        while(i <= mi) tmp[k++] = arr[i++];
        while(j <= hi) tmp[k++] = arr[j++];

        k = 0;

        for(int i = lo; i <= hi; i++) arr[i] = tmp[k++]; 
        delete tmp; 
     }  
};

int main( void ) {

    int arr[] = {9,8,7,6,5,4,3,2,1,0}, 
        n = sizeof(arr)/sizeof(arr[0]);
     
    for(int i = 0; i < n; ++i) cout<<arr[i]<<" "; 

    cout<<endl;
 
    mergesort(arr, 0, n - 1);

    for(int i = 0; i < n; ++i) cout<<arr[i]<<" "; 

    char a = 'a',b = 'b', c = 'c';

    hanoi(5, a, b, c);

 return(0);   
}; 