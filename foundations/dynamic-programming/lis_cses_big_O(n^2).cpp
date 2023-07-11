/*
 * Description     : Longest Increasing Subsequence for CSES Problem Set
 * Time Complexity: O(n^2) using Dynamic Programming Technique.
 * input: n = 8, v = [2,1,3,2,4,8,6,7]
 * Output: 5
 *         2,3,4,6
 *         L = 5 5 4 4 3 1 2 1 5
 */
#include <bits/stdc++.h>
#define SIZE 200002

using namespace std;

int v[ SIZE ], n, Lmax,
    L[ SIZE ];

void dynamic_programming() {

     int max;

     L[n-1] = 1;

     for(int i = n-2; i >= 0; i--) {

        max = 0;

        for(int j = i + 1; j < n; j++) {

              if(L[j] > max && v[i] < v[j]) {

                 max = L[j];
              }

              L[i] = 1 + max;

              if(Lmax < L[i]) Lmax = L[i];
        }
     }

}


int main(int argc, char const *argv[]) {

  cin>>n;
  
  for(int i = 0; i < n; ++i) cin>>v[i];

  dynamic_programming();

  if(n!=1) cout<<Lmax<<endl;
  
  else 
         cout<<"1";

  return 0;
}
