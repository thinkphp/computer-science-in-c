/**
 *  In c++ polymorphism is mainly divided into two types:
 *                      - compile time polymorphism (this type is achieved by function overloading and operator overloading)
 *                      - runtime polymorphism (this type is achieved by function overiding => when a derived class has a definition for one of the member function of the base class)
 */
#include <iostream>

using namespace std;

class Parent {

      public:
      virtual void print() = 0;
};

class Child1: public Parent {

      public:
      void print() {
           cout<<"The child1 print method was called!"<<endl; 
      }

};


class Child2: public Parent {

      public:
      void print() {
           cout<<"The child2 print method was called!"; 
      }

};

int main( void ) {


    Child1 obj1; 
    Child2 obj2;

    //the method to be called is determined at runtime
    obj1.print();
    obj2.print();

 return(0);
};