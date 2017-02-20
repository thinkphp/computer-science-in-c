#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

template<class ItemTypeVec>
void selectionSort(vector<ItemTypeVec> &vec) {

     for(int i = 0; i < vec.size(); ++i) {

         int indexMin = i;

             for(int j = i + 1; j < vec.size(); ++j) {

                 if( vec[ j ] < vec[ indexMin ] ) {

                    indexMin = j;
                 } 
             } 

          if(i != indexMin) {

             auto tmp = move(vec[ i ]);

             vec[ i ] = move(vec[ indexMin ]);

             vec[ indexMin ]  = move( tmp ); 
          }
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

      selectionSort( vec ); 
          
      for(const auto &number : vec) {

          fout<<number<<" ";  
      }

    return(0);
}