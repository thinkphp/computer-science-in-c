#include <iostream>
#define FIN "ciur.in"
#define FOUT "ciur.out"

using namespace std;

int eratosthenes( int n ) {

     bool erat[ n + 1 ];

     int i, 
         j, 
         size = n - 1;

     for(int i = 2; i <= n; ++i) erat[ i ] = true;

     i = 2;

     while( i * i <= n ) {     	   

           if( erat[ i ] ) {

               j = 2;     	   

     	       while( i * j <= n ) {

                      int multiply = i * j;

                      if( erat[ multiply ] == true ) size--;

                      erat[ multiply ] = false; 

                      j++;
     	       }
     	   }    

     	   i++;
     }   

     return size;

}

int main(int argc, char const *argv[])
{
	int n;
    
    freopen(FIN, "r",stdin);   
    freopen(FOUT, "w",stdout);   

    cin>>n;

    cout<<eratosthenes(n);

	return 0;
}

//n = 10
// 2,3,4,5,6,7,8,9,10
