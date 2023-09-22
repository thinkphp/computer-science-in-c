#include <iostream>

using namespace std;

class Fractie {
      public:
      Fractie(){nr = 1; num = 1; }
      Fractie(int nr, int num) {
        this->nr = nr;
        this->num = num;
      }
      Fractie& operator++(int x) {
         nr++;
         num++;
         return *this;
      }
      Fractie& operator++() {
        nr++;
        num++;
        return *this;
      }
      void display() {
        cout<<nr<<"/"<<num<<endl;
      }
      friend ostream& operator<<(ostream&out, Fractie&f);
      private:
      int nr,
          num;
};

ostream& operator<<(ostream&out, Fractie&f) {
  out<<f.nr<<"/"<<f.num<<endl;
  return out;
}

int main(int argc, char const *argv[]) {

  Fractie F(1,2);
  for (size_t i = 0; i < 10; i++) {
    cout<<F;
    F++;
  }
  return 0;
}
