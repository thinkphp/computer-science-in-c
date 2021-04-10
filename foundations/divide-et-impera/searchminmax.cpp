#include <iostream>
using namespace std;

int divideEtConquer(int vec[], int left, int right) {
    int m;
    if(left == right) {
               return vec[ left ];
    } else {
         int a, b;
         m = (left + right)>>1;
         a = divideEtConquer(vec, left, m);
         b = divideEtConquer(vec, m + 1, right);
         if(a < b) return a;
               else
                   return b;
    }
}

int main(int argc, char const *argv[]) {

    int vec[] = {44,22,99,100,101,-19,17,0,1,2,3},
    n = sizeof(vec)/sizeof(vec[0]),
    max;
    max = divideEtConquer(vec, 0, n - 1);
    cout<<max;

  return 0;
}
