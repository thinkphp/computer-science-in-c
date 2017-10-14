#include <iostream>

using namespace std;

//abstract base class
class Polygon {

      protected:
      int width, height;
      public:
      void setValues(int a, int b) {
          width = a;
          height = b;
      } 
      virtual int area(void) = 0; 

      void printarea() {

         cout<<this->area()<<'\n'; 
      }
};



//notice that area has no definition; this has been replaced by = 0, which makes it a pure virtual function
//Classes that contain at least one pure virtual function are known as abstract base classes.
//abstract base classes cannot be used to declare objects like:
//Polygon mypolygon.

//But an abstract base class is not totally useless. It can be used to create pointers to it and take advantages of all its polymorphic abilities. For example:
//the following pointer declarations would be valid:
//Polygon *polygon1;
//Polygon *polygon2;


//And can actually be dereferenced when pointing to objects of derived(non-abstract) classes. Here is the entire example:

class Rectangle: public Polygon {
  public:
    int area (void)
      { return (width * height); }
};

class Triangle: public Polygon {
  public:
    int area (void)
      { return (width * height / 2); }
};


int main() {

  Rectangle rect;
  Triangle trgl;
  Polygon * poly1 = &rect;
  Polygon * poly2 = &trgl;
  poly1->setValues(5,7);
  poly2->setValues(5,7);
  poly1->printarea();
  poly2->printarea();


 return(0);
};

/**
 *  Abstract base Classes
 *  Abstract Base classes are something very similar to the Polygon class in the previous example.
 *  
 *  They are classes than can only used as base classes, and thus are allowed to have virtual member functions without definition (known as pure virtual functions).
 *  The syntax is to to replace their definition by =0(an equal sign and a zero).
 *
 */

