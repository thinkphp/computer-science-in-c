#include <stdio.h>

void swap(void *a, void *b, size_t dim) {
     char* x = (char*)a;
     char* y = (char*)b;
     char aux;
     //printf("bytes = %ld\n", dim);
     for(int i = 0; i < (int)dim; ++i) {
           aux = *(x+i);
           *(x+i) = *(y+i);
           *(y+i) = aux;
     }
}
/*
0000 00001
 /\   /\
 ||   ||
 \/   ||
\/    \/
0000 00010
*/
void bubblesort(int *p, int count) {

     int finished = 0;

     while( !finished ) {

       int swapped = 0;

       for (size_t i = 0; i < count - 1; i++) {

            if( *( p + i ) > *(p + i + 1 )) {

              swap(p + i, p + i + 1, sizeof(int));

              swapped = 1;
            }
       }
       if(swapped) count--;else finished =1;
     }
}

int main(int argc, char const *argv[]) {

  long int a,
           b;
  int arr[] = {5,4,3,2,1},size = sizeof(arr)/sizeof(arr[1]);

  printf("a = ");
  scanf("%ld", &a);
  printf("b = ");
  scanf("%ld", &b);
  swap(&a,&b,sizeof(long int));
  printf("a = %ld\n", a);
  printf("b = %ld\n", b);
  for (size_t i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  bubblesort(arr,size);
  printf("\n");
  for (size_t i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
