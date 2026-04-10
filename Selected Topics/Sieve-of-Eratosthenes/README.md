# Sieve of Eratosthenes

```cpp

#include <iostream>
#include <fstream>

typedef unsigned long ulong;
typedef unsigned  int uint;

namespace Erathostenes {

          ulong getCount(ulong n) {

                ulong i,j;

                bool isPrime[ n + 1 ];

                for(i = 2; i <= n; ++i) isPrime[ i ] = true;

                ulong totalPrimes = n - 1;

                for(i = 2; i * i <= n; ++i) {

                    if( isPrime[ i ] ) {

                        j = 2;

                        while( i * j <= n ) {

                               ulong multiple = i * j;

                               if( isPrime[ multiple ] ) totalPrimes--;

                               isPrime[ multiple ] = false;

                               j++;
                        } 
                    }   
                }                

                return totalPrimes;
          }
};

using namespace std;
using namespace Erathostenes;

int main() {

    const char *inFile = "ciur.in"; 
    const char *outFile = "ciur.out";

    ifstream fin( inFile );
    ofstream fout( outFile );

    if(!fin || !fout) {

        cerr<<"Error opening one of "<<inFile<<" or "<<outFile<<endl; 
        return -1;
    } 

    ulong n;

    fin>>n;

    fout<<getCount( n ); 

 return(0);
};
```

### Problem Set

- https://www.infoarena.ro/problema/ciur
- Cufar https://www.infoarena.ro/problema/cufar
- Count Primes https://leetcode.com/problems/count-primes/
- Prime Arrangements https://leetcode.com/problems/prime-arrangements/description/
- Largest Component Size by Common Factor https://leetcode.com/problems/largest-component-size-by-common-factor/description/
- Prime Number of Set Bits in Binary Representation  https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/

