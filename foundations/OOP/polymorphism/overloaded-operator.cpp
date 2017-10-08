/**
 *  In c++ polymorphism is mainly divided into two types:
 *                      - compile time polymorphism (this type is achieved by function overloading and operator overloading)
 *                      - runtime polymorphism (this type is achieved by function overriding => when a derived class has a definition for one of the member function of the base class)
 */
#include <iostream>

using namespace std;

class Complex {

      private:
      int real, //real
          imag; //imaginary

      public:
      Complex(){};
      Complex(int _re, int _im):real(_re), imag(_im){};

      Complex operator + (Complex const &obj) {

              Complex res;
              res.real = real + obj.real; 
              res.imag = imag + obj.imag; 

              return res;
      };

      void print() {
           cout<<real<<" + i"<<imag<<endl; 
      };
};

int main( void ) {
    Complex c1(10,5),
            c2(10,10);
    c1.print();  
    c2.print();
    Complex r;
    r = c1 + c2;
    r.print(); 
 return(0);
};