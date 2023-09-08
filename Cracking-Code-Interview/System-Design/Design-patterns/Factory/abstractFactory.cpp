/*          ABSTRACT FACTORY
 In the Abstract Factory pattern, an abstract factory class defines a family of 
 related factories, each of which can produce a set of related objects.

In this example, we'll create an abstract factory for producing different types of 
animals: Dog and Cat, and for each animal type, we'll have concrete factories that 
create concrete instances of those animals.

*/
#include <iostream>
#include <string>

// Abstract base class for animals
class Animal {
public:
    virtual void makeSound() = 0;
};

// Concrete animal classes
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Dog is barking." << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Cat is meowing." << std::endl;
    }
};

// Abstract factory class
class AnimalFactory {
public:
    virtual Animal* createAnimal() = 0;
};

// Concrete factory classes for each animal
class DogFactory : public AnimalFactory {
public:
    Animal* createAnimal() override {
        return new Dog();
    }
};

class CatFactory : public AnimalFactory {
public:
    Animal* createAnimal() override {
        return new Cat();
    }
};

int main() {
    // Using the Abstract Factory pattern
    AnimalFactory* dogFactory = new DogFactory();
    AnimalFactory* catFactory = new CatFactory();

    Animal* dog = dogFactory->createAnimal();
    Animal* cat = catFactory->createAnimal();

    dog->makeSound();
    cat->makeSound();

    delete dogFactory;
    delete catFactory;
    delete dog;
    delete cat;

    return 0;
}
