#include <bits/stdc++.h>

using namespace std;

class Base {

        protected:
        int nr,
            num;
        int numarator() {
            return nr;
        }
        int numitor() {
           return num;
        }
};


class Derivate: public Base {

       public:

         void read() {
              cout<<"Num = ";
              cin>>nr;
              cout<<"Numitor = ";
              cin>>num;
         }

         void display() {
              cout<<numarator()<<"/"<<numitor();
         }

};


int main(int argc, char const *argv[]) {

  Derivate f;
  f.read();
  f.display();

  return 0;
}
