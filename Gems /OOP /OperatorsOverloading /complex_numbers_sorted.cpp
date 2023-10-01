#include <iostream>
class Complex {
      public:
      Complex(){real = 0; imag = 0;}
      Complex(double real, double imag) {this->real = real; this->imag = imag;}
      double sqr(double x){
        return x*x;
      }

      void set(double r, double i);

      double sqrt(double n){
        double x = n, y = 1, e = 0.00001;
               while(x-y>e) {
                   x = (x+y)/2;
                   y = n/x;
               }
               return x;
      }
      double module() {
        return sqrt(sqr(real) + sqr(imag));
      }
      void display();
      friend double module2(Complex&z);
      friend std::istream& operator>>(std::istream&stream,Complex&z);
      friend std::ostream& operator<<(std::ostream&stream,const Complex&z);
      friend Complex operator+(Complex&z, float x);
      friend Complex operator+(float x,Complex&z);

      private:
      double real,imag;

};

void Complex::set(double r, double i) {
     real = r;
     imag = i;
}
void Complex::display() {
     std::cout<<real;
     if(imag>0)std::cout<<"+";
     std::cout<<imag<<"i";
     std::cout<<"\n";
}

std::istream& operator >>(std::istream&stream,Complex&z) {
  std::cout<<"real=";
  stream>>z.real;
  std::cout<<"imag=";
  stream>>z.imag;
  return stream;
}


std::ostream& operator <<(std::ostream&stream,const Complex&z) {
  std::cout<<z.real;
  if(z.imag>0) std::cout<<"+";
  std::cout<<z.imag<<"i";
  return stream;
}

Complex operator+(Complex&z, float x) {
        return Complex(x+z.real, z.imag);
}

Complex operator+(float x,Complex&z) {
        return Complex(x+z.real, z.imag);
}

double module2(Complex&z){
    return z.sqrt(z.sqr(z.real) + z.sqr(z.imag));
}

void bubblesort(Complex *p, int n) {
     int finished = 0,
         swapped;
         while(!finished) {
           swapped = 0;
           for(int i = 0; i < n-1; ++i) {
               if(p[i].module() < p[i+1].module()) {
                  Complex aux = p[i];
                          p[i] = p[i+1];
                          p[i+1] = aux;
                          swapped = 1;
               }
           }
           if(swapped==1) n--;
              else
                       finished =1;
         }
}

int main(int argc, char const *argv[]) {
  Complex arr[100];
  int n;
  double real, imag;
  std::cout<<"How many complex numbers? N=";
  std::cin>>n;
  for(int i = 0; i < n; ++i) {
      std::cin>>real>>imag;
      arr[i].set(real, imag);
  }
  for(int i = 0; i < n; ++i) {
      arr[i].display();
      std::cout<<"Module = "<<module2(arr[i])<<"\n";
  }
  Complex z(4,5),zcopy;
  zcopy = z;
  zcopy.display();
  std::cout<<z.module()<<"\n";
  std::cout<<module2(z);
  std::cout<<"\n";
  bubblesort(arr,n);
  std::cout<<"Sorted:"<<"\n";
  for(int i = 0; i < n; ++i) arr[i].display();
  Complex complex_number, complex_number2;
  std::cin>>complex_number>>complex_number2;
  std::cout<<1+complex_number<<"\n"<<complex_number2+2;
  return 0;
}
