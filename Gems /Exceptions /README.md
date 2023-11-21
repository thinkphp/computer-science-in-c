# Exceptions Handling

When executing C++ code, different errors can occur: coding errors made by the programmer, errors due to wrong input, or other unforeseeable things.

When an error occurs, C++ will normally stop and generate an error message. The technical term for this is: C++ will throw an exception (throw an error).

Exception handling in C++ consist of three keywords: try, throw and catch:

* The try statement allows you to define a block of code to be tested for errors while it is being executed.

* The throw keyword throws an exception when a problem is detected, which lets us create a custom error.

* The catch statement allows you to define a block of code to be executed, if an error occurs in the try block.

* The try and catch keywords come in pairs:

```c++
try {
  int age = 15;
  if (age >= 18) {
    cout << "Access granted - you are old enough.";
  } else {
    throw (age);
  }
}
catch (int myNum) {
  cout << "Access denied - You must be at least 18 years old.\n";
  cout << "Age is: " << myNum;
}
```
