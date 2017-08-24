#include <fstream>
#include <iostream>
#include <vector>
#define pb push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"


using namespace std;

class Container{

      public:
      Container(){};

      void sorted() {

           doPancake();
      };

      friend istream &operator>>(istream &stream, Container &obj) {

             int n, item; 

             vector<int> vec;

             stream>>n; 

             obj.n = n;

             for(int i = 0; i < n; ++i) stream>>item, vec.pb(item);

             obj.vec = vec;
      };


      friend ostream &operator<<(ostream &stream, const Container &obj) {

             vector<int> vec = obj.vec;

             for(auto v:vec) stream<<v<<" "; 

             return stream;
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

 ifstream fin( FIN );
 ofstream fout( FOUT );

 Container container; 
 fin>>container;
 container.sorted();  
 fout<<container;

 return(0);
};