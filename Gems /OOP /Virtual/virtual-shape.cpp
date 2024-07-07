#include <iostream>

using namespace std;

class Forma {

     public:
     virtual double getArea() const {
              //poate sa fie si goala
              return 0.0;
     }
};


class Dreptunghi : public Forma {

      public:
      Dreptunghi(double width, double height): width_(width), height_(height){}

      double getArea() const override {
        return width_ * height_;
      }

      private:
      double width_,
             height_;
};

class Patrat: public Forma {

      public:
      Patrat(double side): side_(side){}

      double getArea() const override{
        return side_ * side_;
      }

      private:
      double side_;
};

class Cerc: public Forma {

      public:
      Cerc(double r): r_(r) {}
      double getArea() const override {
        return 3.14 * r_ * r_;
      }
      private:
      double r_;

};

int main(int argc, char const *argv[]) {

  Forma *shape1 = new Dreptunghi(2.8, 7.5);
  Forma *shape2 = new Patrat(2.8);
  Forma *shape3 = new Cerc(5);

  cout<<"Aria Dreptunghi = "<<shape1->getArea()<<endl;
  cout<<"Aria Patrat = "<<shape2->getArea()<<endl;
  cout<<"Aria Cerc = "<<shape3->getArea()<<endl;


  //clean up memory
  delete shape1;
  delete shape2;

  return 0;
}
