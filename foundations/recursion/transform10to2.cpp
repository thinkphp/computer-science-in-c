#include <iostream>

void transform(int n, int p) {
	int r = n % p;

	if(n>=p) transform(n/2, p);

	std::cout<<r;

}

int main(int argc, char const *argv[])
{
	int n;
	std::cout<<"n=";
	std::cin>>n;
	transform(n,2);
	return 0;
}
