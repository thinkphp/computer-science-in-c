#include <iostream>

class MyData {

      int data;

      public:
      //constructorul clasei
      MyData(int info): data(info) {}

      friend std::ostream& operator<<(std::ostream &output, const MyData &obj) {
          
             output<<obj.data;
             return output;
      }

      friend std::istream& operator>>(std::istream &input, MyData &obj) {

             input>>obj.data;
             return input;
      }

};

int main(int argc, char const *argv[]) {

  MyData obj( 10 );

  std::cout<<"Obiectul este: "<<obj<<std::endl;

  std::cout<<"Introduceti o valoare pentru obiect: ";
  std::cin>>obj;

  std::cout<<"Obiectul actualizat este: "<<obj<<"\n";

  return 0;
}
