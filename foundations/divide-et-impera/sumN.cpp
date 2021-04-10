#include <iostream>

using namespace std;

int divideEtImpera(int arr[], int lo, int hi) {

     int m;

     if(lo == hi) {

        return arr[ lo ];

     }  else {

        int x, y;
        m = (lo + hi) >> 1;
        x = divideEtImpera(arr, lo, m);
        y = divideEtImpera(arr, m + 1, hi);
        if(x < y) return x + y;
              else
                  return y + x;

     }
}

void comb(int x, int y, int &z) {
     z = x + y;
}
void sumN(int arr[], int left, int right, int &z) {
      int x1, x2;
      if(left == right) {
         z = arr[left];
      } else {
        int m = (left + right) >> 1;
        sumN(arr, left, m, x1);
        sumN(arr, m + 1, right, x2);
        comb(x1,x2,z);
      }

};

int main(int argc, char const *argv[]) {

  int arr[] = {1,2,3,4,5,6,7,8,9,10},
      sum,
      n = sizeof(arr)/sizeof(arr[0]),
      z;

  cout<<"Sum 1 + 2 + 3 +...+ 10 = ";
  sum = divideEtImpera(arr, 0, n - 1);
  cout<<sum;
  cout<<endl;
  cout<<"Sum 1 + 2 + 3 +...+ 10 = ";
  sumN(arr, 0, n - 1, z);
  cout<<z;
  return 0;
