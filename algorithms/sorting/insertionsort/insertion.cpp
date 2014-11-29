/**
 *  Insertion Sort in C++ Language for 40 points.
 */

#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

using namespace std;

typedef unsigned int uint;

class InsertionSort {

     public:
     uint vec[ MAXN ],
          n;

     //constructor of the class
     InsertionSort() {
     };

     //destructor of the class  
     ~InsertionSort() {
     };

     void read() {

          ifstream fin( FIN );  

          fin>>n;

          for(uint i = 0; i < n; i++) fin>>vec[i];

          fin.close();
     };

     void write() {

          ofstream fout( FOUT );  

          for(uint i = 0; i < n; i++) fout<<vec[ i ]<<" ";

          fout.close();
     };


     void sort() {

          uint i,

               j,

               temp;

               for(i = 1; i < n; i++) {

                   if(vec[ i ] > vec[ i - 1 ]) continue;

                   temp = vec[ i ];

                   j = i - 1;

                   while(j >= 0 && vec[ j ] > temp) {

                         vec[ j + 1 ] = vec[ j ];

                         j--; 
                   }   

                   vec[ j + 1 ] = temp;
               } 

     };
};

int main() {

    InsertionSort obj;

    obj.read();

    obj.sort();

    obj.write(); 
 
    return(0); 
};
