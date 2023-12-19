#include <iostream>
#include <string>

// Abstract Product
class Product {
public:
    virtual void display() const = 0;
    virtual ~Product() {}
};

// Concrete Product A
class ConcreteProductA : public Product {
public:
    void display() const override {
        std::cout << "This is ConcreteProductA." << std::endl;
    }
};

// Concrete Product B
class ConcreteProductB : public Product {
public:
    void display() const override {
        std::cout << "This is ConcreteProductB." << std::endl;
    }
};

// Abstract Creator
class Creator {
public:
    virtual Product* createProduct() const = 0;
    virtual ~Creator() {}
};

// Concrete Creator A
class ConcreteCreatorA : public Creator {
public:
    Product* createProduct() const override {
        return new ConcreteProductA();
    }
};

// Concrete Creator B
class ConcreteCreatorB : public Creator {
public:
    Product* createProduct() const override {
        return new ConcreteProductB();
    }
};

int main() {
    // Client code using Factory Method Pattern

    // Create a ConcreteCreatorA
    Creator* creatorA = new ConcreteCreatorA();
    Product* productA = creatorA->createProduct();
    productA->display();
    delete productA;
    delete creatorA;

    // Create a ConcreteCreatorB
    Creator* creatorB = new ConcreteCreatorB();
    Product* productB = creatorB->createProduct();
    productB->display();
    delete productB;
    delete creatorB;

    return 0;
}
