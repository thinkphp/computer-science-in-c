/*
Author:
Adrian Statescu
 
Description:
Counting Sorting Algorithm
 
References:
https://w...content-available-to-author-only...s.eu/algorithms/counting-sort/#Counting_Sort_Algorithm_-_Phase_2_Counting_the_Elements
*/
#include <iostream>
 
using namespace std;
 
int FindMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
       if(arr[i] > max) {
         max = arr[i];
       }
    }
    return max;
}
 
int FindMin(int arr[], int n) {
 
  int min = arr[0];
 
  for(int i = 1; i < n; i++) {
 
     if(arr[i] < min) {
 
       min = arr[i];
     }
  }
  return min;
}
 
int main(int argc, char const *argv[]) {
 
  int arr[] = {9,8,7,6,5,-4,3,-2,1,0,-4,-5,-4,-1,-8,-19,-19,8},
 
      n = sizeof(arr) / sizeof(arr[0]);
 
  for(int i = 0; i < n; ++i) cout<<arr[i]<<" ";
 
  //firstly we computes the boundaries: lower and upper boands
  int min = FindMin(arr,n),
      max = FindMax(arr,n);
 
  int counts[max - min + 1] = {0};
 
  cout<<"\n";
 
  for(int i = 0; i < n; ++i) {
      counts[arr[i]-min]++;
  }
 
  int pos = 0;
 
  for(int i = 0; i < max - min + 1; i++) {
 
       for(int j = 0; j < counts[i]; ++j) {
 
           arr[pos++] = i + min;
       }
  }
 
  for(int i = 0; i < n; ++i) cout<<arr[i]<<" ";
 
  return 0;
}
