#include <iostream>
#include <string.h>
using namespace std;
template <class T>
void my_swap(T &a, T &b) {
     T aux;
     aux = a;
     a = b;
     b = aux;
}

template <class T>
void my_swap2(T *a, T *b) {
     T aux;
     aux = *a;
     *a = *b;
     *b = aux;
}

int main(int argc, char const *argv[]) {
  //int    a = 12,
    //     b = 45;

  //float    a = 12.42,
           //b = 45.72;

  //double a = 12.123,
         //b = 45.65;

    //char     a = 'x',
      //       b = 'y';

  string a = "adrian",
         b = "campanera";
  //char *a="Adrian",
       //*b="Campanera";

  std::cout<<"a="<<a<<"\n";
  std::cout<<"b="<<b<<"\n";

  //my_swap(a,b);
  my_swap2(&a,&b);

  std::cout<<"Changed:\n";
  std::cout<<"a="<<a<<"\n";
  std::cout<<"b="<<b<<"\n";

  return 0;
}
