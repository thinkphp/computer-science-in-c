I'll show you how to apply the SOLID principles in C++ with examples for each principle.

## 1. Single Responsibility Principle (SRP)

A class should have only one reason to change, meaning it should have only one responsibility.

```cpp
// Bad: Class has multiple responsibilities
class User {
private:
    std::string name;
public:
    User(const std::string& name) : name(name) {}
    
    std::string getName() const {
        return name;
    }
    
    void save() {
        // Save user to database
        std::cout << "Saving user " << name << " to database" << std::endl;
    }
    
    void sendEmail(const std::string& message) {
        // Send email to user
        std::cout << "Sending email to " << name << ": " << message << std::endl;
    }
};

// Better: Separate responsibilities into different classes
class User {
private:
    std::string name;
public:
    User(const std::string& name) : name(name) {}
    
    std::string getName() const {
        return name;
    }
};

class UserRepository {
public:
    void save(const User& user) {
        // Save user to database
        std::cout << "Saving user " << user.getName() << " to database" << std::endl;
    }
};

class EmailService {
public:
    void sendEmail(const User& user, const std::string& message) {
        // Send email to user
        std::cout << "Sending email to " << user.getName() << ": " << message << std::endl;
    }
};
```

## 2. Open/Closed Principle (OCP)

Software entities should be open for extension but closed for modification.

```cpp
// Bad: Need to modify class to add new shapes
class AreaCalculator {
public:
    double calculateArea(const void* shape, const std::string& type) {
        if (type == "Rectangle") {
            auto rectangle = static_cast<const Rectangle*>(shape);
            return rectangle->width * rectangle->height;
        } else if (type == "Circle") {
            auto circle = static_cast<const Circle*>(shape);
            return 3.14 * circle->radius * circle->radius;
        }
        throw std::invalid_argument("Shape not supported");
    }
};

// Better: Use polymorphism to extend functionality
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    double area() const override {
        return 3.14 * radius * radius;
    }
};

class AreaCalculator {
public:
    double calculateArea(const Shape& shape) {
        return shape.area();
    }
};
```

## 3. Liskov Substitution Principle (LSP)

Objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program.

```cpp
// Bad: Square is not a proper substitute for Rectangle
class Rectangle {
protected:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    virtual void setWidth(double w) {
        width = w;
    }
    
    virtual void setHeight(double h) {
        height = h;
    }
    
    double area() const {
        return width * height;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    
    void setWidth(double w) override {
        width = w;
        height = w;  // Violates LSP
    }
    
    void setHeight(double h) override {
        width = h;  // Violates LSP
        height = h;
    }
};

// Better: Use a common abstraction
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    void setWidth(double w) {
        width = w;
    }
    
    void setHeight(double h) {
        height = h;
    }
    
    double area() const override {
        return width * height;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    
    void setSide(double s) {
        side = s;
    }
    
    double area() const override {
        return side * side;
    }
};
```

## 4. Interface Segregation Principle (ISP)

No client should be forced to depend on methods it does not use.

```cpp
// Bad: Fat interface
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual ~Worker() = default;
};

// Classes must implement all methods, even if they don't need them
class Robot : public Worker {
public:
    void work() override {
        std::cout << "Robot is working" << std::endl;
    }
    
    void eat() override {
        // Robots don't eat, but have to implement this
    }
    
    void sleep() override {
        // Robots don't sleep, but have to implement this
    }
};

// Better: Segregated interfaces
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() = default;
};

class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() = default;
};

class Sleepable {
public:
    virtual void sleep() = 0;
    virtual ~Sleepable() = default;
};

class Human : public Workable, public Eatable, public Sleepable {
public:
    void work() override {
        std::cout << "Human is working" << std::endl;
    }
    
    void eat() override {
        std::cout << "Human is eating" << std::endl;
    }
    
    void sleep() override {
        std::cout << "Human is sleeping" << std::endl;
    }
};

class Robot : public Workable {
public:
    void work() override {
        std::cout << "Robot is working" << std::endl;
    }
};
```

## 5. Dependency Inversion Principle (DIP)

High-level modules should not depend on low-level modules. Both should depend on abstractions.

```cpp
// Bad: High-level module depends on low-level module
class MySQLDatabase {
public:
    void connect() {
        std::cout << "Connected to MySQL database" << std::endl;
    }
    
    void query(const std::string& sql) {
        std::cout << "Executing query: " << sql << std::endl;
    }
};

class UserService {
private:
    MySQLDatabase database;  // Direct dependency
public:
    void getUser(int userId) {
        database.connect();
        database.query("SELECT * FROM users WHERE id = " + std::to_string(userId));
    }
};

// Better: Both depend on abstractions
class Database {
public:
    virtual void connect() = 0;
    virtual void query(const std::string& sql) = 0;
    virtual ~Database() = default;
};

class MySQLDatabase : public Database {
public:
    void connect() override {
        std::cout << "Connected to MySQL database" << std::endl;
    }
    
    void query(const std::string& sql) override {
        std::cout << "Executing query: " << sql << std::endl;
    }
};

class PostgreSQLDatabase : public Database {
public:
    void connect() override {
        std::cout << "Connected to PostgreSQL database" << std::endl;
    }
    
    void query(const std::string& sql) override {
        std::cout << "Executing SQL: " << sql << std::endl;
    }
};

class UserService {
private:
    Database& database;  // Dependency injection
public:
    UserService(Database& db) : database(db) {}
    
    void getUser(int userId) {
        database.connect();
        database.query("SELECT * FROM users WHERE id = " + std::to_string(userId));
    }
};
```

These examples demonstrate how to apply each SOLID principle in C++. Key points to remember:

- Single Responsibility: Each class has one job
- Open/Closed: Extend functionality without modifying existing code
- Liskov Substitution: Subtypes must be substitutable for their base types
- Interface Segregation: Create specific interfaces rather than general ones
- Dependency Inversion: Depend on abstractions, not concrete implementations

C++ specific considerations:
- Use pure virtual functions for interfaces
- Remember to provide virtual destructors for base classes
- Use const correctness to ensure immutability where appropriate
- Consider using smart pointers for memory management in real applications
- Reference parameters or pointers can be used for dependency injection
