## Templates

A template is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need to sort() for different data types. Rather than writing and maintaining multiple codes, we can write one sort() and pass the datatype as a parameter. 
## 

swap https://ideone.com/8Mov8u

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

https://www.geeksforgeeks.org/templates-cpp/
