#include <iostream>
#include <math.h>

using namespace std;

class Complex {

      public:
      float real,
            imag;

      Complex();
      Complex(float v1, float v2);
      float modul();
      Complex operator+(Complex z);
      Complex operator-(Complex z);
      Complex operator*(Complex z);
      Complex operator/(Complex z);
};

Complex::Complex() {
    real = 0;
    imag = 0;
}

Complex::Complex(float v1, float v2) {
       real = v1;
       imag = v2;
}

float Complex::modul() {

      return sqrt(real * real + imag * imag);
}

Complex Complex::operator+(Complex z) {

    Complex t;

    t.real = real + z.real;

    t.imag = imag + z.imag;

    return t;
}

Complex Complex::operator-(Complex z) {

    Complex t;

    t.real = real - z.real;

    t.imag = imag - z.imag;

    return t;
}


Complex Complex::operator*(Complex z) {

    Complex t;

    t.real = (real + z.real) - imag * z.imag;

//x2y1
    t.imag = (real * z.imag) + z.real*imag;

    return t;
}

Complex Complex::operator/(Complex z) {


      Complex t;

      float m = z.modul();

      t.real = (real*z.real + imag*z.imag) / (m^2);

      t.imag = (z.real*img - real*z.imag) / (m^2);


  }    return t;
}



int main(int argc, char const *argv[]) {
  int n;
  Complex z1,
          z2,
          z3,
          z4;
  //citim primul numar complex
  cin>>z1.real>>z1.imag;
  //citim al doilea numar compelx
  cin>>z2.real>>z2.imag;

  //(z1/z2)^n
  cin>>n;

   //z1(real, imag) (z2.real, z2.imag)
  z3 = z1/z2;

  for(int i = 1; i <= n; ++i) {

       z4 = z4 * z3;
  }

   //x1 = partea reala
   //y1 = partea imaginara
  //z1 = x1 + i y1
  //z2 = x2 + i y2
  //z1 + z2 = (x1 + x2) + i (y1 + y2);

  return 0;
}

/*
z1 * z2 = (x1+iy1) (x2+iy2) = x1x2 - y1y2 + i(x1y2 + x2y1);

          (x1 + iy1) (x2-iy2)    (x1x2 + y2y2) + i(x2y1 - x1y2)
z1 / z2 = =================== = ===============================
          (x2 + iy2) (x2-iy2)      x2^2 + y2^2
*/
