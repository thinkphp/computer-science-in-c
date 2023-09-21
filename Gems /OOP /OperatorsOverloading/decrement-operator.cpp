#include <iostream>
#include <cstring>
class Sir {
    char buffer[100];
    int len;
    public:
    Sir(char *s) {
      strcpy(buffer, s);
      len = strlen(s);
    }
    Sir operator--() {
        buffer[len-1] = NULL;
        len--;
        return *this;
    }
    Sir operator--(int x) {
      buffer[len-1] = NULL;
      len--;
      return *this;
    }
    void show() {
      std::cout<<buffer<<std::endl;
    }
};

int main(int argc, char const *argv[]) {
  Sir title("C/C++ Programming Language");
  title.show();
  --title;
  title.show();
  title--;
  title.show();
  return 0;
}
