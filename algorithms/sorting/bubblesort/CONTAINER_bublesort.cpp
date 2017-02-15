#include <fstream>
#include <iostream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class Container {

      public:
      Container(int _n): n(_n){}
      ~Container(){}  

      void added(int elem) {

           vec.push_back( elem );
      }

      void bubblesort() {

           for(int i = 0; i < n - 1; ++i) {

               for(int j = i + 1; j < n; j++) {

                   if(vec[ i ] > vec[ j ]) {

                      swap(vec[i], vec[j]);
                   }                   
               } 
           }            
      };

      void sorted() {

           bubblesort();
      };

      friend ostream &operator<<(ostream &stream, const Container &obj) {
         
           vector<int> vec = obj.vec; 

           for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) 

               stream<<*it<<" "; 

             return stream;
      };

      void print() {

           ofstream fout(FOUT);

               for(auto const &elem: vec) {

                   cout<<elem<<" "; 
               }             

               fout.close();
      };
       
      private:
      int n;
      vector<int> vec; 
};

int main() {

    int n, elem;

    ifstream fin( FIN );
    ofstream fout( FOUT );

    fin>>n;

    Container container( n );

    for(int i = 1; i <= n; ++i) fin>>elem, container.added( elem );

    container.sorted();

    fout<<container;

    fout.close();

 return(0);
}