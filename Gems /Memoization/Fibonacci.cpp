#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

std::vector<int> memo;

long long fibonacci_map(int n, std::map<int, long long> &memo) {

          if(memo.find(n) != memo.end()) {

            return memo[ n ];
          }

          if(n<=1) {
            return n;
          }

          memo[n] = fibonacci_map(n-1, memo) + fibonacci_map(n-2, memo);

          return memo[n];

}

int fibonacci(int n) {

    if( n <= 1 ) return n;

    //daca rezultatul a fost calculat adica memo[n]!=-1, returnam valoarea din vector
    if( memo[ n ] != -1 ) return memo[ n ];

    //o stocam in vectorul memo
    memo[ n ] = fibonacci( n - 1 ) + fibonacci( n - 2 );

    return memo[n];
}

int factorial(int n, std::vector<int>&memo) {

     if(n <= 1) return 1;

     if(memo[n] != -1) return memo[n];

     memo[n] = n * factorial(n-1, memo);

     return memo[n];

}

//in vectorul memo stocam resultatele intermediare ale functiei fibonacci
//fibonacci cu memoizare
int main() {

   std::map<int, long long>memo2;//tabla de memoizare

   int n = 10;

   std::vector<int> memo_fact(n+1,-1);

   //initializam vectorul memo cu -1 pentru a indica ca aceste valori nu au fost
   // inca calculate
   memo.resize(n + 1, -1);

   std::cout<<"fibonacci("<<n<<") = "<<fibonacci( n )<<std::endl;
   std::cout<<"fibonacci("<<n<<") = "<<fibonacci_map( n, memo2 )<<std::endl;

   std::cout<<"factorial("<<n<<") = "<<factorial( n, memo_fact )<<std::endl;

   return 0;
}

//folosim memoizare ca sa reduce semnificativ timpul de executie pentru a calcula fibonacci

//fibo(10) = fibo(9)          +   fib(8)
//fibo(9) = fibo(8)+fibo(7)       fibo(7) +     fibo(6)
//         fibo(7)+fibo(6)       fib(6)+fib(5)   fib(5)+fibo(4)
//0,1,1,2,3,5,8,13,21,....



/*
                        fibonacci(7)

          fibonacci(6)       +                             fibonacci(5)

      fibonacci(5) +  fibonacci(4)                fibonacci(4) +             fibonacci(3)

  fibonacci(4)+fibonacci(3)  fibonacci(3)+fibonacci(2)  fibonacci(3)+fibonacci(2) fibonacci(2)+fibonacci(1)
......


fact(10) = 10 * fact(9) = 10 * 9 * fact(8)

*/
