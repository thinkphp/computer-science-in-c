## Templates
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

