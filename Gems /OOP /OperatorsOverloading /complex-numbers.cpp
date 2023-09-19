#include <iostream>
float sqrt(float n) {
     float x = n, y = 1,
           e = 0.00001;
     while((x-y)>e) {
       x = (x+y)/2;
       y = n/x;
     }
     return x;
}
class Complex {
    private:
      float x,y;
    public:
      Complex();
      Complex(float x);
      Complex(float x, float y);
      Complex(Complex&);
      float module();
      Complex operator+(Complex&z1) {
          Complex s;
          s.x = z1.x + x;
          s.y = z1.y + y;
          return s;
      };
      void display() {
        std::cout<<x<<"+i"<<y<<"\n";
      }
};
float Complex::module() {
     return sqrt(x*x+y*y);
};
Complex::Complex() {
  x = 0;
  y = 1;
};
Complex::Complex(float v) {
  x = 0;
  y = v;
};
Complex::Complex(float a, float b) {
  x = a;
  y = b;
}
Complex::Complex(Complex&z) {
  x = z.x;
  y = z.y;
}
int main(int argc, char const *argv[]) {
  Complex z1(2,3),z2(5),z3,z4(7,8);
  z1.display();
  //z2.display();
  //z3 = z1;
  //z3.display();
  std::cout<<z1.module()<<"\n";
  z4.display();
  Complex sum = z1 + z4;
  sum.display();
  return 0;
}
