#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500001

using namespace std;

class Base {

      public:
      Base(int a[],int _n):vec(a),n(_n){}      
      int getN(){return n;}
      void print() {
           ofstream fout(FOUT);
           for(int i = 0; i < n; ++i) fout<<vec[i]<<" ";
      }

      protected:
      int *vec, 
           n;
};

class Child: public Base {
      public:
      Child(int b[], int n):Base(b, n){}
      void divideEtImpera(int lo, int hi) {

           int i, j, mi, *tmp, k;

           if(lo < hi) {
              mi = (lo+hi)>>1; 
              divideEtImpera(lo, mi);
              divideEtImpera(mi+1,hi);
              i = lo; j = mi + 1; tmp = new int[hi - lo + 1]; k = 0;
              while(i <= mi && j <= hi) {
                    if(vec[i] < vec[j]) tmp[k++] = vec[i++]; else tmp[k++] = vec[j++];
              }
              while(i<=mi) tmp[k++] = vec[i++];
              while(j<=hi) tmp[k++] = vec[j++];
              k = 0;
              for(int it = lo; it <= hi; ++it) vec[it] = tmp[k++];
              delete tmp; 
           }
      }
      void run() {
           divideEtImpera(0, getN() - 1);
      }
};

int main( void ) {

    ifstream fin(FIN);
    int n, elem, arr[SIZE];
    fin>>n; 
    for(int i = 0; i < n; ++i) fin>>elem, arr[i] = elem;
    Child ob(arr, n); 
    ob.run();
    ob.print();

 return(0);
};