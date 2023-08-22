#include <iostream>
#include <cstring>

#define FIN "students.in"
#define FOUT "students.out"

typedef struct {
     char name[100];
     float CS,
           Maths,
           Biology;
    int ID;
} Student;

typedef bool(*Compare)(const void*,const void*);

bool descendBiology(const void* a, const void *b) {
     Student* ob1 = (Student*)a;
     Student* ob2 = (Student*)b;
     return (ob2->Biology - ob1->Biology) > 0;
}

bool descendMaths(const void* a, const void *b) {
     Student* ob1 = (Student*)a;
     Student* ob2 = (Student*)b;
     return (ob2->Maths - ob1->Maths) > 0;
}

bool descendCS(const void* a, const void *b) {
     Student* ob1 = (Student*)a;
     Student* ob2 = (Student*)b;
     return (ob2->CS - ob1->CS) > 0;
}


void bubblesort(Student *ob, int size, Compare cmp) {

     int finished = 0,
         swapped;

         while(!finished) {
           swapped = 0;
           for (size_t i = 0; i < size - 1; i++) {
                if(cmp(&ob[i], &ob[i+1])) {
                  Student temp = ob[i];
                  ob[i] = ob[i+1];
                  ob[i+1] = temp;
                  swapped = 1;
                }
           }

           if(swapped) size--;
           else
               finished = 1;
        }

}

void readData(Student *ob, int *size) {

     char name[100];
     float cs, maths, bio;

     while(scanf && scanf("%s", name) == 1) {
           scanf("%f %f %f", &cs, &maths, &bio);
           //printf("%s %.2f %.2f %.2f\n", name, cs, maths, bio);
           ob[(*size)].ID = (*size)+1;
           strcpy(ob[(*size)].name, name);
           ob[(*size)].CS = cs;
           ob[(*size)].Maths = maths;
           ob[(*size)].Biology = bio;
           (*size)++;
     }
}

int main(int argc, char const *argv[]) {

  //the number of the students
  int size = 0;
  //define an array of Students
  Student arr[100];

  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);

  readData(arr, &size);

  printf("\nThe number of the Students = %d\n\n", size);

  for(int i = 0; i < size; ++i) printf("%d. %s %.2f %.2f %.2f\n", arr[i].ID, arr[i].name, arr[i].CS, arr[i].Maths, arr[i].Biology);

  bubblesort(arr, size, descendMaths);

  printf("\n");

  for(int i = 0; i < size; ++i) printf("%d. %s %.2f %.2f %.2f\n", arr[i].ID, arr[i].name, arr[i].CS, arr[i].Maths, arr[i].Biology);

  return 0;
}
