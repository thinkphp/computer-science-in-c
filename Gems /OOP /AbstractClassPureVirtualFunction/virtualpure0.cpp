/*
- un program care ilustreaza o clasa abstracta cu o functie virtuala pura
*/
#include <iostream>

using namespace std;

//orice clasa derivata care mosteneste clasa de baza va fi obligat sa implementeze
//toate functiile virtuale pure
class Base {

       private:
       int x;

       public:
         //functie virtuala pura
         virtual void euclid() = 0;
         virtual void fn2() = 0;
         virtual void fn3() = 0;
         virtual void fn4() = 0;
         int get() {
           return x;
         }
};

class Derived: public Base {

       int y;
        public:
        void euclid() {
              int a = 10,b =3;
              while(b) {
                int r = a % b;
                a = b;
                b = r;
              }
              cout<<"euclid(10,3) = "<<a;
        }

        void fn2() {
          //code goes here
        }
        void fn3() {
          //code goes here
        }
        void fn4() {
          //code goes here
        }


};
int main(int argc, char const *argv[]) {

  Derived ob;
  ob.euclid();
  return 0;
}
