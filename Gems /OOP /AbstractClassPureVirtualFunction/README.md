# Pure Virtual Functions and Abstract Classes in C++
An abstract class is a class that is designed to be specifically used as a base class. An abstract class contains at least one pure virtual function. You declare a pure virtual function by using a pure specifier (= 0) in the declaration of a virtual member function in the class declaration.

The following is an example of an abstract class:

```c++
class AB {
public:
  virtual void f() = 0;
};
```

## Refecences

https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/

https://www.ibm.com/docs/en/zos/2.4.0?topic=only-abstract-classes-c
