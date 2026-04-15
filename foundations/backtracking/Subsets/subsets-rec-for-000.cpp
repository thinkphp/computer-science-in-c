#include <iostream>

using namespace std;
int n, 
    stack[100];

void subsets(int k) {

	if(k == n + 1) {
	
		cout<<"{ ";
		for(int i = 1; i <= n; ++i) {
		
			if(stack[i]==1) {
			
				cout<<i<<" ";
			}
		}
		
		cout<<"}";	
		cout<<"\n";
		return;
	}
	
	for(int i = 1; i >= 0; i--) {
	
	    stack[k] = i;
	    
	    subsets(k+1);    
	}

   
}
int main(int argc, char const *argv[])
{
	n = 3;
	subsets(1);
	return 0;
}
/*
DFS Preordine
                               1

                           0

                        0        0 
                                101 100
                1 1 1     1 1 0        
*/
