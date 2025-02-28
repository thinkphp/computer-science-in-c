#include <iostream>
#include <cstring>

using namespace std;

class Book {

      private:
      char *title;

      public:
      //constructor clasei
      Book(const char *t) {
          title = new char[strlen(t) + 1];
          strcpy(title, t);
      }

      Book(const Book&b) {
          title = new char[strlen(b.title) + 1];
          strcpy(title, b.title);
          cout<<"Apel constructorul de copiere (deep copy)\n";
      }

      void afiseaza() {
        cout<<"Title = "<< title<< endl;
      }


      ~Book() {
        delete [] title;
      }
};

int main(int argc, char const *argv[]) {

  Book book1("C++ pentru avansati");
  Book book2 = book1;
  //Book book3;

  book1.afiseaza();
  book2.afiseaza();

///
//book3 = book1;

  //output: C++ pentru avansati
  //        C++ pentru avansati

  return 0;
}
