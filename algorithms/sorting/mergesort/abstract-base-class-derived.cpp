#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Base {

      protected:
      int *arr, 
           n;

      public:
      Base(int *vec, int _n):arr(vec),n(_n){}
      void run() {
           this->sort();
      } 
      void printarray(){

           ofstream fout(FOUT); 
           this->run();
           for(int i = 0; i < n; ++i) fout<<arr[i]<<" ";
      }
 
      int getnum(){return n;} 
      virtual void sort()=0;       
};

class bubblesort: public Base {

      public:
      bubblesort(int *arr, int n): Base(arr, n){}
      void sort() {
           int finished = 0, i, 
               swapped, last = n - 1;
           while(!finished) {
                  swapped = 0;
                  for(i = 0; i < last - 1; ++i) {
                      if(arr[i] > arr[i+1]) {
                         int tmp = arr[i];
                             arr[i] = arr[i+1];
                             arr[i+1] = tmp;
                             swapped = 1;
                      }
                  }
                  if(swapped) last--;
                     else finished = 1;  
           }           
      } 
};


class mergesort: public Base {

      public:
      mergesort(int *arr, int n): Base(arr, n){}

      void _mergesort(int lo, int hi) {
           int i, j, mi, *tmp, k;
           if(lo < hi) {

              mi = (lo+hi)>>1;
              _mergesort(lo, mi);   
              _mergesort(mi+1, hi);

              i = lo; j = mi+1;tmp = new int[hi - lo + 1];
              k = 0; 
              while(i <= mi && j <= hi) {
                    if(arr[i] <= arr[j]) tmp[k++] = arr[i++];
                            else         tmp[k++] = arr[j++];
              } 

              while(i <= mi) tmp[k++] = arr[i++];
              while(j <= hi) tmp[k++] = arr[j++];

              k = 0;
              for(int p = lo; p <= hi; ++p) arr[p] = tmp[k++];
              delete tmp; 
           } 
      }; 

      void sort() {
           this->_mergesort(0, n - 1);
      } 
};


int main() {
    int *arr, n;
    ifstream fin(FIN);
    fin>>n;
    arr = new int[n+1];
    for(int i = 0; i < n; ++i) fin>>arr[i];
    Base *ptr = new mergesort(arr, n);
          ptr->printarray();
 return(0);
};