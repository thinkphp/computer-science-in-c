/*
calloc versus malloc

*/
#include <stdio.h>
#include <malloc.h>

int sum(int a, int b) {
    return a + b;
}

int main(int argc, char const *argv[]) {

  //tip ptr
  int *arr = NULL; //declaram un pointer catre integer
  //int 4 bytes
  int size,
      sum = 0;

  printf("Enter the number of elements: ");
  scanf("%d",&size);

  //calloc initializeaza toate elemente cu 0
  //malloc nu face initializarea
  arr = (int*)calloc(size, sizeof(int));

  if(arr == NULL) {
    printf("Memory allocation failed!");
    return 1;
  }

  for(int i = 0; i < size; ++i) {
      printf("%d ", arr[i]);
  }

  printf("Enter the elements: %d", size);
  for(int i = 0; i < size; ++i) {
      printf("arr[%d]=",i);
      scanf("%d", &arr[i]);
      sum += arr[i];
  }

  for(int i = 0; i < size; ++i) {
      printf("%d ", arr[i]);
  }

  printf("\nSum of element = %d\n", sum);

  return 0;
}
