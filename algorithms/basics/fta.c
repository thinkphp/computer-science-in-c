#include <stdio.h>

int main(int argc, char const *argv[]) {

  //we declare the variable for our algorithm
  int n, //n input
      i, //start with a variable i
      fm;//multiplicity factor

  printf("%s","Fundamental Theorem of Arithmentic\n");
  printf("%s\n","Source: https://mathworld.wolfram.com/FundamentalTheoremofArithmetic.html");
  printf("%s","Give a N = ");
  //read an integer
  scanf("%d", &n);

  printf("%d = ", n);
  //start with i equal 2
  i = 2;
  do {

      fm = 0;

      while( (n % i) == 0) {

          fm++;

          n /= i;
      }

      if(n == 1) printf("%d ^ %d", i, fm);
      else
      if( fm!=0 ) printf("%d ^ %d + ", i, fm);


      i++;

  } while(!( n == 1 ));
  printf("\n");

  return 0;
}
