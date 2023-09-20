#include <iostream>

class Shape {
      public:
      virtual double area()=0;
      virtual void print()=0;
};

class Rectangle: public Shape {
      double length, width;
      public:
      Rectangle(double l, double w) {
        length = l;
        width = w;
      }
      void print() {
        printf("Rectangle(length = %lf, width = %.2lf)", length, width);
      }
      double area() {
        return length * width;
      }
};

class Triangle: public Shape {
      private:
        int base, height;
      public:
      Triangle(int b, int h) {
          base = b;
          height = h;
      };
      double area() {
        return base * height * 0.5;
      }
      void print() {
        printf("Triangle(%d,%d)",base,height);
      }
};

class Circle: public Shape {
      private:
      double radius;
      public:
        Circle(double r) {
          radius = r;
        }
      double area() {
        return 3.14*radius*radius;
      };
      void print() {
        printf("Circle(r = %.3lf)",radius);
      };
};

int main(int argc, char const *argv[]) {
  Shape *p = new Triangle(4,8),
        *c = new Circle(10),
        *r = new Rectangle(7,8);
  p->print();
  std::cout<<"Area = "<<p->area()<<"\n";
  c->print();
  std::cout<<"Area = "<<c->area()<<"\n";
  r->print();
  std::cout<<"Area = "<<r->area()<<"\n";
  return 0;
}
