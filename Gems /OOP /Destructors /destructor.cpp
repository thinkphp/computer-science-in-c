#include <iostream>

class Fractie {

      public:
      int nr, num;
      Fractie() {
        std::cout<<"Constructor of the class! Without params"<<std::endl;
      }
      Fractie(int a, int b) {
        std::cout<<"Constructor of the base class! with 2 params"<<std::endl;
        nr = a;
        num = b;
      }
      ~Fractie() {
        std::cout<<"Destructor of the class!"<<std::endl;
      }
};

class FractieDerivate: public Fractie {
      public:
      FractieDerivate(int a, int b) {
      std::cout<<"Constructor Derivate of the class! with 2 params"<<std::endl;
       nr = a;
       num = b;
      }
      ~FractieDerivate() {
        std::cout<<"Destructor Derivate of the class!"<<std::endl;
      }
};

int main(int argc, char const *argv[]) {

  FractieDerivate F(7,8);

  return 0;
}
