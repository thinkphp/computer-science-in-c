#include <bits/stdc++.h>

using namespace std;

class Fraction {

     public:
     int nr;
     int num;

     Fraction(int a, int b) {         
         nr = a;
         num = b;
     }

     int numarator() {
         return nr;         
     }

     int numitor() {
         return num;
     }

     void display() {
         cout<<numarator()<<"/"<<numitor();
     }

     friend void multiply(int n, Fraction &f);

};

void multiply(int n, Fraction &f) {
     f.nr = f.nr * n;
}

int main() {
    Fraction f(3,4);
    multiply(3,f);
    f.display();  
}     
