#include <iostream>
using namespace std;
class Test {
      private:
      int* data;
      public:
      Test(int value) {
           data = new int(value);
           cout<<"Constructorul normal: "<< *data<<endl;
      };

      Test(const Test& other) {
        data = new int(*other.data);
        cout<<"Constructorul de copiere: "<<*data<<endl;
      }

      Test& operator=(const Test&other) {
          if(this!=&other) {
            delete data;
            data = new int(*other.data);
            cout<<"Operator = apelat: "<<*data<<endl;
          }
          return *this;
      }

      ~Test() {
        cout<<"Destructorul clasei: "<<*data<<endl;
        delete data;
      }
};
int main(int argc, char const *argv[]) {

  Test a(-10);//constructorul clasei
  Test b = a; //constructorul de copiere
  Test c(30); //construcoturl clasei
  c = a;//operator de atribuire supraincarcat

  return 0;
}
