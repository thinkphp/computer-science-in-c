#include <iostream>
#include <string>

using namespace std;

//clasa de baza
class Animal {
   public:
   virtual string makeSound() const {
         return "animal sound";
   }
};

class Dog: public Animal {
      public:
      string makeSound() const override {
            return "Hau! Hau!";
      }
};

class Cat: public Animal {
      public:
      string makeSound() const override {
           return "Miau! Miau!";
      }
};

int main(int argc, char const *argv[]) {
  /* code */

  Animal *animal1 = new Dog();
  Animal *animal2 = new Cat();

  //cout<<animal1->makeSound();
  //cout<<animal2->makeSound();

  //array de animale pointers
  Animal *animals[] = {animal1, animal2};

  for(Animal *animal: animals) {
        cout<<animal->makeSound()<<endl;
  }


  return 0;
}
