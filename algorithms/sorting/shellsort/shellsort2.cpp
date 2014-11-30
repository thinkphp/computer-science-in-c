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

          int gap = n - 1,

              g,

              i, 

              j,

              k,

              temp;

         for(g = gap/2; g > 0; g /= 2) {

             for(i = g; i < n; i++) {

                 temp = arr[ i ];

                 for(j = i; j >= g; j -=g) {

                     if(arr[j - g] > temp) {

                       arr[ j ] =  arr[j - g];

                     } else {

                       break; 
                     }
                 }

                 arr[ j ] = temp;
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
