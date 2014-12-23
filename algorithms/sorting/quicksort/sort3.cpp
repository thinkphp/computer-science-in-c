#include <iostream>
#include <fstream>

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ull;

const char *FIN = "algsort.in";
const char *FOUT = "algsort.out";

using namespace std;

int* read();
void write(int*);

class qSort 
{

      public:
      qSort(int *p) : v( p ), n( p[ 0 ] ) 
      {

           sort();
      };
       
      private:
      int *v,
           n;    

      void sort() 
      {

           _qsort(1, n);
      };

      void _qsort(int li, int ls) 
      {

           int i = li,

               j = ls,

               p = v[ (li + ls ) >> 1 ];

               while( i <= j ) {

                     while( v[ i ] < p ) i++;

                     while( v[ j ] > p ) j--;

                     if( i <= j ) _swap(i,j), 
                                  i++, j--;
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

    p = read();

    qSort q( p );

    write( p );     

    delete [] p; 

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

void write( int *p ) 
{

    ofstream fout( FOUT );  

    for(int i = 1; i <= p[ 0 ]; i++) fout<<p[ i ]<<" ";

    fout.close();
};
