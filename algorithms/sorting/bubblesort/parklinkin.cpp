#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:
      Container(int _n): n(_n){}

      void added(int val) {

           arr.push_back( val );
      }


      friend ostream &operator<<(ostream &stream,const Container &obj)  {
   
             vector<int> vec = obj.arr;

             for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {

                 stream<<(*it)<<" "; 
             }

          return stream;
      };

      void sorted() {

           for(int i = 0; i < n - 1; ++i) {

               for(int j = i + 1; j < n; ++j) {

                       if(arr[ i ] > arr[ j ]) {

                          int temp = arr[ i ] ^ arr[ j ];

                              arr[ i ] = temp ^ arr[ i ];

                              arr[ j ] = temp ^ arr[ j ];
                       }
               }
           }                         
      };


      private: 
      int n;
      vector<int> arr;  
};

int main() {

    int n, 
        elem;

    ifstream fin(FIN);
    ofstream fout(FOUT);

    fin>>n; 

    Container container(n);

    for(int i = 0; i < n; ++i) fin>>elem, container.added(elem);

    container.sorted();

    fout<<container;

 return(0);
};

