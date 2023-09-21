#include <iostream>
#include <string.h>

using namespace std;

class Sir {
   private:
   char buffer[256];
   int len;
   public:
   Sir(char *s) {
      strcpy(buffer,s);
      len = strlen(buffer);
   }
   Sir operator++() {
       strcat(buffer, "X");
       len++;
       return *this;
   }
   Sir operator++(int x) {
     strcat(buffer, "X");
     len++;
     return *this;
   }
   friend ostream& operator<<(ostream &out, Sir&o);
};

ostream& operator<<(ostream &out, Sir&o) {
       out<<o.buffer<<"\n";
       return out;
}

int main(int argc, char const *argv[]) {
  Sir title("C/C++ Programming Language");
  ++title;
  cout<<title;
  title++;
  cout<<title;
  title++;
  cout<<title;
  return 0;
}
