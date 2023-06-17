#include <iostream>
using namespace std;
 
int main() {
 
	int arr[] = {20,30,35,45,123,178,293};
 
	int i,step,N=sizeof(arr)/sizeof(arr[0]),key = 20;
 
	for(step=1;step<N;step<<=1);
	cout<<step;
 
	for(i = 0; step; step >>=1) 
	    if(i + step < N && arr[i+step] <= key)
	       i+=step;
	cout<<i;      
	return 0;
}
