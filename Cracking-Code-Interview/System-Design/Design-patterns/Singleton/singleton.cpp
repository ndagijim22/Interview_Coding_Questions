
/*
    SINGLETON OOD design: 
       It ensures that a class has only one instance and provides 
       a global point of access to that instance

       -characteristics:
       1. single instance: it allows a single instance of class and provide 
            a way to access it
       2. private constructor: this to prevent other classes from creating an 
            instance of it
       3. private instance variable: to hold a single instance of the class
       4. static method for access: getInstance()--> it allows other classes to get 
            ref to the single instance. it is used to create instance of the class
*/
#include <iostream>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    int data;

    // Private constructor prevents instantiation from other classes
    Singleton() {
        // Initialization code
        data = 0;
    }

public:
    // Static method to get the singleton instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
    //method to get the value
    int getValue() const{
        return data;
    }
    //method to det the value
    void setValue(int newData){
        data = newData;
    }
};

// Initialize the static member variable
Singleton* Singleton::instance = nullptr;

int main() {
    // Using the Singleton class
    Singleton* firstInstance = Singleton::getInstance();
    Singleton* secondInstance = Singleton::getInstance();

    //accessing and modifying attributes
    firstInstance->setValue(89);
    secondInstance->setValue(90);

    // if (firstInstance == secondInstance) {
       cout << firstInstance->getValue() << endl;
    // } else {
        cout << secondInstance->getValue()<< endl;
    // }

    return 0;
}

