#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

using namespace std;

typedef unsigned int uint;

uint arr[ MAXN ],
     n;

class ShellSort {

      public:

      uint *arr,
            N;  

      ShellSort(uint vec[],uint n) {

           arr = vec;

           N = n;

           shell();
      };

      void shell() {

           int d,

               dis,

               i,

               j,

               aux;

               int dist[ 8 ] = {15, 13, 11, 9, 7, 5, 3, 1};

            for(d = 0; d < 8; d++) {

                dis = dist[ d ];

                for(j = dis; j < n; j++) {

                    aux = arr[ j ];
       
                    for(i = j; i >= dis; i -= dis) {

                        if(arr[ i - dis ] > aux) {
 
                           arr[ i ] = arr[ i - dis ];
 
                        } else break;
                }
                arr[ i ] = aux;
               }
            }
};

void write() {

     uint i;

     ofstream fout( FOUT );
 
     for(i = 0; i < n; i++) fout<<arr[ i ]<<" ";

     fout.close();
};

};//end class

void read() {

     uint i;

     ifstream fin( FIN );

     fin>>n;
 
     for(i = 0; i < n; i++) fin>>arr[ i ];

     fin.close();
};


int main() {

    read();

    ShellSort shell(arr, n);

    shell.write(); 
 
  return(0);
};