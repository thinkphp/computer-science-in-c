#include <iostream>

using namespace std;

void checkOrder(int arr[], int n) {

     int i;
     i = 1;
     while(i < n && arr[i] == arr[0]) i++;


     if(i == n) cout<<"Sir Constant.";
     else if(i < n) {

          if(arr[i] > arr[i-1]) {

            int order = 1;

            for(int j = i; j < n; j++) {
              if(arr[j]<arr[j-1]) {
                order = 0;
              }
            }

            if(order == 1) cout<<"Sir Ordonat Strict Crescator.";
                    else
                           cout<<"Sir Unordered.";

          } else if(arr[i] < arr[i-1]) {

            int order = 1;

            for(int j = i; j < n; j++) {
              if(arr[j] > arr[j-1]) {
                order = 0;
              }
            }

            if(order == 1) cout<<"Sir Ordonat Strict Descrescator.";
                    else
                           cout<<"Sir Unordered.";

          }


     }

}

int main(int argc, char const *argv[]) {

  int arr[] = {-11,7,6,5,4,3,2,1,0,-10}, n = sizeof(arr) / sizeof(arr[0]);

  checkOrder(arr, n);

  return 0;
}
