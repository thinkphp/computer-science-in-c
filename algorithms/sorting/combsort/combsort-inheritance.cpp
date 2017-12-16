#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Base {

      public:
      Base(int *_arr, int _n): arr(_arr),n(_n){};

      void printSorted() {
           this->sort(); 
           ofstream fout(FOUT);
           for(int i = 0; i < n; ++i) fout<<arr[ i ]<<" ";
      }  
      int getn(){return n;}
      void _swap(int a, int b) {int tmp = arr[a]; arr[a] = arr[b]; arr[b] = tmp;}   
      virtual void sort()=0; 
      protected:
      int *arr, n;
};

class BubbleSort: public Base {

};

class MergeSort: public Base {

};

class QuickSort: public Base {

};

class PancakeSort: public Base {

};

class CombSort: public Base {
      
      public:
      CombSort(int *arr, int n): Base(arr, n){};
      void sort() {
           float shrinkFactor = 1.3;
           int gap = this->getn(), swapped = 0;
           while(gap > 1 || swapped) {
                 if(gap > 1) gap = gap / shrinkFactor;
                 swapped = 0;
                 for(int i = 0; i + gap < this->getn(); ++i) 

                     if(arr[i] > arr[i+gap]) {
                        this->_swap(i, i+gap);
                        swapped = 1; 
                     }  
           }    
      } 
};

int main() {
    int n,*arr;
    ifstream fin(FIN);
    fin>>n;
    arr = new int[n+1];
    for(int i = 0; i < n; ++i) fin>>arr[ i ];
    Base *obj = new CombSort(arr, n);
          obj->printSorted();
 return(0);
};