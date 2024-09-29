#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Fibonacci {

      public:
      vector<long long> getFibonacci(int n) {
            vector<long long> result;
            int i = 0;

            while( true ) {

              long long fibNum = fibonacci( i );

              if( fibNum > n ) {

                break;
              }

              result.push_back( fibNum );

              i++;
            }

            return result;
      };

       private:
       unordered_map<int, long long> memo;

       long long fibonacci(int n) {

             if(n <= 1) {

               return n;
             }

             if( memo.find(n) != memo.end() ) return  memo[ n ];

             long long result = fibonacci(n-1) + fibonacci(n-2);

             memo[ n ] = result;

             return result;

       }
};

int main(int argc, char const *argv[]) {

  Fibonacci fib;
  int n;


  cout<<"Introduceti un N = ";
  cin>>n;

  if(n < 0) {
    cout<<"n trebuie sa fie pozitiv!";
    return 1;
  }

  vector<long long> result = fib.getFibonacci( n );
  cout<<"Termenii Fibonacci pana la "<<n<<" sunt: ";

  //iteram prin vectorul result
  for(long long term : result) {
      cout<<term<<" ";
  }

  cout<<endl;

  return 0;
}

/*
          fib(10) = fib(9) +   fib(8)

             fib(8)   +   fib(7)  fib(7) + fib(6)
        fib(7) fib(6)
*/
