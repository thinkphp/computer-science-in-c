#include <stdio.h>

typedef struct {
  int n;//the cardinal of the set
  int set[100];
} TSet;

void read(TSet *p) {
   printf("number of elements N = ");
   scanf("%d",&p->n);
   for(int i = 0; i < p->n; ++i) scanf("%d",&p->set[i]);
}

int belongTo(TSet p, int elem){
  int is = 0;
  for(int i = 0; i < p.n && !is; ++i) {
    if(elem == p.set[i]) {
      is = 1;
    }
  }
  return is;
}

void display(TSet p) {
  for(int i = 0; i < p.n-1; ++i) printf("%d, ",p.set[i]);
  printf("%d",p.set[p.n-1]);
  printf("\n");
}

int main(int argc, char const *argv[]) {
  TSet A, B,//first and second sets
       I, //intersection
       D, //difference
       R; //union
  I.n = 0;
  D.n = 0;

  //read the first set
  read(&A);
  //read the second set
  read(&B);

  printf("Set A:\n");
  display(A);
  printf("Set B:\n");
  display(B);
  R = B;

  for(int i = 0; i < A.n;++i) {
     if(belongTo(B, A.set[i])==1) {
        I.set[I.n++] = A.set[i];
     } else {
       D.set[D.n++] = A.set[i];
       R.set[R.n++] = A.set[i];
     }
  }
  printf("Intersection:\n");
  display(I);
  printf("Difference:\n");
  display(D);
  printf("Union:\n");
  display(R);
  return 0;
}
