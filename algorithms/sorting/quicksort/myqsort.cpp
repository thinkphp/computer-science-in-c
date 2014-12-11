#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ull;

using namespace std;

int* read();
void write(int*);

class qSort 
{      
      public:
      //constructor of the class
      qSort(int *p) : v( p ), n( p[ 0 ] ) {};

      //destructor of the class
      ~qSort(){};//nothing to do

      void sort() 
      {
           _qsort(1, n);
      };
       
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
    //declare a pointer to integer
    int *p;

    //read the data
    p = read();

    //define a pointer to the class qSort and make allocation
    qSort *q = new qSort( p );

           //execute sorting
           q->sort(); 

    //write the sorted array to the output File
    write( p );     

    //free allocation p
    delete [] p; 

    //free allocation q
    delete q;  

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

    for(int i = 1; i <= p[0]; i++) fout<<p[ i ]<<" ";

    fout.close();
};
