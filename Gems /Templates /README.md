## Templates

A template is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need to sort() for different data types. Rather than writing and maintaining multiple codes, we can write one sort() and pass the datatype as a parameter. 
## 

## Ideone

https://www.geeksforgeeks.org/templates-cpp/

swap https://ideone.com/8Mov8u

```C++
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

```

```c++
template <class T>
class Stack {
      public:
      Stack() {
        printf("%s\n","Init Stack.");
        vis = 0;
      }
      ~Stack() {
        printf("\n%s", "Deconstructor:stack is distroyed.");
      }
      void push(T v);
      T pop();
      private:
        T stack[SIZE];
        int vis;
};

```
https://ideone.com/xBQQ0l
* Stack < char > st_c  
* Stack < float > st_f
* Stack < double > st_d
* Stack < int > st_i


## References

https://ideone.com/thinkphp/templates
