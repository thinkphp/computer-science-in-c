#include <iostream>

using namespace std;

//abstract base class
class Polygon {

      protected:
      int width, height;
      public:
      Polygon(int a, int b):width(a),height(b){}
      virtual int area(void) = 0; 
      void printarea() {
         cout<<this->area()<<'\n'; 
      }
};

class Rectangle: public Polygon {
  public:
    Rectangle(int a, int b):Polygon(a, b){}
    int area (void)
      { return (width * height); }
};

class Triangle: public Polygon {
  public:
    Triangle(int a, int b):Polygon(a, b){}
    int area (void)
      { return (width * height / 2); }
};


int main() {

  Polygon * poly1 = new Rectangle(5,7);
  Polygon * poly2 = new Triangle(5,7);
  poly1->printarea();
  poly2->printarea();


 return(0);
};

