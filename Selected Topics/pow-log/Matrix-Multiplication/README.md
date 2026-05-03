# Matrix Multiplication
```
#include <iostream>
struct Matrix {
	long long a, b, c, d; //(a, b; c d)
};

Matrix multiply(const Matrix& A, const Matrix& B) {
	return {
          A.a*B.a + A.b*B.c,
          A.a*B.b + A.b*B.d,
          A.c*B.a + A.d*B.c,
          A.c*B.b + A.d*B.d
	};
}

Matrix fastPower(Matrix base, long long n) { 
  
       Matrix result = {1,1,1,0}; //identity matrix

       while(n>0) {
       	  if(n&1) result = multiply(result, base);
       	  base = multiply(base, base);
       	  n>>=1;
       }   
       return result;
}

long long Fib(long long n) {
	if(n==0) return 0;
	Matrix F = {1,1,1,0};
	Matrix R = fastPower(F, n-1);
	return R.a;
}

int main(int argc, char const *argv[])
{

    int n = 10;
    for(int i = 1; i<=n; ++i) std::cout<<Fib(i)<<" ";
	
	return 0;
}
```
