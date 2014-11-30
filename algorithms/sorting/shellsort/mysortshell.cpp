/**
 *  @description Shell Sort Algorithm for 100 points.
 *  @License     MIT  
 */

#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

using namespace std;

int arr[MAXN],
    n;

class Sort {

      public:

      int *arr,

           n;

      //constructor of the class 
      Sort(int p[], int N) {

           arr = p;

           n = N;
      };
 
      //descructor of the class
      ~Sort() {

      };

      void shellsort() {

           int h = 1,
               i,
               j, 
               aux;

           do {

              h = 3 * h + 1;
  
           } while( h <= n);

           do {

              h /= 3;

              for(j = h; j < n; j++) {

                  aux = arr[ j ];

                  for(i = j - h; i >= 0 && arr[ i ] > aux; i -= h) {

                          arr[ i + h ] = arr[ i ];
                  }  

                          arr[ i + h ] = aux;
              } 

           } while(h > 0);
      };

      void write() {

           ofstream fout( FOUT );

           for(int i = 0; i < n; i++ ) {

               fout<<arr[ i ]<<" "; 
           }  

           fout.close();
      };
};

      void read() {

           ifstream fin( FIN );

           fin>>n;

           for(int i = 0; i < n; i++ ) {

               fin>>arr[ i ]; 
           }

           fin.close();
      };

int main() {

    read();

    Sort obj(arr, n);
 
    obj.shellsort();

    obj.write();
  
    return(0);
}