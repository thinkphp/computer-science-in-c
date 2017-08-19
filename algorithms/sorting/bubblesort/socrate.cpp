#include <fstream>
#include <iostream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:
      Container(vector<int> _arr):vec(_arr){n = vec.size();}

      void sorted2() {

           int swapped = 1; 
            for(int i = 0; i < n - 1 && swapped; ++i) {
               swapped = 0;
               for(int j = 0; j < n - i - 1; ++j) {
                    if(vec[j] > vec[j+1]) {
                       int tmp = vec[j];
                           vec[j] = vec[j+1];
                           vec[j+1] = tmp;
                           swapped = 1; 
                    }
               }
           }          
      }; 


      void sorted1() {

           int swapped = 1; 
            for(int i = n-1; i >= 1 && swapped; --i) {
               swapped = 0;
               for(int j = 0; j < i; ++j) {
                    if(vec[j] > vec[j+1]) {
                       int tmp = vec[j];
                           vec[j] = vec[j+1];
                           vec[j+1] = tmp;
                           swapped = 1; 
                    }
               }
           }          
      }; 

      void sorted() {

           int i,
               finished = 0,
               swapped,
               last = n - 1;

               while(!finished) {
                      swapped = 0;
                      for(i = 0; i < last; ++i) {
                          if(vec[i]>vec[i+1]) {
                             int tmp = vec[i];
                                 vec[i] = vec[i+1];
                                 vec[i+1] = tmp;
                                 swapped = 1;   
                          }
                      } 
                      if(swapped) last--;
                            else  finished = 1;
               }  
                  
      }; 

      void sorted3() {

           for(int i = 0; i < n - 1; ++i) {

               for(int j = i + 1; j < n; j++) {

                   if(vec[i] > vec[j]) {

                      vec[i] = vec[i] + vec[j];
                      vec[j] = vec[i] - vec[j];
                      vec[i] = vec[i] - vec[j];  
                   }
               }
           } 
           
      }; 


      void sorted4() {

           int i,

               swapped,

               last = n - 1;
 
                do {
                      swapped = 0;

                      for(i = 0; i < last; ++i) {

                          if(vec[i]>vec[i+1]) {

                             int tmp = vec[i];
                                 vec[i] = vec[i+1];
                                 vec[i+1] = tmp;
                                 swapped = 1;
                          }
                      } 
       
                      if( swapped ) last--;

                 } while(swapped);
                  
      }; 


      void print() {

           ofstream fout( FOUT );
           for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
               fout<<*it<<" ";
           }
      };
      
      private:
      vector<int> vec;
      int n;
};

int main() {

    int n, item;
    ifstream fin( FIN );
    vector<int> arr;

    fin>>n;
    for(int i = 0; i < n; ++i) fin>>item, arr.push_back(item);
    Container container( arr );
    container.sorted3();
    container.print(); 
    return(0);
};