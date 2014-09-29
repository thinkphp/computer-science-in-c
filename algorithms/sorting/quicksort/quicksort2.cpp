#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"
 
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ull;
 
using namespace std;
 
int* read();
void write(int*);
 
class QuickSort
{     
      //public members
      public:
      //constructor of the class
      QuickSort(int *p) : v( p ), n( p[ 0 ] ) {};
 
      //destructor of the class
      ~QuickSort(){};//nothing to do
 
      void sort()
      {  
           _qsort(1, n);
      };

      friend ostream& operator << (ostream &stream, QuickSort &ob) 
      {
             int N = ob.n;

             for(int i = 1; i <= N; i++) {

                 stream<<ob.v[ i ]<<" "; 
             }

             return stream;
      };

      //private members        
      private: 
      int *v,
           n;   

      void _qsort(int li, int ls)
      {
 
           int i = li,
 
               j = ls,
 
               p = v[ (li + ls ) >> 1 ];
 
               while( i <= j ) {
 
                     while( v[ i ] < p ) i++;
 
                     while( v[ j ] > p ) j--;
 
                     if( i <= j ) _swap(i, j), i++, j--;
               }
 
               if(li < j ) _qsort(li, j);
 
               if( i < ls ) _qsort(i, ls);
      };
 
      void _swap(int x, int y)
      {
 
           int aux;

               aux = v[ x ] ^ v[ y ];    

                     v[ x ] = aux ^ v[ x ];

                     v[ y ] = aux ^ v[ y ];
      } 
};
 
int main()
{
    int *p;

    ofstream cout( FOUT ); 
 
    p = read();
 
    QuickSort ob( p );
 
    ob.sort( );

    cout<<ob;
 
    delete p; 

    cout.close();
 
    return(0);
};
 
int* read()
{ 
     ifstream fin( FIN ); 
 
     int *p,
          n,
          i;    
 
     fin>>n;
 
     p = new int[ n ];
 
     for(i = 1; i <= n; i++) fin>>p[ i ];
 
     p[ 0 ] = n;
 
     fin.close();
   
     return p;    
};
