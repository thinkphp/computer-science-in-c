#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

vector<int> vec; //the vector
int N; //number of components

void readData();
void QuickSort();
void _QuickSort(int,int);
void _swap(int,int);
void writeData(); 

int main() {

    readData();
    QuickSort();
    writeData(); 

    return(0);
};

void readData() {

     int num;

     ifstream fin(FIN);
 
     fin>>N;

     for(int i = 0; i < N; ++i) fin>>num, vec.push_back(num);

     fin.close(); 
}

void _QuickSort(int li, int ls) {

     int i = li,

         j = ls,

         piv = vec[ (li + ls) >> 1 ];

     while(i<=j) {

           while(vec[i] < piv) i++; 
           while(vec[j] > piv) j--; 

           if( i <= j ) {

              _swap(i, j);

              i++;

              j--; 
           }           
     } 

     if(li < j) _QuickSort( li, j );

     if(i < ls) _QuickSort( i, ls); 
}

void _swap(int i, int j) {

     int aux;

     aux = vec[ i ] ^ vec[ j ];

     vec[ i ] = aux ^ vec[ i ];

     vec[ j ] = aux ^ vec[ j ];
}


void QuickSort() {

     _QuickSort(0, N - 1);
}

void writeData() {

     ofstream fout(FOUT);
   
     for(int i = 0; i < N; ++i) fout<<vec[ i ]<<" ";

     fout.close();
}
