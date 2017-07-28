#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:

      Container(vector<int> vec, int _n): n(_n),arr(vec){};

      void sorted() {

           int gaps, dist, i, j, k, aux; 

           for(gaps = n / 2; gaps > 0; gaps/=2) {

               dist = gaps;

               for(i = dist; i < n; ++i) {

                   aux = arr[ i ] ;

                   for(j = i - dist; j >= 0 && arr[j] > aux; j-=dist) {
                    
                       arr[ j + dist] = arr[ j ];
                   }

                       arr[ j + dist] = aux;
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