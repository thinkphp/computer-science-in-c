#include <iostream>
#include <fstream>
#include <vector>
#define loop(vec) for(const auto &number : vec)
#define iter(i,begin,end) for(int i = begin; i <= end; ++i)
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

template<typename T>
void mergeSort(vector<T> &vec, T lo, T hi) {

     if( lo >= hi ) return;

     T m = (lo + hi)>>1;

     mergeSort<T>(vec, lo, m);
     mergeSort<T>(vec, m + 1, hi); 

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

     iter(q, lo, hi) vec[ q ] = aux[ k++ ];
}

int main() {

    vector<int> vec; 

    ifstream fin( FIN );

    ofstream fout( FOUT );

    int num,

        n; 
 
      fin>>n;

      while( fin>>num ) vec.push_back( num );   

      //call the function mergeSort to sort the array
      mergeSort<int>(vec, 0, vec.size()-1 ); 
                
      loop( vec ) fout<<number<<" ";  

    return(0);
}