/*Continuous knapsack Problem
(fractional knapsack problem)
---------------------------
Given a set of items, each with a weight and a value,
determine a subset of items to include in a collection so that the total weight
is less than or equal to a given limit and the  total value is as large as possible.
 
Se considera un rucsac de capacitate M si N obiecte, ale
caror greutate si valoare sunt date. Sa se gaseasca
o modalitate de a introduce cat mai multe obiecte in rucsac,
astfel incat valoarea globala sa fie maxima. Se considera ca
obiectele poti fi fractionate. Presupunem ca datele de intrare
sunt corecte si valorile obiectelor sunt strict pozitive. Pe prima
linie a fisierului de intrare obiecte.in se gaseste
capacitatea rucsacului. Numarul maxim de obiecte este 50.
 
obiecte.in
41
12.34 123.99
23.45 600.54
12.78 90.67
9.34 45.32
 
rucsac.out
In rucsac vor fi introduse obiecte:
Obiectul 2 23.45 600.54 - complet
Obiectul 1 12.34 123.99 - complet
Obiectul 3: 12.34 123.99 - 5.2 kg (fractionar)
*/
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
 
typedef bool (*comparer)(const void *a, const void *b);
 
typedef struct {
  float weight,
        value;
  int index;
} Object;
 
void read(Object *ob, int *n, float *capacity){
 
     float w,v;
     scanf("%f", capacity);
     while(scanf("%f",&w) == 1) {
         scanf("%f", &v);
         ob[(*n)].weight = w;
         ob[(*n)].value = v;
         ob[(*n)].index = (*n);
         (*n)++;
     }
}
 
void bubblesort(Object *ob, int n, comparer comp) {
 
      bool finished = false;
 
        while(!finished) {
            bool swapped = false;
 
            for(int i = 0; i < n - 1; ++i) {
 
                if( comp(&ob[i], &ob[i+1])) {
                    Object temp = ob[i];
                           ob[i] = ob[i+1];
                           ob[i+1] = temp;
                           swapped = true;
                }
            }
            if(!swapped) {
              n--;
            } else {
              finished = true;
            }
        }
}
 
bool descending(const void *a, const void *b) {
 
     Object *o1 = (Object*)a;
     Object *o2 = (Object*)b;
 
     return o2->value/o2->weight - o1->value/o1->weight > 0;
}
 
int main(int argc, char const *argv[]) {
 
  int count = 0;
 
  float capacity;
 
  Object arr[100];
 
  read(arr, &count, &capacity);
 
  printf("%d %f\n", count, capacity);
 
  bubblesort( arr, count, descending );
 
  int i = 0;
 
  while(capacity>0) {
 
    if(arr[i].weight < capacity) {
 
      capacity -= arr[i].weight;
 
      i++;
 
    } else {
 
      capacity = -capacity;
    }
  }
 
  printf("%f\n", capacity);
 
  for(int j = 0; j < i; j++) {
 
      printf("%d: %.4f %.4f completed object\n", arr[j].index,arr[j].weight, arr[j].value);
  }
 
  if(capacity<0) {
 
     printf("%d: %.4f %.4f fractional object %f\n", arr[i].index,arr[i].weight, arr[i].value, capacity);
  }
 
  return 0;
}
