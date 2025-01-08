/*
malloc, realloc, free
*/
#include <stdio.h>
#include <malloc.h>

struct person {

       int age;
};

int sum(int a, int b) {
    return a + b;
}

int main(int argc, char const *argv[]) {

  struct person p; //variabila de tip struct person
  struct person *ptr;//pointer catre struct person

  int i[3] = {42,1337,815};
  //          0   1    2

  i[0] = 42; *(i+0) = 42;
  i[1] = 1337; *(i+1) = 1337;

  printf("%d",*(i+0));
  printf("%d\n",i[0]);
  printf("\n-------\n");
  printf("%d\n",*(i+1));
  printf("%d",i[1]);

  printf("\n-------\n");
  //p.age = 10;
  //ptr->age;

  //tip ptr
  int *arr = NULL; //declaram un pointer catre integer
  //int 4 bytes
  int initial_size,
      new_size;

  //alocam spatiu in HEAP
  printf("Introduceti numar initial de elemente:");
  scanf("%d",&initial_size);
  //initial_size = 101;
  //int arr = [1,2,3,4,5,6,7,...,100]
  //           4 bytes, 4 bytes, 4 bytes, 4bytes......
  //
  //int este pe 4 bytes
  //rezervare memorie in HEAP pentru 100 * 4bytes
  arr = (int*)malloc( initial_size * sizeof( int ) );//intoarce void*

  if(arr == NULL) {
       printf("Memory allocation failed!");
       return 1;
  }

  printf("\nint este pe %ld bytes\n",sizeof(int));
  printf("\nfloat este pe %ld bytes\n",sizeof(float));
  printf("\ndouble este pe %ld bytes\n",sizeof(double));
  printf("\nchar este pe %ld bytes\n",sizeof(char));

  //sum(2,2);//apelezi functia care este implementata

  int sum = 0;
  for(int i = 0; i < initial_size; ++i) {
       printf("arr[%d]=",i);
       scanf("%d", &arr[i]);
       sum += arr[i];
  }

  printf("Suma currenta = %d\n", sum);

  //realloc
  printf("\nIntroduceti elementele aditionale: ");
  scanf("%d",&new_size);

  arr = (int*)realloc(arr, (initial_size + new_size) * sizeof(int));//si realloc intoarce void*

  if(arr == NULL) {
       printf("Memory REAllocation failed!");
       return 1;
  }

  printf("Enter %d more elements: \n", new_size);
  for(int i = initial_size; i < (initial_size + new_size); ++i) {
    printf("arr[%d]=",i);
    scanf("%d", &arr[i]);
    sum += arr[i];
  }

   printf("All elements in array: ");

   for(int i = 0; i < (initial_size + new_size); ++i) {
       printf("%d ",arr[i]);
   }

   printf("Final sum: %d",sum);

   //free(arr);

   //arr=NULL;

   for(int i = 0; i < (initial_size + new_size); ++i) {
       printf("%d ",arr[i]);
   }


  return 0;
}
