/*
 Object Oriented Programming OOP 
 - Inheritance + polymorphism
 */
#include <bits/stdc++.h>

using namespace std;

class Base {

    public: 
      int nr;
      int num;
      
      virtual void getNumarator() {
           cout<<"Numarator = "<<nr;
      }

      virtual void getNumitor() {
           cout<<"Numitor = "<<num;
      }

      void read() {
           cout<<"Numarator=";
           cin>>nr;
           cout<<"Numitor=";
           cin>>num; 
      }

      void display() {
           getNumarator();
           cout<<endl;
           getNumitor();
      }
};

class Derivate: public Base {

      public:      
      void getNumarator() {
           cout<<"Apply Polymorphism. Numarator => "<<nr;
      }

      void getNumitor() {
           cout<<"Apply Polymorphism. Numitor => "<<num;
      }
};

int main() {

    Derivate f;

    f.read();
    f.display();

    return( 0 );
};
