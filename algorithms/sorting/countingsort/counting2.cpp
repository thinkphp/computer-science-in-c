#include <iostream>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
 
  int arr[] = {5,90,23,3,2,-1},
      n = sizeof(arr) / sizeof(arr[0]),
      B[n+1]={0},
      C[n+1]={0};
 
      for(int i = 0; i < n; ++i) {
          C[i] = arr[i];
      }
 
      for(int i = 0; i < n - 1; ++i) {
          for(int j = i + 1; j < n; ++j) {
              if(arr[j] < arr[i]) {
                B[i]++;
              } else {
                B[j]++;
              }
          }
      }
 
      for(int i = 0; i < n; ++i) arr[B[i]] = C[i];
 
      cout<<"\n";
      for(int i = 0; i < n; ++i) {
          cout<<arr[i]<<" ";
      }
 
      cout<<"\n";
 
  return 0;
}
 
