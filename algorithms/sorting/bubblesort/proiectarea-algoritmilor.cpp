#include <iostream>

int main(int argc, char const *argv[]) {

  int a[5] = {1,2,3,4,-5},

  n = sizeof(a)/sizeof(a[0]),

  n1,

  size = n;

  for(int i = 0; i < n; ++i) printf("%d ", a[i]);

  printf("\n");

  while( size ) {

      n1 = size - 1;

      size = 0;

      printf("\n[%d]\n", n1);

      for( int i = 0; i <= n1; ++i ) {

               if(a[i]>a[i+1]) {
                 
                 int tmp = a[i];
                 a[i] = a[i+1];
                 a[i+1] = tmp;
                 
                 size = i;
                 
               }
      }
  }

  printf("n=%d\n", n);

  for(int i = 0; i < n; ++i) printf("%d ", a[i]);

  return 0;
}
