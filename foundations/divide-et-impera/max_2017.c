#include <stdio.h>

int max(int a, int b) {

    if(a > b) return a;else return b;
};

int dei(int arr[], int lo, int hi) {

     if(lo == hi) {

        return arr[lo]; 

     } else {

         int a = dei(arr,lo,(lo+hi)/2);  

         int b = dei(arr,(lo+hi)/2+1,hi);

         return max(a,b); 
     }

};

int main() {

  int max; 

  int arr[10] = {0,1,2,3,91,5,6,7,8,4};     

  printf("%d", dei(arr,0,9)); 
   
  return(0);
}     