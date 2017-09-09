#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:
      Container(int _n):n(_n){}
      void added(int val) {
           vec.pb(val); 
      } 
      void sorted() {
           __stoogesort(0, n - 1);
      };
      friend ostream &operator<<(ostream &stream, const Container &obj) {

             vector<int> arr = obj.vec;

             for(auto v: arr) stream<<v<<" ";

             return stream;
      };
      private:
      vector<int> vec;
      int n;

      void __stoogesort(int lo, int hi) {

           if(lo>hi) return;
           if(vec[lo] > vec[hi]) _swap(lo, hi);
           if((hi - lo + 1) > 2) {
               int t = (hi - lo + 1)/3;
                   __stoogesort(lo, hi - t);
                   __stoogesort(lo + t, hi); 
                   __stoogesort(lo, hi - t);
           }
      };
      void _swap(int lo,int hi) {
           int tmp;
           tmp = vec[lo];
           vec[lo] = vec[hi];  
           vec[hi] = tmp; 
      }
};

int main() {

    int elem, n;
    ifstream fin(FIN);
    ofstream fout(FOUT); 

    fin>>n;
    Container container(n);
    for(int i = 0; i < n; ++i) fin>>elem, container.added(elem);
    container.sorted();
    fout<<container;

 return(0);
};