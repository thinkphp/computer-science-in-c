/**
 *  @description Cocktail Sort for 40 points.
 *  @License     MIT  
 */

#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

using namespace std;

class Sort {

      public:

      int arr[ MAXN ],
          n;

      //constructor of the class 
      Sort() {
      };
 
      //descructor of the class
      ~Sort() {
      };

      void read() {

           ifstream fin( FIN );

           fin>>n;

           for(int i = 0; i < n; i++ ) {

               fin>>arr[ i ]; 
           }  
      };

      void cocktail() {

           int start = 0,
               end = n - 1,
               i, 
               j, 
               swapped;

            do {

               swapped = 0;

               for(i = start; i < end; i++) {

                   if( arr[ i ] > arr[ i + 1 ] ) {

                       swap(i, i + 1);

                       swapped = 1;
                   }
               }

               end--;

               swapped = 0;

               for(j = end; j >= start; j--) {

                   if( arr[ j ] > arr[ j + 1 ] ) {

                       swap(j, j + 1);

                       swapped = 1;
                   }
               }                  

               start++;

            } while( swapped );   
      };

      void write() {

           ofstream fout( FOUT );

           for(int i = 0; i < n; i++ ) {

               fout<<arr[ i ]<<" "; 
           }  

      };

      private:

      void swap(int a,int b) {

           int x;

               x = arr[ a ] ^ arr[ b ]; 
 
               arr[ a ] = x ^ arr[ a ];

               arr[ b ] = x ^ arr[ b ];
      };   
};

int main() {

    Sort obj; 

    obj.read();

    obj.cocktail();

    obj.write();
  
    return(0);
}