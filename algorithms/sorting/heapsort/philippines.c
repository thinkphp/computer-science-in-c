#include <stdio.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500070

//global variables
int Heap[SIZE],
    size = 0;

void up(int child) {
      int parent;
      parent = child / 2;

      while(parent!=0) {
           if(Heap[parent]>=Heap[child]){
              int temp = Heap[parent];
              Heap[parent] = Heap[child];
              Heap[child] = temp;
              child = parent;
              parent = child / 2;
           } else {
             break;
           }
      }
}

void down(int parent) {
      int child;
      while(2 * parent <= size) {

            child = 2 * parent;
            if (2 * parent + 1 <= size && Heap[2 * parent + 1] < Heap[2 * parent]) {
                child++;
            }
            if(Heap[parent]<=Heap[child]) break;
            int temp = Heap[parent];
            Heap[parent] = Heap[child];
            Heap[child] = temp;
            parent = child;
      }
}

void insert(int value) {

     size +=1;
     Heap[size] = value;
     up(size);
}

int removes() {
    int min = Heap[1];
        Heap[1] = Heap[size];
        size--;
        down(1);
        return min;
}

int main(int argc, char const *argv[]) {
  int n, x;
  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
      scanf("%d", &x);
      insert(x);
  }
  for(int i = 0; i < n; ++i) {

      printf("%d ", removes());
  }

  return 0;
}
