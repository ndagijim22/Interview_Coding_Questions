/*
            VIRTUAL FUNCTION
    A virtual function is a function declared with the virtual keyword in the base class. 
    Derived classes can override this function with their own implementation. When a virtual 
    function is called using a pointer or reference to a base class, the appropriate 
    implementation based on the actual object type is determined at runtime.

    Using virtual functions, you can achieve polymorphism, which allows you to write code that 
    works with objects of different derived classes through a common interface (base class). 
    The appropriate function to call is determined based on the actual object's type at runtime.
*/
#include <iostream>

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};
