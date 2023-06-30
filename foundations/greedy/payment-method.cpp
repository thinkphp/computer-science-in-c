
#include <bits/stdc++.h>
/*
 * Payment method Problem
 *
 * Se considera n (n<=1000) tipuri de bancnote, de valori diferite,
 * din fiecare existand un numar nelimitat de bucati.  Sa se determine
 * o modalitate de plata, a valorii S, folosind un numar minim de bancnote.

 #
 # We consider N (N<=1000) types of banknotes, of different values,
 # of each there being an unlimited number of pieces. Determine a payment
 # method of payment, of value S using a minimum numbers of banknotes.
 #
 # Input:
 # N = 5
 # S = 100
 #         3,15,1,5,2
 #
 # Output: 6 * 15
 #         2 * 5
 */
int B[ 1001 ],
    N,
    S;

void load() {
   scanf("%d %d", &N,&S);
   for(int i = 0; i < N; ++i) scanf("%d", &B[i]);
}

void sort(int sign) {

     int aux,j;

     for(int i = 1; i < N; ++i) {

         j = i - 1;
         aux = B[i];

         while(j>=0 && B[j]*sign>aux*sign) {
           B[j+1] = B[j];
           j--;
         }
         B[j+1] = aux;
     }
}

void solve() {

     sort(-1);
     int sum;
     for(int i = 0; i < N; ++i) {
         if(S>=B[i]) printf("%d * %d\n", S/B[i],B[i]);
         S -= (S / B[i]) * B[i];
         if(!S) break;
     }
     if( S > 0 )printf("No Solution!");
}

int main(int argc, char const *argv[]) {

  load();
  solve();

  return 0;
}
