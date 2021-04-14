#include <stdio.h>
 
void __toBin(int n) {
 
	   int size = 16;
 
		 for(int i = size - 1; i >= 0; i--) {
 
			   printf("%d", (n>>i) & 1);
		 }
}
 
void _toBin(int n) {
 
    int arr[16],
		    k = 0;
 
     while(n > 0) {
 
			   arr[k++] = n % 2;
 
				 n /= 2;
		 }
 
		 for(int i = k - 1; i >= 0; i--) {
 
			   printf("%d", arr[i]);
		 }
 
}
 
double _pow(double a, double b) {
	double p;
	p = 1;
	for (int i = 1; i <= b; ++i)
	{
		 p = p * a;
	}
	return p;
}
 
void toBin(int n ){
     if( n / 2)
     	 toBin( n / 2);
 
     printf("%d", n % 2);
}
 
void toDec(int n) {
 
     double base,
            dec;
     base = 0;
     dec = 0;
 
     while(n > 0) {
 
           dec += (n % 10) * _pow(2, base);
           base += 1;
           n /= 10;
     }
 
     printf("%.f",dec);
}
 
int main(int argc, char const *argv[])
{
	int n
	;
	scanf("%d", &n)
	;
	toBin(n)
	;
	printf("\n")
	;
	toDec(1000000000)
	;
	printf("\n")
	;
	_toBin(n);
	printf("\n")
	;
	__toBin(n);
	return 0
	;
}
