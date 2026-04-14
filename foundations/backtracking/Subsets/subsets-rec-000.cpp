#include <iostream>

using namespace std;
int n, 
    stack[100];

void subsets(int k) {

	if(k == n + 1) {
		cout<<"{ ";
		for(int i = 1; i <= n; ++i) {
			if(stack[i]==1) {
				cout<<stack[i]<<" ";
			}
		}
		cout<<"}";	
		cout<<"\n";
		return;
	}

	stack[k] = 1;
	subsets(k+1);
	stack[k] = 0;
	subsets(k+1);
}    

int main(int argc, char const *argv[])
{
	n = 3;
	subsets(1);
	return 0;
}
