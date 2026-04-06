#include <iostream>

using namespace std;

int factorial(int li, int ls) {

	if(li > ls) return 1;

	if(li == ls) return li;

	int mid = (li+ls)>>1;

	return factorial(li, mid) * factorial(mid+1, ls);
}
        




int main(int argc, char const *argv[])
{
	int n = 5;
	cout<<factorial(1,n);
	return 0;
}
