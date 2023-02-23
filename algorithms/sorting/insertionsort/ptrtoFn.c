#include <stdio.h>
#include <malloc.h>
#define fin "algsort.in"

typedef int (*ptr2)(const int a,const int b);
typedef void (*ptr1)(int*, int, ptr2);


int comp(int a, int b) {

      return a > b;
}

void insertSort(int *p, int n, ptr2 cmp) {

     int i, j, temp;

     for(i = 1; i < n; i++) {

         temp = p[i];

         j = i - 1;

         while( j >= 0 && comp(p[ j ], temp) ) {

           p[j+1] = p[j];

           j--;

         }

         p[j+1] = temp;
     }
}

int* read(int*p, int *n) {

     freopen(fin, "r", stdin);

     scanf("%d", n);

     p = (int*)malloc(sizeof(int) * (*n));

     int i = 0;

     int size = *n;

     while(size--) {

          scanf("%d", p + i);
          i++;
     }
     return p;
}
void display(int *p, int n) {

     for(int i = 0; i < n; ++i) {

         printf("%d ", *(p+i));
     }
}

int main(int argc, char const *argv[]) {

  int *arr, n;

  arr = read(arr, &n);

  ptr1 sort = insertSort;

  sort(arr, n, comp);

  display(arr, n);

  free( arr );
  
  return 0;
}
