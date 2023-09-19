#include <iostream>

class Fractie {
   int nr, num;
   public:
   //constructors of the class
   Fractie() { }
   Fractie(int nr, int num) {
     this->nr = nr;
     this->num = num;
   }
   //operators overload
   Fractie operator+(Fractie&fr) {
     Fractie f;
     f.nr = nr * fr.num + fr.nr * num;
     f.num = fr.num * num;
     return f;
   }
   Fractie& increment() {
     nr = nr + 1;
     num = num + 1;
     return *this;
   }

   Fractie& display() {

     std::cout<<"\n"<<nr<<"/"<<num;
     return *this;
   }
};

class Euclid {
     int a, b;
     public:
     Euclid(int a, int b) {
       this->a = a;
       this->b = b;
     }
     int run() {
       while(b) {
         int r = a % b;
         a = b;
         b = r;
       }
       return a;
     }
};

class Number {
    public:
    int n;
    Number(int n) {
      this->n = n;
    }
    Number& increment() {
      n++;
      return *this;
    }
    Number& display() {
      std::cout<<n;
      return *this;
    }
};

int main(int argc, char const *argv[]) {
  Number N(10);
  N.display().increment().increment().display();
  Euclid ob(10,4);
  std::cout<<std::endl;
  std::cout<<ob.run();
  Fractie f1(1,2);
  Fractie f2(5,7);
  std::cout<<std::endl;
  f1.display();
  std::cout<<std::endl;
  f2.display();
  Fractie fsum;
  fsum = f1 + f2;
  std::cout<<std::endl;
  fsum.display().increment().display();
  return 0;
}
