#include <iostream>

using namespace std;
//
// clasa abstracta
//
class Base {
     //data member
     protected:
     int x;

     public:
     // constructorul clasei de baza
     Base(int parameter) {
       //x = 17
       x = parameter;
       cout<<"Called Constructorul clasei de baza\n";
     }
     //functie virtuala pura
     virtual void function() = 0;
     virtual void euclid() = 0;
     virtual void factorial() = 0;
};

//clasa derivata
class Derived: public Base {

      private:
      int y;

      public:
                                      //se apeleaza constructorul clasei de baza =>
                                      //se afla la linia 14

      //constructorul clasei derivate
      Derived(int first, int second) : Base( first ) {
         y = second;
      }

      void function() {
        cout<<"x = "<<x;
        cout<<endl;
        cout<<"y = "<<y;
      }

      void euclid() {
           int r;
           int copy_x = x, copy_y = y;
           while(copy_y) {
             r = copy_x % copy_y;
             copy_x = copy_y;
             copy_y = r;
           }
           cout<<"Euclid("<<x<<","<<y<<")="<<copy_x;
      }

      void factorial() {
           int p = 1;
           for(int i = 1; i <= y; ++i) {
              p = p * i;
           }
           cout<<"Factorial = "<<p;
      }
};

int main(int argc, char const *argv[]) {

  //avem 2 parametri de transmis
  //primul parametru este 17
  //al doilea parametru este 18
  //se apeleaza constructorul asociat clasei Derived
  //go to linia 30
  Derived d( 101, 5);
  d.function();
  cout<<"\n";
  d.euclid();
  cout<<"\n";
  d.factorial();

  //int *ptr = new int[100]
  //   1     ,2,3,4,5,6,7,8,9,10....100
  // ptr + 0                 ptr+9
  //ptr reprezinta adresa de inceput a vectorului
  //iar aritmetica este urmatoarea:
  // ptr + 1 este cel de-al doilea element
  // ptr + 2 este cel de-al treilea element
  // ptr  + 3 este cel de-al patrulea element
  //....

  Base *pointer = new Derived(100,50);
  //int, float, double, char, string => tipuri de date primitive
  //int *p = new int[1]

  pointer -> function();
  //pointer->ORICE_METODA()

 int *p;
 float b;
 int a;
 p = &a;
 //p = &b;//error: cannot convert ‘float*’ to ‘int*’ in assignment
 //p = new float[10];//cannot convert ‘float*’ to ‘int*’ in assignment
 //p = new int[10];//no error
 //se aloca spatiu in HEAP pentru 10 componente de tip integer
 //si adresa de inceput se stocheaza in pointerul p
 //pointerul p poate sa primeasca in atributul valoare numai adrese catre int
 //NU poate retine adrese catre FLOAT!!!!
 //     _     _ _ _ _ _
 //  p+0    p+1
 //
 //int p[100];//static SEGMENT program

 //HEAP
 //p = new int[ 1000 ];//dynamic

 //p[0] = 1;
 //p[1] = 2;
 //cout<<"Pointers:"<<endl;
 //cout<<*(p+0);
 //delete p

  return 0;
}
