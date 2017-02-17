#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

void shellsort(int *arr, int begin, int end){

     int i,j; 

     for(int gaps = end/2; gaps > 0; gaps/=2) {

             int gap = gaps; 
             
             for(i = gap; i <= end; i++) {

                 int aux = arr[ i ];

                     for(j = i - gap; (j>=0 && (arr[j] > aux)); j -= gap) {

                         arr[ j + gap] = arr[ j ];
                     }  

                     arr[ j + gap] = aux;
             } 

     }

}

int main() {

    int *arr;

    ifstream fin( FIN );

    ofstream fout( FOUT );

    int num,

        n; 
 
      fin>>n;

      arr = new int[ n ];

      for(int i = 0; i < n; ++i) fin>>num, arr[ i ] = num; 

      shellsort(arr, 0, n - 1);

      for(int i = 0; i < n; ++i) fout<<arr[ i ]<<" ";

      delete[]arr;  
     
    return(0);
}