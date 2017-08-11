#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500005

using namespace std;

int arr[SIZE],
    n;

void read() {

     ifstream fin( FIN );

     fin>>n;

     for(int i = 0; i < n; ++i) fin>>arr[i];
};

void sorted() {

     int i, 

         finished = 0, 

         swapped, last = n;

          do {  

                 swapped = 0;

                 for(i = 0; i < last - 1; ++i) {

                     if(arr[ i ] > arr[ i + 1 ]) {

                        int tmp = arr[ i ];

                            arr[ i ] = arr[ i + 1 ];

                            arr[ i + 1 ] = tmp;

                        swapped = 1;
                     }
                 }

                 if( swapped ) last--;

                     else 
                               finished = 1; 

         } while(!finished);
       
};

void write() {

     ofstream fout( FOUT );
       
     for(int i = 0; i < n; ++i) fout<<arr[i]<<" ";   
};

int main() {

    read();

    sorted(); 

    write();    

 return(0);
};