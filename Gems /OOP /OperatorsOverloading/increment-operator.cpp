#include <iostream>

using namespace std;

class Intreg {
   private:
   int n;
   public:
   Intreg(int a) {
     n = a;
   }
   Intreg operator++() {
     n++;
     return *this;
   }
   Intreg operator++(int x) {
     n++;
     return *this;
   }
   friend ostream& operator<<(ostream &out, Intreg&o);

};

ostream& operator<<(ostream &out, Intreg&o) {
       out<<o.n;
       return out;
}

int main(int argc, char const *argv[]) {
  Intreg ob(5);
  cout<<ob;
  ++ob;
  cout<<ob;
  ob++;
  cout<<ob;
  return 0;
}
