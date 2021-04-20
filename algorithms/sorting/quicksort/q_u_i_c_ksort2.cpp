#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using  namespace std;

vector<int> vec;

void _swap(int i, int j) {

     int aux = vec[ i ];
         vec[ i ] = vec[ j ];
         vec[ j ] = aux;
}

void quicksort(int lo, int hi) {

     int pivot = vec[ (lo + hi) >> 1],
          i = lo,
          j = hi;

          while(i <= j) {
                 while(vec[i] < pivot) i++;
                 while(vec[j] > pivot) j--;
                 if(i<=j) {_swap(i, j); i++; j--;}
          }

          if(lo < j) quicksort(lo, j);
          if(i < hi) quicksort(i, hi);

}

int main(int argc, char const *argv[]) {

  int N,
       num;

  ifstream fin(FIN);
  ofstream fout(FOUT);

  fin>>N;
  for(int i = 0; i < N; i++) {

      fin>>num;
      vec.push_back(num);
  }

  quicksort(0, N - 1);

  for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {

      fout<<(*it)<<" ";
  }

  return(0);
}
