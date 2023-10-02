#include <iostream>
/*
Consider the following code, where the sum() function is overloaded
to accept two and three integer arguments.
Even though there are two functions with the same name inside the
A class, the function call sum() binds to the correct function
depending on the parameters passed to those functions.
This binding is done statically during compile time.
*/
class A {
      public:
      A(){
        std::cout<<"Constructor caled."<<"\n";
      }

      int sum(int a, int b) {
          return a + b;
      }

      int sum(int a, int b, int c) {
          return a + b + c;
      }
      ~A(){
        std::cout<<"Destructor caled."<<"\n";
      }
};

int main(int argc, char const *argv[]) {
  A obj;
  std::cout<<"Sum is = "<<obj.sum(1,3)<<"\n";
  std::cout<<"Sum is = "<<obj.sum(1,3,5)<<"\n";
  return 0;
}
