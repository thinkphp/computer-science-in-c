#include <iostream>
#include <cstring>
using namespace std;
class Book {

      private:
      char *title;

      public:
      //constructorul clasei
      Book(const char*t) {
        title = new char[strlen(t)+1];
        strcpy(title, t);
      }

      //constructor de copiere
      Book(const Book& c) {
        title = new char[strlen(c.title) + 1];
        strcpy(title, c.title);
        cout<<"Apel constructor de copiere.\n";
      }

      ~Book() {
        cout<<"Apel destructor clasei\n";
        delete [] title;
      }

      void display_title() {
          cout<<"title: "<<title<<endl;
      }

};

int main(int argc, char const *argv[]) {

  Book book1("C++ pentru avansati. Constructorul de copiere.");
  Book book2 = book1;

  book1.display_title();
  book2.display_title();
  return 0;
}
/*
Fara constructorul de copiere definit de utilizator C++ va genera un constructor implicit
care ar copia doar adresa pointerului
Constructorul de copiere manual definit realizeaza o copiere profunda (deep copy) alocand memorie
noua si copiaza continutul ,prevenind erori de memorie.

- daca nu definesti unul explicit, compilatorul genereaza automat unul shallow copy
*/
