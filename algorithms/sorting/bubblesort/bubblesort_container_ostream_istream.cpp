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
           _bubblesort();
      };
      void added(int val) {
           vec.pb(val);
      };

      friend ostream &operator<<(ostream &stream, const Container &obj) {

             for(auto i:obj.vec) stream<<i<<" "; 
      }; 

      friend istream &operator>>(istream &stream, Container &obj) {

             int num, 
                 elem;  

             stream>>num; 

             obj.n = num;

             for(int i = 0; i < num; ++i) stream>>elem, obj.added(elem);
      }; 

      private:
      vector<int> vec;
      int n;

      void _bubblesort() {

           int t, bound = n,
               finished = 0;

           while(!finished) {

                 t = 0;

                 for(int i = 0; i < bound - 1; ++i) {

                     if( vec[ i ] > vec[ i + 1 ] ) {

                            _swap(i, i + 1);

                            t = i;
                     }
                 }

                 if( t ) bound = t + 1;

                     else 

                         finished = 1; 
           }; 
      };

      void _swap(int a, int b) {

           int tmp;

               tmp = vec[ a ];

               vec[ a ] = vec[ b ];

               vec[ b  ] = tmp;
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