#include <iostream>
#include <cstring>

using namespace std;

class String {

      private:
      char *data;
      public:
      String(const char *str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        cout<<"Constructorul clasei apelat."<<endl;
      }

      String(String&other) {
          data = new char(strlen(other.data)+1);
          strcpy(data,other.data);
          cout<<"Constructorul de copiere apelat.\n"<<endl;
      }

      friend ostream& operator<<(ostream& out, const String& str);

      void display() const {
           cout<<data<<endl;
      }

      String operator+(const String&other);

         // Operator de atribuire supraincarcat
         String& operator=(const String& other) {
             if (this != &other) { // Protecție împotriva auto-atribuției
                 delete[] data; // Eliberăm memoria existentă
                 data = new char[strlen(other.data) + 1];
                 strcpy(data, other.data);
                 cout << "Operator= apelat: " << data << endl;
             } else {
                 cout << "Auto-atribuire detectată.\n";
             }
             return *this; // Returnăm referința la obiectul curent
         }

      ~String() {
        //cout<<"Destructorul clasei apelat"<<endl;
        delete [] data;
      }
};

ostream& operator<<(ostream& out, const String&str) {
        out<<str.data;
        return out;
};

String String::operator+(const String&other) {

     size_t len = strlen(data) + strlen(other.data);

     char *tmp = new char[len+1];

     strcpy(tmp, data);

     strcat(tmp, other.data);

     String result(tmp);

     delete [] tmp;

     return result;
}

int main(int argc, char const *argv[]) {

  String str1("John"),
         str2("Resig");

  String str3 = str1;

  String str4;

  cout<<str1<<endl;
  cout<<str2<<endl;
  cout<<str3<<endl;

  //str1.display();
  //str2.display();

  str4 = str1 + str2;

  cout<<str4;

  return 0;
}
