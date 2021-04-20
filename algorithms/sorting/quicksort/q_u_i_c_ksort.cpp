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

     int i = lo,
         j = hi,
         m,
         pivot;

          m = (i + j) >> 1;
          pivot = vec[m];
          while(i <= j) {
                 while(vec[i] < pivot) i++;
                 while(vec[j] > pivot) j--;
                 if(i<=j) {_swap(i, j); i++; j--;}
          }

          if(lo < j) quicksort(lo, j);
          if(i < hi) quicksort(i, hi);
}

int main(int argc, char const *argv[]) {

  string n,
         str1;
  int N;

  ifstream fin(FIN);
  ofstream fout(FOUT);

  getline(fin, n);
  N = stoi(n);

  string str2;
  getline(fin, str2);

  int i = 0,
      num;

  for(int k = 0; k < N; k++) {

    num = 0;

    while(str2[i] != ' ' && str2[i] != '\0') {

      num = num * 10 + str2[i] - '0';

      i++;
    }

    vec.push_back(num);
    i++;
  }

  quicksort(0, N - 1);

  for(vector<int>::iterator it = vec.begin(); it!= vec.end(); it++) {

      fout<<(*it)<<" ";
  }
  return(0);
}
