#include <stdio.h>
#define SIZE 100

int n, V[ SIZE ];

int getIndMin( int i, int n ) {

    int right = 2 * i + 1,
        left = 2 * i;

    if( right <= n ) {
        if( V[ right ]  <  V[ left ]) return right;
                  else
                                      return left;
    } else if(left <= n) return left;

    else return i;
}

void heapify(int i, int n) {

    while( i <= n/2 ) {

         int indMin = getIndMin(i, n);

         if(i == indMin || V[i] < V[indMin]) break;

         int aux = V[i];
         V[i] = V[indMin];
         V[indMin] = aux;

         i = indMin;
    }
}

void minHeap() {

    for(int i = n / 2; i >= 1; i--) heapify(i, n);
}

void heapsort() {
     //transformi vectorul in minHEAP
     minHeap();//V[1] contine cea mai mica valoare

     for(int i = n; i >= 1; i--) {

          int aux = V[1];
          V[1] = V[i];
          V[i] = aux;
          heapify(1, i - 1);
     }
}

int main(int argc, char const *argv[]) {

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", &V[i]);
  heapsort();
  for(int i = 1; i <= n; ++i) printf("%d ", V[i]);

  return 0;
}

/*
   Breadth First Search = metoda de traversare a grafului
   cautare in latime.
   BFS pentru orice graf.

   Graful este o cale abstracta de a reprezenta conectivitatea folosind
   noduri si muchii.

   DFS (stiva pe recursie)
   BFS ( coada )

   Cum reprezinti in memorie un graf:

   - matrice de adiacenta.
   - liste de adiacenta.
   - lista de muchii(arce).

- sort(edges, cost)

   Arborele partial de cost minim - MST
   input: graf neorientat cu pondere cu greutate, cost.

   struct muchie {
     int a, b, cost;
   }

   Ciclu hamiltornian - matrice de adiacenta

   Shortest Path => reprezentare graf prin liste de adiacenta

   vector<muchie>


            1

        7       8

    10    9   11   18

21    22

V = [1, 7, 8, 10, 9, 11, 18, 21, 22]

V = [22, 7, 8, 10, 9, 11, 18, 21, 1]

      V[1] = cea mai mica valoare din vector

      V[ultima pozitie] =V[1]

               22

        7             8


  10      9      11      18

21

MinHeap = V[1] trebuie sa fie cea mai mica valoare


                  8

          7             11


      10      9      22     18

21

V = [8,7,11,10,9,22,18,21] => V = [21,7,11,10,9,22,18,8,1]

Complexitate O(n log n)

MinHeap si MaxHeap

MaxHeap => V[1] cea mai mare valoare si V[i] mai mare decat left si right

*/
