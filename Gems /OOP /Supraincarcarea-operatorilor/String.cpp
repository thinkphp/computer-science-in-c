#include <iostream>
#include <cstring>
using namespace std;
 
class String {
private:
    char* data;
 
public:
    // Constructor
    String(const char* s = "") {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
        cout << "Constructor apelat: " << data << endl;
    }
 
    // Constructor de copiere
    String(const String& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Constructor de copiere apelat: " << data << endl;
    }
 
    // Operator de atribuire supraincarcat
    String& operator=(const String& other) {
        if (this != &other) {  // ✅ Protecție împotriva auto-atribuției
            delete[] data;     // ✅ Eliberăm memoria existentă
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
            cout << "Operator= apelat: " << data << endl;
        } else {
            cout << "Auto-atribuire detectată.\n";
        }
        return *this;  // ✅ Returnăm referința la obiectul curent
    }
 
    // Destructor
    ~String() {
        cout << "Destructor apelat: " << data << endl;
        delete[] data;
    }
 
    // Afișare
    void afiseaza() const {
        cout << data << endl;
    }
};
 
int main() {
    String a("john");
    String b("resig");
    String c;
 
    c = b;    // Apelăm operatorul= (copiere profundă)
    c.afiseaza();
 
    c = a;    // Apelăm din nou operatorul=
    c.afiseaza();
 
    c = c;    // Testăm auto-atribuirea
    c.afiseaza();
 
    return 0;
}
