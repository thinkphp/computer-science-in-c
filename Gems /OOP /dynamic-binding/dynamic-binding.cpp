#include <iostream>
/*
Consider the following code, where we have a base class B, and a derived class D.
Base class B has a virtual function f(), which is overridden by a function
in the derived class D, i.e., D::f() overrides B::f().

Now consider lines 30-34, where the decision as to which class’s
function will be invoked depends on the dynamic type of the object
pointed to by basePtr. This information can only be available at the
runtime, and hence f() is subject to the dynamic binding.
*/

class A {
      public:
      A() {
        std::cout<<"The constructor of the base class is called.\n";
      }
      virtual void f() {
        std::cout<<"The base class function is called.\n";
      }
      ~A() {
        std::cout<<"The destructor of the base class is called.\n";
      }
};

class D: public A {

         public:
         D() {
          std::cout<<"The constructor of the class D is called.\n";
         }
         void f() {
            std::cout<<"The Derived Class function is called.\n";
         }
         ~D() {
            std::cout<<"The destructor of the class D is called.\n";
        }
};

int main(int argc, char const *argv[]) {
  A base;
  D derived;
  A *basePtr = &base;
  basePtr->f();
  basePtr = &derived;
  basePtr->f();
  base.f();
  derived.f();
  return 0;
}
