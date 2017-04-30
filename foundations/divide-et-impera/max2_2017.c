#include <stdio.h>

int max2(int a, int b) {

    if(a > b) return a;else return b;
};

int dei(int arr[], int lo, int hi,int* max) {

     if(lo == hi) {

        return arr[lo]; 

     } else {

         int a = dei(arr,lo,(lo+hi)/2,max);  

         int b = dei(arr,(lo+hi)/2+1,hi,max);

         *max = max2(a,b);
     }

};

int main() {

  int max; 

  int arr[10] = {0,1,2,3,91,5,6,7,8,4};     

  dei(arr,0,9,&max);
  
  printf("%d", max); 
   
  return(0);
}     