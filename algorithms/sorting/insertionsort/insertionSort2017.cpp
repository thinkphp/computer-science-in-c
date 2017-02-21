#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

template<class ItemTypeVec>
void insertionSort(vector<ItemTypeVec> &vec) {

     int i, 
         j;
 
     for(i = 1; i < vec.size(); ++i) {

         auto tmp = move(vec[ i ]);

         if( vec[ i ] > vec[ i - 1] ) continue;  
 
         for(j = i - 1; (j >= 0 && (vec[ j ] > tmp)); j--) {

             vec[ j + 1 ] = move( vec[ j ] );          
         } 

         vec[ j + 1] = tmp;
     }

}

int main() {

    vector<int> vec; 

    ifstream fin( FIN );
    ofstream fout( FOUT );

    int num,

        n; 
 
      fin>>n;

      while( fin>>num )

      vec.push_back( num );   

      //call the function insertion to sort the array
      insertionSort<int>( vec ); 
          
      for(const auto &number : vec) {

          fout<<number<<" ";  
      }

    return(0);
}