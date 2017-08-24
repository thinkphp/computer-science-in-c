#include <fstream>
#include <iostream>
#include <vector>
#define pb push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"


using namespace std;

class Container{

      public:
      Container(vector<int> _arr):vec(_arr){n = vec.size();}
      void sorted() {
           _pancake(); 
      }; 

      //g++ filename.cpp
      void print() {
           for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) cout<<*it<<" ";
      };

      //g++ filename.cpp -std=c++11
      void print2() {

           for(auto v:vec) cout<<v<<" ";  
      };

      private:
      vector<int> vec;
      int n;

      int _findMax(int index) {

          int idxMax = 0;

          for(int i = 1; i < index; ++i) 

              if(vec[i] > vec[idxMax]) idxMax = i;

          return idxMax;  
      }; 


      void _flip(int index) {

           int start = 0;

           while(start < index) {

                 int tmp = vec[start];

                     vec[start] = vec[index];

                     vec[index] = tmp;

                     start++;

                     index--; 
           } 
      }; 

      void _pancake() {

           int curr, 

               size = n, 

               idxMax;

           for(curr = size; curr > 1; --curr) {

               idxMax = _findMax(curr);

               if(idxMax != (curr-1)) {

                  _flip(idxMax);

                  _flip(curr-1);
               }
           } 
      };
};

int main() {

    int n, item;
    vector<int> vec;
 
    ifstream fin(FIN);
    fin>>n;
    for(int i = 0; i < n; ++i) {
        fin>>item;
        vec.pb(item);
    }   
    Container container(vec);
    container.sorted();
    container.print(); 

    return(0);
};