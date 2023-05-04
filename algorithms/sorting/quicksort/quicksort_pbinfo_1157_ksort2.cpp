#include <iostream>

using namespace std;

int n, k, arr[200005];
void quicksort(int lo, int hi, int sign) {
    
     int i,j,m;
     i = lo;
     j = hi;
     m = arr[(lo+hi)>>1];
    
     while(i<=j) {
         while(sign * arr[i] < m * sign) i++;
         while(sign * arr[j] > m * sign) j--;
         if(i<=j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
         }        
     }
    
     if(lo<j) quicksort(lo,j, sign);
     if(i<hi) quicksort(i,hi, sign);
     
}

int main() {
    
    cin>>n>>k;
    for(int i = 0; i < n; ++i) {
        cin>>arr[i];
    } 
    
    quicksort(0, k-1, 1);
    quicksort(k, n, -1);
    
    for (int i = 0 ; i < n ; i ++) cout << arr[i] << " ";
}
