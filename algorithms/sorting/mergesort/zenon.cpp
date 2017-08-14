#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:
      //constructor of the class
      Container(vector<int> _vec):arr(_vec){

               n = arr.size();
      };

      void sorted() {

           _mergesort(0, n - 1);
      };

      void print() {

           ofstream fout( FOUT );

           for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {

               fout<<*it<<" "; 
           }             
      };

      private:
      vector<int> arr;
      int n;  

      void _mergesort(int left, int right) {

           if(left == right) {

              return;

           } else {

              int half = (left + right) >> 1;

              _mergesort(left, half); 

              _mergesort(half+1, right);

              vector<int> merged;

              int firstPos = left, secondPos = half + 1;


              while(firstPos <= half && secondPos <= right) {
                    
                    if(arr[firstPos] < arr[secondPos]) merged.push_back(arr[firstPos++]);
  
                                               else    merged.push_back(arr[secondPos++]);   
              }

              while(firstPos <= half) merged.push_back(arr[firstPos++]);

              while(secondPos <= right) merged.push_back(arr[secondPos++]);

              for(int i = left; i <= right; ++i) arr[ i ] = merged[ i - left];
           }
      };
};

using namespace std;

int main() {

     int n, elem; 

     vector<int> vec;

     ifstream fin( FIN );

     fin>>n;  

     for(int i = 0; i < n; ++i) fin>>elem, vec.push_back( elem );

     Container container( vec );

     container.sorted();

     container.print();      


 return(0);
};