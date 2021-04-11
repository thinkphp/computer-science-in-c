#include <iostream>

using namespace std;

void divideEtImpera(int arr[], int left, int right, int &min, int &max) {

     int x, y, a, b;

     if(left == right) {

        min = max = arr[ left ];

     } else {

        int m = (left + right) >> 1;
        divideEtImpera(arr, left, m, x, a);
        divideEtImpera(arr, m + 1, right, y, b);
         if(x < y) { min = x;}
              else { min = y;}
         if(a > b) {max = a;}
              else {max = b;}

     }

}

int main(int argc, char const *argv[]) {

  int arr[] = {20,2021,44,-41,3,7,8,9,10},

      n = sizeof( arr )/sizeof( arr[0] ),

      min, max;

   divideEtImpera(arr, 0, n-1, min, max);

   cout<<"Min = "<<min<<endl<<"Max = "<<max;

  return 0;
}
