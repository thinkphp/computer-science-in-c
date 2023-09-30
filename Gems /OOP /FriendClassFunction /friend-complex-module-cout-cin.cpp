#include <iostream>

using namespace std;

double sqrt(double n) {
       double x = n, y = 1, e = 0.00001;
       while(x-y>e) {
         x = (x+y)/2;
         y = n/x;
       }
       return x;
}

class Complex {
    public:
      //constructor of the class without parameters
      Complex();
      //constructor of the class with two parameters
      Complex(float,float);
      void display();
      friend double module(Complex&);
      Complex operator+(Complex&);
      friend Complex operator+(float,Complex&);
      friend Complex operator+(Complex&, float);
      friend ostream& operator<<(ostream&,const Complex&);
      friend istream& operator>>(istream&, Complex&);
    private:
    float real,
          imag;

};

Complex::Complex() {
  real = 1;
  imag = 0;
}

Complex::Complex(float pr, float pi){
  real = pr;
  imag = pi;
}

Complex operator+(float x,Complex&c) {
    Complex z(x+c.real, c.imag);
    return z;
}

Complex operator+(Complex&c, float x) {
    Complex z(x+c.real, c.imag);
    return z;
}

void Complex::display(){
  cout<<real;
  if(imag>0) cout<<" + ";
  cout<<imag<<" i"<<"\n";
}

double module(Complex&z) {
        return sqrt(z.real*z.real + z.imag*z.imag);
}

ostream& operator<<(ostream&stream,const Complex&z) {

  stream<<z.real;
  if(z.imag>0) stream<<" + ";
  stream<<z.imag<<" i"<<"\n";

    return stream;
}

istream& operator>>(istream&stream, Complex&c) {
         cout<<"real=";
         stream>>c.real;
         cout<<"imag=";
         stream>>c.imag;
         return stream;
}

Complex Complex::operator+(Complex&z) {
    Complex c;
    c.real = real + z.real;
    c.imag = imag + z.imag;
    return c;
}

int main(int argc, char const *argv[]) {
  Complex z(4,5),z1;
  cin>>z1;
  cout<<z1;
  z.display();
  cout<<z;
  z = 1 + z;
  z.display();
  z = z + 3;
  z.display();
  cout<<module(z)<<"\n";
  Complex sum;
  sum = z1 + z;
  cout<<z1 + z<<sum;
  return 0;
}
