#include <fstream>
#include <iostream>
#include <vector>
#define MAXN 500005
#define push push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

ofstream fout( FOUT );

class Container {

      public:
      Container(int _n): n(_n){}

      void added(int elem) {

           vec.push( elem );
      }

      void sorted() {
 
           divide(0, n - 1); 
      }

      void divide(int lo,int hi) {

           if(lo == hi) return;

           int m;

               m = (lo + hi) >> 1;  

               divide(lo, m);

               divide(m + 1, hi);

               merge(lo, m, hi);
      }

      void merge(int li, int m, int hi) {

           int i = li,

               j = m + 1,

               k = li;

           int aux[ MAXN ]; 

               while(i <= m && j <= hi) {

                     if(vec[ i ] <= vec[ j ]) aux[ k++ ] = vec[ i++ ];

                          else 

                                              aux[ k++ ] = vec[ j++ ];
               }

               while(i <= m) aux[ k++ ] = vec[ i++ ];

               while(j <= hi) aux[ k++ ] = vec[ j++ ];

               for(int i = li; i <= hi; i++) vec[ i ] = aux[ i ];
      } 

      void display() {

           for(int i = 0; i < n; ++i) fout<<vec[ i ]<<" ";
      }

      private:
      vector<int> vec;
      int n;
};

int main() {

    int n, elem;

    ifstream fin( FIN );    
 
    fin>>n;

    Container container( n );

    for(int i = 0; i < n; ++i) fin>>elem, container.added( elem );

    container.sorted();

    container.display(); 

    return(0);
};