#include <stdio.h>
/*
Programare orientata obiect:

Polimorfism in C++:

1 - Abilitatea de a aparea in mai multe forme.
2 - Abilitatea limbajelor de programare de a procesa obiectele
diferit in functie de tipul lor sau de clasa.
3 - Abilitatea limbajelor de programare de a redefini metode in clase derivate.

*/

//clasa de baza abstracta
class Shape {
public:
    virtual double area()=0;
    virtual void print()=0;
};

//clasa derivata
class Rectangle: public Shape {
      //date membre
      private:
      double height,width;
      public:
      //constructorul clasei
      Rectangle(double h, double w) {
        height = h;
        width = w;
      }

      void print() {
        printf("Rectangle => height = %.3lf; width = %.3lf\n", height, width);//%lf = long float
      }

      double area() {
        return height * width;
      }
};

class Triangle: public Shape {
      private:
      double base, height;
      public:
      Triangle(double b, double h) {
        base = b;
        height = h;
      }
      double area() {
        return base * height / 2;
      }
      void print() {
        printf("Triangle => base = %.3lf; height = %.3lf\n", base, height);
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
        return 3.14 * radius * radius;
      }
      void print() {
        printf("Cerc => R = %.3lf\n", radius);
      }
};

int main(int argc, char const *argv[]) {
  //Shape *p = new Triangle(2,3);
  Shape *r = new Rectangle(20,3),
        *c = new Circle(10),
        *t = new Triangle(20,50);
  r->print();
  printf("Aria = %.3lf\n", r->area());
  c->print();
  printf("Aria = %.3lf\n", c->area());
  t->print();
  printf("Aria = %.3lf\n", t->area());
  return 0;
