/**
 * Merge Sort within Container.
 */
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

      ~Container()
      {
      };

      void add_to_container(uint elem) 
      {
           vec.push( elem );     
      }

      void sorted() 
      {
           _mergesort(0, N - 1);
      };

      friend std::ostream &operator << (std::ostream &stream, const Container &obj) 
      {
             for(auto const &elem: obj.vec) 

                 stream<<elem<<" "; 
 
             return stream;
      }; 

      private:
      std::vector<uint> vec;
      uint N;

      void _mergesort(int low, int high) 
      {
           if(low == high) return; 

           else 
           {
                int middle = (low + high) >> 1;

                _mergesort(low, middle); 

                _mergesort(middle + 1, high);

               int i,
                   j, 
                   p1 = low,
                   q1 = middle,
                   p2 = middle + 1,
                   q2 = high,  
                   merged[ q1 - p1 + 1 ];

           //make a copy of the first interval to merge.
           for(i = p1; i <= q1; i++) merged[ i - p1 ] = vec[ i ];                        

           i = 0;
           j = q1 - p1;

           while( i <= j && p2 <= q2 ) 
           {

                 if(merged[ i ] < vec[ p2 ]) vec[ p1++ ] = merged[ i++ ];

                                else         

                                             vec[ p1++ ] = vec[ p2++ ];      
           }

           while( i <= j ) vec[ p1++ ] = merged[ i++ ];

           } 
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