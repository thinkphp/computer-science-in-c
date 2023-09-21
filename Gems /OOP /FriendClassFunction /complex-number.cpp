#include <iostream>

class Complex {

     public:
     //constructor of the class without parameter
     Complex(){}
     //constructor of the class with one parameter
     Complex(double r) {
       real = r;
       imag = 0;
     }
     //constructor of the class with two parameters
     Complex(double r, double i) {
       real = r;
       imag = i;
     }

     friend Complex operator+(double n, Complex&z);

     friend Complex operator+(Complex&z, double n);

     //operator + overloaded
     Complex operator+(Complex&z) {
       Complex sum;
       sum.real = real + z.real;
       sum.imag = imag + z.imag;
       return sum;
     }

     friend std::ostream& operator<<(std::ostream &out, Complex &z);

     void display() {
       printf("%.2lf + %.2lf i\n", real, imag);
     }

     private:
     double real,
            imag;
};

Complex operator+(double n, Complex&z) {
  Complex Z(z.real + n, z.imag + n);
  return Z;
}

Complex operator+(Complex&z, double n) {
  Complex Z(z.real + n, z.imag + n);
  return Z;
}

std::ostream& operator<<(std::ostream &out, Complex &z) {

     out<<z.real<<" + "<<z.imag<<" i\n";
     return out;
}

int main(int argc, char const *argv[]) {
  Complex z1(2,3),z2(3,4),z3;
  std::cout<<z1;
  z1.display();
  std::cout<<z2;
  z2.display();
  z3 = z1 + z2;
  z3.display();
  std::cout<<z3;
  Complex z4(5,7);
  z4 = 1 + z4;
  z4 = z4 + 3;
  std::cout<<z4;
  return 0;
}
