#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define pb push_back

using namespace std;

class Container {

      public:
      Container(vector<int> _arr):arr(_arr){n = arr.size();}
      void sort() {
           _stoogesort(0, n - 1);
      }; 
      void print() {
           ofstream fout(FOUT);
           for(auto v:arr) fout<<v<<" ";
      };
      private: 
      vector<int> arr;
      int n; 
      void _stoogesort(int lo, int hi) {
           if(lo>=hi) return;
           if(arr[lo] > arr[hi]) {
              int tmp = arr[lo];
                  arr[lo] = arr[hi];
                  arr[hi] = tmp;    
           } 
           if((hi - lo + 1) > 2) {
                int t = (hi - lo + 1) / 3;  
                _stoogesort(lo, hi - t); 
                _stoogesort(lo + t, hi);
                _stoogesort(lo, hi - t);
           }
      } 
};

int main() {

    vector<int> arr;
    int elem, n; 
    ifstream fin(FIN);
    fin>>n;
    for(int i = 0; i < n; ++i) fin>>elem, arr.pb(elem);
    Container container(arr);
    container.sort();
    container.print();
 return(0);
};