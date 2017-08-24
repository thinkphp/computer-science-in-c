#include <fstream>
#include <iostream>
#include <vector>
#define pb push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"


using namespace std;

class Container{

      public:
      Container(vector<int> _arr):vec(_arr){n = vec.size();};

      void sorted() {

           doPancake();
      };

      friend ostream &operator<<(ostream &stream, const Container &obj) {

             vector<int> vec = obj.vec;

             for(auto v:vec) stream<<v<<" "; 
      };

      private:
      vector<int> vec;
      int n; 

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
      
      void doPancake() {

           for(int curr_size = n; curr_size > 1; --curr_size) {

               int idxMax = findMax( curr_size );

               if(idxMax != (curr_size - 1)) {

                  _flip(idxMax);

                  _flip(curr_size-1);
               }
           }
      };



      int findMax(int index) {

           int iMax = 0;
   
           for(int i = 1; i < index; ++i) 

               if(vec[i] > vec[iMax]) iMax = i;

           return iMax;  

      };
};

int main() {

 int n, 

     item;

 vector<int> arr;

 ifstream fin(FIN);
 ofstream fout(FOUT);

 fin>>n;
   
 for(int i = 0; i < n; ++i) fin>>item, arr.pb(item);
 
 Container container(arr); 
 container.sorted();  
 fout<<container;

 return(0);
};