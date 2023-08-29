#include <iostream>

/*
 Greedy Review
 Se dau o multime A cu m numere intregi nenule si o multime B cu n>=m numere intregi
 nenule. Se cere sa se selecteze un sir cu m elemente din B, x1,x2,...xn such as expresia
 urmatoare sa fie maxima:
 E = a1x1 + a2x2+...anbn
 unde a1, a2, ... an sunt elementele multimii A intr-o anumita ordine pe care trebuie
 s-o determinati.

*/
int A[100],B[100],m,n,i,
    E = 0;

void sort(int *p, int size) {
     int finished = 0;
     while(!finished) {
        int swapped = 0;
        for(int i = 1; i <= size - 1; i++) {
          if(p[i]>p[i+1]){
            int aux = p[i];p[i] = p[i+1];p[i+1] = aux;
            swapped = 1;
          }
        }
        if(swapped) size--;else finished = 1;
     }
}

int main(int argc, char const *argv[]) {

   std::cout<<"m=";
   std::cin>>m;
   for(i = 1; i <= m; ++i) std::cin>>A[i];
   std::cout<<"n=";
   std::cin>>n;
   for(i = 1; i <= n; ++i) std::cin>>B[i];
   sort(A,m);
   sort(B,n);
   for(i = 1; i <= m; ++i) E += A[i]*B[n-m+1];
   std::cout<<"Emax = "<<E;
  return 0;
}
