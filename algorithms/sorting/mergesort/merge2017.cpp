#include <iostream>
#include <fstream>
#include <vector>
#define loop(vec) for(const auto &number : vec)
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

vector<int> vec; 

template<typename T>
void mergeSort(T lo, T hi) {

     if( lo >= hi ) return;

     T m = (lo + hi)>>1;

     mergeSort<T>(lo, m);
     mergeSort<T>(m + 1, hi); 

     vector<T> aux;

     T i = lo;
     T j = m + 1;  

     while(i <= m && j <= hi) {

           if(vec[ i ] < vec[ j ]) aux.push_back(vec[i++]);

                     else      
                                   aux.push_back(vec[j++]);
     }

     while( i <= m ) aux.push_back(vec[i++]);

     while( j <= hi ) aux.push_back(vec[j++]);

     T k = 0;

     for(int ii = lo; ii <= hi; ii++) vec[ ii ] = aux[ k++ ];
}

int main() {

    ifstream fin( FIN );

    ofstream fout( FOUT );

    int num,

        n; 
 
      fin>>n;

      while( fin>>num ) vec.push_back( num );   

      //call the function mergeSort to sort the array
      mergeSort<int>( 0, vec.size()-1 ); 
                
      loop( vec ) fout<<number<<" ";  

    return(0);
}