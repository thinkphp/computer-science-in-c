#include <iostream>

using namespace std;

class Polygon {

      protected:
      int width, height;
      public:
      void setValues(int a, int b) {
          width = a;
          height = b;
      } 

/* 
 *  A virtual member is a member function that can be redefined in a derived class. The syntax for a function to become virtual is to precede its declaration with the virtual keyword: virtual
 */
     virtual int area() {
          return 0;
      }

//the member function area has been declared as virtual in the base class because it is later redefined in each of derived class.

//Non-virtual members can be redefined in derived class, but non-virtual members of derived classes cannot be accessed throught 
// reference of the base class,i.e. if virtual is removed from the declaration of area in this example, all three calls of area
// return zero, because in all cases, the version of the base class would have been called instead.
};

class Triangle: public Polygon {

      public:
      int getArea() {
           return width*height/2; 
      }   

      int area() {
           return width*height/2; 
      }   

};

class Rectangle: public Polygon {

      public:
      int getArea() {
           return width*height; 
      }   
      int area() {
           return width*height; 
      }   
};

//function main declares two pointers to Polygon(named poly1 and poly2). These are assigned the addresses of react and trig,
//respectively, which are objects of type Rectangle and Triangle. Such assignments are valid, since both Rectangle and Triangle
//are classes derived from Polygon.
//Deferencing poly1 and poly2 (with *poly1 and *poly2) is valid and allows us to access the members of their pointed objects. For
//example, the following two statements would be equivalent in the provious example:
// poly->setValues(5,9) <=>rect.setValues(5,9)


int main() {

    Rectangle rect; 
    Triangle trig;
    Polygon poly;

    Polygon *poly1 = &rect; 
    Polygon *poly2 = &trig; 
    Polygon *poly3 = &poly; 

    poly1->setValues(5,9);
    poly2->setValues(5,9);

    cout<<rect.getArea()<<endl;
    cout<<trig.getArea()<<endl;


    cout<<poly1->area()<<endl;
    cout<<poly2->area()<<endl;
    cout<<poly3->area()<<endl;


 return(0);
};

//Before getting any deeper into this chapter, you should have a proper understanding of pointers and class inheritance.
//Pointers to base class. 
//One of the key features of class inheritance is that a pointer to a derived class is type-compatible with a pointer to
//its base class. Polymorphism is the art of taking advantage os this simple but powerful and versatile feature.
//The example about the rectangle and triangle classes can be rewriten using pointers taking this feature into account.