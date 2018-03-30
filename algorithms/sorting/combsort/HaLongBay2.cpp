#include <iostream>
#include <fstream>

using namespace std;

void combsort(int *p, int n) {
 
     int swapped = 1, 

         gap = n, 

         i;

     float shrinkFactor = 1.3;


     while( gap > 1 || swapped ) {

           if( gap > 1 ) gap = gap / shrinkFactor;

           swapped = 0;

           for(i = 0; (i + gap) < n; ++i) {

               if( p[ i ] > p[ i + gap ] ) {

                  int tmp = *(p + i);

                      *(p + i) = *(p + i + gap); 

                      *(p + i + gap) = tmp;

                      swapped = 1;
               }
           }           
     }
};

int main() {

    const char* fin = "algsort.in";

    const char* fout = "algsort.out";

    int n, *v;        

    freopen(fin, "r", stdin);

    freopen(fout, "w", stdout);

    cin>>n;

    v = new int[ n ];

    for(int i = 0; i < n; ++i) cin>>*(v + i); 

    combsort(v, n);       

    for(int i = 0; i < n; ++i) cout<<*(v + i)<<" "; 

    delete v;

 return(0);
};