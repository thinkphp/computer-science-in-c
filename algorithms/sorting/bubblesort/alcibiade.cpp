#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:
      Container(vector<int> _arr):vec(_arr){};
 
      void added(int val) {

           vec.push_back( val ); 
      };

      void sorted() {
       
           int i, 

               n = vec.size(), 

               swapped, 

               sorted_finished = 0;

           while( !sorted_finished ) {

                swapped = 0;
 
                for(i = 0; i < n - 1; ++i) {

                    if(vec[ i ] > vec[ i + 1 ]) {
  
                       int tmp = vec[ i ] ^ vec[ i + 1 ];

                           vec[ i ] = tmp ^ vec[ i ];

                           vec[ i + 1 ] = tmp ^ vec[ i + 1 ];

                           swapped = 1;  
                    } 
                } 

                if( swapped ) n--;

                     else 
                              sorted_finished = 1; 
           }
           

      };

      void print() {

           ofstream fout(FOUT);

           for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {

               fout<<*it<<" "; 
           } 
      };
 
      private:
      vector<int> vec;
      int n;
    
};

int main() {

    //vars declarations
    int i, elem, n; 
    vector<int> arr;
    ifstream fin(FIN);

    fin>>n;

    for(i = 0; i < n; ++i) fin>>elem, arr.push_back( elem );

    Container container(arr);

    container.sorted();

    container.print(); 

    return(0);
};