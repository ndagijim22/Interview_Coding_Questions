/*
        PURE VIRTUAL FUNCTION
    A pure virtual function is a virtual function that is declared with = 0 at the end of 
    its declaration. It has no implementation in the base class and must be overridden by 
    any derived class. Classes containing at least one pure virtual function are considered 
    abstract classes and cannot be instantiated.

    Using virtual functions, you can achieve polymorphism, which allows you to write code that 
    works with objects of different derived classes through a common interface (base class). 
    The appropriate function to call is determined based on the actual object's type at runtime.
*/
#include <iostream>

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};
