#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:
      Container(vector<int> _arr, int _n):vec(_arr), n(_n){}
 
      void added(int val) {

           vec.push_back( val );
      };     

      void sorted() {

           int finished = 0,
               swapped,
               last = n,
               i; 

           while( !finished ) {

                 swapped = 0;

                 for(i = 0; i < last - 1; ++i) {

                      if(vec[ i ] > vec[ i + 1 ]) {

                         int tmp = vec[ i ];
                         vec[ i ] = vec[i + 1];
                         vec[ i + 1 ] = tmp;

                         swapped = 1;
                       }
                 }

                 if( swapped ) last--;
                    
                     else 
                               finished = 1;
           }
      };

      void print() {

           ofstream fout(FOUT);
           for(int i = 0; i < n; ++i) fout<<vec[i]<<" ";
      };

      friend ostream &operator<<(ostream &stream, Container &obj) {

             vector<int> arr;
             arr = obj.vec; 
  
             for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {

                 stream<<*it<<" ";  
             }

         return stream;
      };

      private:
      vector<int> vec;
      int n;  
};

int main() {

    int elem, 
        n;

    vector<int> vec;

    ifstream fin(FIN);

    ofstream fout(FOUT);

    fin>>n;

    for(int i = 0; i < n; ++i) fin>>elem, vec.push_back(elem);      
     
    Container container(vec, n);
    container.sorted();  
    fout<<container;
 
    //container.print();

    return(0);
};