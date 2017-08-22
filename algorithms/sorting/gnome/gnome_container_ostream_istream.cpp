#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define pb push_back

using namespace std;

class Container {

      public:
      Container(){};
      void sorted() {
           _gnome();
      };
      void added(int val) {
           vec.pb(val);
      };

      friend ostream &operator<<(ostream &stream, const Container &obj) {

             vector<int> arr = obj.vec;
 
             for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) stream<<*it<<" "; 

           return stream;
      };

      friend istream &operator>>(istream &stream, Container &obj) {
                
             int elem, 
                 n;
             vector<int> arr = obj.vec;              

             stream>>n;

             obj.n = n;

             for(int i = 0; i < n; ++i) stream>>elem, obj.added(elem);

            return stream; 
      };

      private:
      vector<int> vec;
      int n;
      void _gnome() {

           int pos = 0;
           while(pos < n) {
                 if(pos == 0 || vec[pos] >= vec[pos-1]) pos++;
                    else {_swap(pos, pos-1); pos--; } 
           }
      };
      void _swap(int a, int b) {
           int tmp;
               tmp = vec[a];
               vec[a] = vec[b];
               vec[b] = tmp;
      };

};

int main() {
  
    ifstream fin(FIN);
    ofstream fout(FOUT);

    Container container; 
    fin>>container;
    container.sorted();
    fout<<container; 

 return(0);
};