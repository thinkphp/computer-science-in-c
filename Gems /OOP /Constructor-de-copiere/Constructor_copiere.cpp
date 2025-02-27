#include <iostream>
#include <cstring>

//programare orietanta pe obiect
using namespace std;

class String {

     private:
     char *data;

     public:
     //constructorul clasei
     String(const char*s = "") {
       data = new char[strlen(s) + 1];
       strcpy(data, s);
       cout<<"Constructor apelat: "<<data<<endl;
     }

     //constructorul de copiere
     String(const String&other) {
       data = new char[strlen(other.data) + 1];
       strcpy(data, other.data);
       cout<<"Constructor de copiere apelat: "<<data<<endl;
     }

      //supraincarcare operator de atribuire =
     String& operator=(const String&other) {

          if(this!=&other) {
              delete []data; //eliberam memoria existenta
              data = new char[strlen(other.data) + 1];
              strcpy(data, other.data);
              cout<<"Operator= apelat: "<< data << endl;
          } else {
             cout<<"Auto-atribuire detectata";
          }

          return *this;//returnam o referinta a obiectului current
     }

     void afiseaza() {
          cout<<data<<endl;
     }

     //operator de atribuire supraincarcat
     ~String() {
       cout<<"Destructor apelat: "<< data << endl;
       delete [] data;
     }
};

int main(int argc, char const *argv[]) {

   String a("John");
   String b("Resig");
   String c = a;
   String d;
   d = b;//apelam operatorul = (copiere profunda)

   cout<<"String a: ";
   a.afiseaza();
   cout<<"String b: ";
   b.afiseaza();
   cout<<"String c: ";
   c.afiseaza();

   cout<<"String d: ";
   d.afiseaza();

   c = c;
   c.afiseaza();
  return 0;
}

/*
Constructorul de copiere in c++ este un constructor special utilizat pentru a initializa un obiect
nou ca o copie a unui obiect existent. copy valorile obiectului sursa in obiectul nou creat
*/
