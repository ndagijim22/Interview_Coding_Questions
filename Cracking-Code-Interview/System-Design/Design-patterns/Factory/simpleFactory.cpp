/*
                SIMPLE FACTORY
    class responsible for creating instances of other classes based on some input
*/
#include <iostream>
#include <string>

// Base class for shapes
class Shape {
public:
    virtual void draw() = 0; //pure virtual function
};

// Concrete shape classes
class Circle : public Shape {
public:
    void draw() override {  //use override always. it's a good practice
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square." << std::endl;
    }
};

// Simple Factory class for creating shapes
/*
    static: this means that the function belong to the class itself. not to the instance of the class
                it can be called using the class name w/o the need to create an instance
    type: data type 
*/
class ShapeFactory {
public:
    static Shape* createShape(const std::string& type) {
        if (type == "circle") {
            return new Circle();
        } else if (type == "square") {
            return new Square();
        } else {
            return nullptr; // Return null for unsupported types
        }
    }
};

int main() {
    // Using the Simple Factory to create shapes
    Shape* circle = ShapeFactory::createShape("circle");
    Shape* square = ShapeFactory::createShape("square");

    if (circle) {
        circle->draw();
        delete circle;
    } else {
        std::cout << "Unsupported shape type: circle" << std::endl;
    }

    if (square) {
        square->draw();
        delete square;
    } else {
        std::cout << "Unsupported shape type: square" << std::endl;
    }

    return 0;
}
