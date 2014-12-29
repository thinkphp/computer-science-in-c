#include <iostream>
#include <fstream>
#include <stack>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

using namespace std;

int arr[ MAXN ], 
    n;

void swap(int *a, int *b) {

     int temp = *a;

     *a = *b;

     *b = temp;
};

int partition(int lo, int hi) {

    int i = lo - 1,

        x = arr[ hi ];

    for(int j = lo; j <= hi - 1; j++) {

        if(arr[ j ] <= x) {

           i++; 

           swap(&arr[i], &arr[j]);   
        } 
    } 

    swap(&arr[i+1], &arr[hi]);   

    return i+1;
};

void read() {

     ifstream fin( FIN );

     fin>>n;

     for(int i = 0; i < n; i++) {

         fin>>arr[ i ];          
     }
};

void write() {

     ofstream fout( FOUT );

     for(int i = 0; i < n; i++) {

         fout<<arr[ i ]<<" ";          
     }

     fout.close();
};

void _sort(int lo, int hi) {

     if(lo < hi) {

        int p;

            p = partition(lo, hi);
            _sort(lo, p - 1);
            _sort(p + 1, hi);
     }
};


void sort() {

     _sort(0, n-1);
};

int main() {

     read();

     sort(); 

     write(); 

     return(0);  
};