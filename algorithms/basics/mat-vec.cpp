/*
In fisierul matrice.in se afla un tablou bidimensioonal cu compontente intregi. Pe prima linie se afla doua valori reprezentand numarul 
de linii, respectiv numarul de coloane, separate printr-un spatiu, iar pe urmatoarele linii componentele tabloului. Se cere sa se obtina
un tablou format din exact din aceleasi elemente ca si matricea data dar elementele fiecarei linii si coloane sa fie in ordine crescatoare. Tabloul obtinut sa se scrie in fisierul matrice.out.
*/
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {

  int mat[100][100],
      n,m;
  cout<<"N=?, M=?";
  cin>>n>>m;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin>>mat[i][j];
    }
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }

  int vec[n*m+1];

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
        vec[i*m+j]= mat[i][j];
    }
    cout<<endl;
  }

  int finished = 0, swapped, size = n * m;

  while(!finished) {
    swapped = 0;
    for(int i = 0; i < size - 1; i++) {
        if(vec[i]>vec[i+1]) {
          swapped = 1;
          int aux = vec[i];
          vec[i] = vec[i+1];
          vec[i+1] = aux;
        }
    }

    if(swapped) size--;else finished = 1;
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
        mat[i][j] = vec[i * m + j];
    }
  }

  cout<<"Sorted Matrix="<<endl;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
