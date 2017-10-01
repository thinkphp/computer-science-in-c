#include <iostream>

using namespace std;

class Base {

      public:
      void which() {
           test();
      } 
      virtual void test() {
           cout<<"Base Class"<<endl; 
      }  
};

class D: public Base {

      void test() {
           cout<<"Derivate Method"; 
      }  
};

int main( void ) {

    Base x;
    D y; 
    x.which();
    y.which();

 return(0);
};