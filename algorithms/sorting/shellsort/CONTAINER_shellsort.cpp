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

      void shellsort() {

           int gaps, gap, i, j; 

           for(gaps = n/2; gaps > 0; gaps/=2) {

               gap = gaps;

               for(i = gap; i < n; ++i) {

                   int temp = vec[ i ];

                   for(j = i - gap; (j >= 0 && vec[j] > temp); j-=gap) {

                       vec[ j + gap] = vec[ j ];
                   }

                   vec[ j + gap ] = temp;
               } 
           } 
  
      };

      void sorted() {

           shellsort();
      };

      void print() {

           ofstream fout(FOUT);
            
           for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) 

               fout<<*it<<" "; 

               fout.close();
      };
       
      private:
      int n;
      vector<int> vec; 
};

int main() {

    int n, elem;

    ifstream fin( FIN );

    fin>>n;

    Container container( n );

    for(int i = 1; i <= n; ++i) fin>>elem, container.added( elem );

    container.sorted();

    container.print(); 

 return(0);
}