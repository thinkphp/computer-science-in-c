#include <stdio.h>

class Developer {
      protected:
        int hours;
      public:
      Developer(int h) {
        hours = h;
      }
      virtual int salary() {
        return 2 * hours;
      }
};

class Programmer: public Developer {
      public:
      Programmer(int h): Developer(h){}
      int salary(){return 3 * hours;}
};

class Engineer: public Programmer {
      public:
      Engineer(int h):Programmer(h){}

      int salary(){return 5*hours;}
};

int main(int argc, char const *argv[]) {

  Developer *p;

  p = new Engineer(5);
  printf("%d\n", p->salary());
  return 0;
}
