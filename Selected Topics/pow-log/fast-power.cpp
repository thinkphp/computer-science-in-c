#include <iostream>
#include <cmath>

int pow(int a, int n) {

	int p = 1;

	for(int i = 1; i <= n; ++i) p*=a;

	return p;
}

int fast_pow(int a, int n) {

	int result = 1;

	while(n>0) {
		if(n&1) result = result * a;
		a = a * a;
		n>>=1;
	}

	return result;
} 

long long power(long long base,int exp) {

	 long long result = 1;

	 while(exp > 0) {
	 	if(exp&1) result = result * base;

	 	base = base * base;

	 	exp>>=1;
	 }

	 return result;
}

int log2_fast(int a) {
    int cnt = 0;
    while (a >>= 1) {
        cnt++;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
	
	int n = 10;

	std::cout<<fast_pow(2,20);
	std::cout<<pow(2,20)<<std::endl;
	std::cout<<log2(20)+1<<"\n";
	std::cout<<log2_fast(8)<<std::endl;
	std::cout<<power(2,3);
	return 0;
}
