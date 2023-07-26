#include <bits/stdc++.h>

using namespace std;

int distict(int nr) {

    int n2,last_digit;

    n2 = 0;

    int num = 0;

    while(nr > 9 && num == 0) {

      last_digit = nr % 10;

      num = nr / 10;

      while(num && num%10 != last_digit) {

            num/=10;
      }

      nr/=10;
    }

    return num;
}

int main(int argc, char const *argv[]) {

  int nr = atoi(argv[1]);

  if(!distict(nr)) cout<<"Distinct Digits!";

      else
                   cout<<"No Distinct Digits!";

  return 0;
}
