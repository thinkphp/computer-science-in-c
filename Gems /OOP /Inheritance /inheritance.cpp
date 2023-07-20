/*
 Object Oriented Programming OOP 
 - Inheritance
 */
#include <bits/stdc++.h>

using namespace std;

class Base {

    protected: 
      int nr;
      int num;
      
      int getNumarator() {
          return nr;
      }

      int getNumitor() {
          return num;
      }
};

class Derivate: public Base {

      public:
      void read() {
           cout<<"Numarator=";
           cin>>nr;
           cout<<"Numitor=";
           cin>>num; 
      }

      void display() {
           cout<<"Fraction f = "<<getNumarator()<<"/"<<getNumitor()<<"\n";
      }
};

int main() {

    Derivate f;

    f.read();
    f.display();

    return( 0 );
};
