#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:

      Container(vector<int> vec, int _n): n(_n),arr(vec){};

      void print() {

            for(int i = 0; i < n; ++i) cout<<arr[i]<<" ";
      }; 

      void sorted() {

           int i, j;

           for(i = 0; i < n - 1; ++i) {

               for(j = 0; j < n - 1 - i; ++j) {

                   if(arr[j] > arr[j+1]) {

                      _swap(j, j+1);
                   } 
               }
           }
      };

      friend ostream &operator<<(ostream &stream, const Container &obj) {

             vector<int> vec = obj.arr;

             for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)

             stream<<(*it)<<" "; 
      };

      private: 
      vector<int> arr;
      int n; 

      void _swap(int i, int j) {

           int cxor;
               cxor = arr[i]^arr[j];   
               arr[i] = cxor^arr[i];
               arr[j] = cxor^arr[j];
      };
};

int main() {

 int elem, 
     n;
 vector<int> arr;

 ifstream fin(FIN);
 ofstream fout(FOUT);

 fin>>n; 

 for(int i = 0; i < n; ++i) fin>>elem, arr.push_back(elem);

 Container container(arr, n); 

 container.sorted();
 
 fout<<container;
  
 return(0); 
};	