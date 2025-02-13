#include <stdio.h>
#include <math.h>

double pow2(double x, int n) {

       double ans = 1; 

       if(n == 0) return 1;
      
       if(n < 0) x = 1 / x;

       while(n) {

          if(n % 2) ans *= x;

          x *= x;

          n /= 2;
       }

       return ans;
}

double pow2_rec(double x, int n) {

       double t;

       if(n == 0) return 1;       

       t = pow2_rec(x, n / 2);

       if( (n & 1) == 0) return t * t;
       //if( n % 2 == 0) return t * t;

             else {
  
                   if(n > 0) return x * t * t; 

                   else 

                            return  (t * t) / x;
              }
}	

int main(int argc, char const *argv[])
{
	printf("%f\n", pow(3.14, -5));

	printf("%f\n", pow2(3.14, -5));

	printf("%f\n", pow2_rec(3.14, -5));

	return 0;
}
