#include <iostream>
#include <cstring>

using namespace std;

class MyString {

      private:
      char *data;

      public:
      //constructorul clasei
      MyString(const char *s = "") {
           data = new char[strlen(s)+1];
           strcpy(data, s);
           cout<<"Constructorul apelat: "<<data<<endl;
      }

      //constructorul de copiere
      MyString(const MyString&other) {
          data = new char[strlen(other.data)+1];
          strcpy(data, other.data);
          cout<<"Construcotul de copiere apelat: "<<data;
      }

     MyString& operator=(const MyString& other) {

             if(this != &other) {
                    delete [] data;
                    data = new char[strlen(other.data) + 1];
                    strcpy(data, other.data);
                    cout<<"Operatorul = supraincarcat apelat: "<<data<<endl;
             } else {
               cout<<"Auto-atribuire detectata!"<<endl;
             }

             return *this;
     }


      //display
      void afiseaza() const{
         cout<<data<<endl;
      }

      //destructorul clasei
      ~MyString() {
        cout<<"Destructorul apelat: "<<data<<endl;
        delete[] data;
      }

};

int main(int argc, char const *argv[]) {

  MyString a("John");
  MyString b("Resig");
  MyString c;
  //MyString c = a;
  a.afiseaza();
  b.afiseaza();

  //supraincarcarea operatorilor =
  c = a;
  c.afiseaza();

  return 0;
}
