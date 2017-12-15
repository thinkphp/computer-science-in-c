#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:
      Container(int _n):n(_n){};

      void added(int val) {

           arr.push_back( val ); 
      };

      void sorted() {

           _combsort_in_action();
           
      };

      void print() {

           ofstream fout( FOUT );

           for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) fout<<*it<<" ";
      }

      private:    
      vector<int> arr;
      int n;  
      void _combsort_in_action() {

           int gap = n, swapped = 0;

           float shrinkFactor = 1.3;

           while( gap > 1 || swapped ) {

                 if( gap > 1 ) gap = gap / shrinkFactor;

                 swapped = 0;

                 for(int i = 0; i + gap < n; ++i ) {

                     if(arr[ i ] > arr[ i + gap ]) {

                        _swap( i, i + gap );

                        swapped = 1; 
                     } 
                 } 
           }          

      }; 

      void _swap(int a, int b) {

                int tmp;
                    tmp = arr[ a ];
                    arr[ a ] = arr[ b ];
                    arr[ b ] = tmp;   
      }

};

int main() {

    int n, elem;

    ifstream fin( FIN );

    fin>>n;

    Container container(n);
     
    for(int i = 0; i < n; ++i) fin>>elem, container.added( elem );

    container.sorted();     

    container.print(); 
    
    return(0);  
};