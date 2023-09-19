#include <iostream>
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
    return 0;
}
