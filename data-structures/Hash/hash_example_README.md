# Student Hash Table in C

This is a simple implementation of a hash table in C for storing and retrieving student records by their names.  
It demonstrates basic operations such as insertion, searching, and memory cleanup using separate chaining (linked lists) to handle collisions.

## 🧠 Features

- Hashing of student records based on their name.
- Insertion of students into the hash table.
- Search for a student by name.
- Prints student information or a message if not found.
- Proper memory management (freeing allocated memory).

## 📁 File Structure

```

project/
│
├── student\_hash.c     # Main C file with hash table implementation
├── README.md          # This documentation file

````

## 🔧 How It Works

- A student's name is hashed using a simple ASCII sum and modulo operation.
- Students with the same hash index are placed in a linked list (chaining).
- Lookup is done by traversing the list at the given hash index.

## ✅ Example Usage

```c
insertStudent("Alice", 20);
insertStudent("Bob", 22);
insertStudent("Charlie", 21);

printStudent("Alice");   // Output: Student: Alice, Age: 20
printStudent("David");   // Output: Student David not found.
````

## 🧪 Compile and Run

To compile the program:

```bash
gcc -o student_hash student_hash.c
```

Then run:

```bash
./student_hash
```

## 📦 Sample Output

```
Student: Alice, Age: 20
Student David not found.
```

## 🚀 Future Improvements

* Load and save student data from/to files.
* Use dynamic resizing of the hash table.
* Implement removal of students.
* Use a better hash function (e.g. djb2 or MurmurHash).

## 🧹 Memory Management

At the end of execution, all allocated memory is properly freed using the `freeTable()` function.

