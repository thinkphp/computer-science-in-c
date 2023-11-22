/*
Polimorfism:
1. abilitatea de a aparea in mai multe forme.
2. abilitatea limbajului de programare de a procesa obiecte diferite in functie de tipul si clasa
3. abilitatea de a redefini metode in clase derivate.
*/
#include <iostream>

using namespace std;

//clasa de baza
class Base {

   public:
   int nr,
       num;
   //constructor
   //Base(int nr, int num) {
   //}

   virtual void getNumarator() {
        cout<<"Numarator ->>>>"<<nr;
   };

   virtual void getNumitor() {
        cout<<"Numitor ->>>>"<<num;
   }

   void read() {
        cout<<"numarator = ";
        cin>>nr;
        cout<<"numitor = ";
        cin>>num;
   }

   void display() {
        getNumarator();
        cout<<endl;
        getNumitor();
   }

};

//clasa derivata
class Derived: public Base {

      private:
      int a, b;
      public:
      Derived(int a, int b) {
        this->a = a;
        this->b = b;
      }

      public:
        void getNumarator() {
               cout<<"Apply Polymorphism OOP : Numarator"<<nr<<" - "<<a;
          };

        void getNumitor() {
               cout<<"Apply Polymorphism OOP Numitor"<<num<<" - "<<b;
        }
};

int main(int argc, char const *argv[]) {

  Base alt_obiect;

  alt_obiect.read();
  alt_obiect.display();
  cout<<endl;
  Derived obiect(7,8);
  //am declarat un obiect de tip Derivate (clasa derivata)
  obiect.read();
  obiect.display();

  return 0;
}
