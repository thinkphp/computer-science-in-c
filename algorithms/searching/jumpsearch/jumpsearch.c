#include <stdio.h>
#include <math.h>
 
//gcc jumpsearch.c -o r -lm
int main(int argc, char const *argv[]) {
  int lo, hi, key, found = 0;
  int vec[] = {55, 77, 100, 101, 103, 170, 200, 300}, //an array of ints
      n = sizeof(vec) / sizeof(vec[0]); //the length of the array
  int jump = sqrt(n);
 
  lo = 0;
  hi = jump;
  key = 170;
 
  while(key >= vec[jump] && hi < n) {
 
        lo = hi;
 
        hi += jump;
 
        if(hi > n) {
 
           hi = n;
        }
  }
 
  for(int i = lo; i < hi; i++) {
 
      if(vec[i] == key) {
 
        printf("The element %d is found at the index: %d ", key, i);
 
        found = 1;
 
      }
  }
  if(found == 0) {
 
     printf("%s", "Not Found");
  }
  return 0;
}
