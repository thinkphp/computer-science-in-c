#include <stdio.h>

int V[100], n;

int getIndMin(int i, int n) {

    if(2 * i + 1 <= n) {

       if(V[ 2 * i + 1 ] < V[ 2 * i ]) return 2 * i + 1;

                    else
                                       return 2 * i;

    } else if( 2 * i <= n ) return 2 * i;

    else return i;
}

void heapify(int i, int n) {

     while( i <= n / 2) {
       
          int indMin = getIndMin(i, n);

          if(i == indMin || V[i]<V[indMin]) break;

          int aux = V[i];
          V[i] = V[indMin];
          V[indMin] = aux;

          i = indMin;

     }
}

void minHeap() {

     for(int i = n/2; i >= 1; i--) heapify(i, n);
}

void heapsort() {

     minHeap();

     for(int i = n; i >= 1; i--) {

          int aux = V[1];

          V[1] = V[i];

          V[i] = aux;

          heapify(1, i-1);
     }
}

int main(int argc, char const *argv[]) {

  scanf("%d",&n);
  for(int i = 1; i <= n; ++i) scanf("%d",&V[i]);
  heapsort();
  for(int i = 1; i <= n; ++i) printf("%d ",V[i]);

  return 0;
}
