#include <iostream>
const int SIZE = 10;
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
template <class T> T Stack<T>::pop() {
    if(vis == 0) {
      printf("%s\n", "empty stack");
      return 0;
    }
    vis--;
    return stack[vis];
}
template <class T>void Stack<T>::push(T v) {
  if(vis == SIZE) {
    printf("%s\n", "Full Stack");
    return;
  }
  std::cout<<"Added to Stack:"<<v<<"\n";
  stack[vis] = v;
  vis++;
}


int main(int argc, char const *argv[]) {

  Stack<int> st_i;//stack of integers
  Stack<float> st_f; //stack of floats
  Stack<double> st_d; //stack of doubles
  Stack<char> st_c; //stack of characters

  st_i.push(1);
  st_i.push(2);
  st_i.push(3);
  std::cout<<"Pop: "<<st_i.pop()<<"\n";
  std::cout<<"Pop: "<<st_i.pop()<<"\n";
  std::cout<<"Pop: "<<st_i.pop()<<"\n";

  st_d.push(12.3);
  st_d.push(16.2);
  std::cout<<"Pop: "<<st_d.pop()<<"\n";
  std::cout<<"Pop: "<<st_d.pop()<<"\n";
  std::cout<<"Pop: "<<st_d.pop()<<"\n";

  st_c.push('A');
  st_c.push('B');
  st_c.push('C');
  std::cout<<"Pop: "<<st_c.pop()<<"\n";
  std::cout<<"Pop: "<<st_c.pop()<<"\n";
  std::cout<<"Pop: "<<st_c.pop()<<"\n";

  return 0;
}
