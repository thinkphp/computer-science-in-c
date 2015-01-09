#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define push push_back

typedef unsigned int uint;

class Container {

      public:
      Container( uint _N )
                         : 
                         N(_N) 
      {
      };

      ~Container(){};

      void add_to_container(uint elem) 
      {
           vec.push( elem );     
      }

      void sorted() 
      {

           _qsort(0, N - 1);
      };

      friend std::ostream &operator << (std::ostream &stream, const Container &obj) 
      {

             for(auto const el: obj.vec) {

                 stream<<el<<" ";  
             }
 
             return stream;
      }; 

      private:
      std::vector<uint> vec;
      uint N;

      void _s(int x, int y) 
      {

           int aux;

               aux = vec[ x ] ^ vec[ y ];

               vec[ x ] = aux ^ vec[ x ];

               vec[ y ] = aux ^ vec[ y ]; 
      };

      void _qsort(int low, int high) 
      {

           int i = low,

               j = high,

               piv = vec[ (low + high) >> 1 ];

               while(i <= j) {

                     while(vec[ i ] < piv) i++;

                     while(vec[ j ] > piv) j--;

                     if( i <= j ) {_s(i, j); i++; j--;}
               }

               if(low < j) _qsort(low, j); 

               if(i < high) _qsort(i, high);
      };

};

char str[5500000];

int main() {

    std::vector<uint> vec; 
    uint N;

    freopen(FIN, "r", stdin);

    scanf("%d\n",&N); 

    Container obj( N );

    gets( str );

    fclose( stdin );

    str[strlen(str)] = ' ';

    int j = 0;

    for(int i = 0; i < N; i++) {

        int num = 0;
         
        while(str[ j ] != ' ') {

              num = num * 10 + str[ j ] - '0';

              j++;
        }

        obj.add_to_container( num );

        j++;
    }  

    obj.sorted();

    std::ofstream fout( FOUT );

    fout<<obj;

    fout.close();
 
  return(0); 
};