#include <iostream>
#include <cmath>
#define FIN "ciur.in"
#define FOUT "ciur.out"
#define SIZE 2000002

using namespace std;

bool notPrimes[SIZE];
int counter, 
    n;

int main(int argc, char const *argv[])
{
    
    cin>>n;

    for(int i = 2; i <= sqrt(n); ++i) {

    	if(notPrimes[i]) {
    		continue;
    	}

    	int j = 2 * i;

    	while(j <= n) {
            if(!notPrimes[j]){        
                notPrimes[j] = true;  
                counter++;
            }    
    		j+=i;
    	}
    }

    cout<<n - counter - 1;
	
	return 0;
}
