#include <iostream>
#include <cstring>

typedef struct student {
  char name[100];
  float cs,
        maths,
        phisics;
} Student;

typedef void(*fnPtr)(int*, int);

void function2(void(*f)(int*, int)) {
    int arr[10], size = 10;
    f(arr, size);
}

void bubblesort(int *p, int size) {
    printf("\nbubblesort method call");
}

void insertsort(int *p, int size) {
    printf("\ninsertsort method call");
}

int main(int argc, char const *argv[]) {

  Student ob,
          *ob2,//pointer to Student
          *ob3;
  ob3 = new Student;
  strcpy(ob3->name, "State");
  ob2 = &ob;
  strcpy(ob.name, "adrian");
  ob.cs = 7.5;
  ob.maths = 10;
  ob.phisics = 8;
  printf("%s\n", ob.name);
  printf("%s\n", ob2->name);
  printf("%s", ob3->name);

  fnPtr f;
  int arr[6] = {5,4,3,2,1,0}, size = 6;
  f = insertsort;
  f(arr, size);
  function2(bubblesort);
  return 0;
}
