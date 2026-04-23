#include <iostream>

int n;

int BIT[ 100 ] = {0};

void update(int i, int val) {

	 while(i <= n) {

	 	BIT[ i ] += val;

	 	i += (i & -i);	 	
	 }
}

int query( int i ) {

    int sum = 0;

    while( i >= 1 ) {
 
        sum += BIT[i];

        i -= ( i & -i );   
    }   

    return sum;
}

int main(int argc, char const *argv[])
{

	//int arr[] = {0,1,5,7,8,10};
	int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
 
    n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 1; i < n; ++i) update(i, arr[i]);


    std::cout<<query(10) - query(0)<<std::endl;
	
	return 0;
}
