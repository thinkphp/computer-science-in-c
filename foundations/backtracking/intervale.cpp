#include <iostream>
/*
Se considera n intervale

(2, 5.5)
(6.7, 10)
(3, 6)

Output:
(2, 5.5)
(3, 6)
(6.7, 10)
(2, 5.5) (6.7, 10)
(3, 6) (6.7, 10)
*/

struct interval {
    float li,
          ls;
} v[100];

int stack[100], n;

void write(int k) {

     for(int i = 1; i <= k; ++i) {

         printf("(%.2f ", v[ stack[i] ].li);

         printf("%.2f)", v[ stack[i]].ls);
     }

     printf("\n");
}

void back( int k ) {
      int i;

      if(k <= n)
        for(i = stack[k-1]+1; i <= n; ++i)
               if(v[i].li > v[ stack[k-1] ].ls) {
                   stack[ k ] = i;
                   write( k );
                   back(k+1);
               }
               return;

}

void sort() {

     int size = n, finished = 0, swapped;
     while(!finished) {
         swapped = 0;
         for(int i = 1; i <= size - 1; ++i) {
           if(v[i].li > v[i+1].li) {
              interval aux = v[i];
              v[i] = v[i+1];
              v[i+1] = aux;
              swapped = 1;
           }
         }

         if(swapped) size--;
         else finished = 1;
     }
}

int main(int argc, char const *argv[]) {

  int i;

  //citim numarul de intervale
  scanf("%d", &n);
  for(int i = 1; i <=n; ++i) {
      scanf("%f%f", &v[i].li, &v[i].ls);
  }
  sort();
/*
  for(int i = 1; i <=n; ++i) {

      printf("%.2f %.2f\n", v[i].li, v[i].ls);

  }
  */

  stack[0] = 0;
  back(1);

  return 0;
}
