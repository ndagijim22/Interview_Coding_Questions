/*                      FACTORY METHOD
    In the Factory Method pattern, a base class defines an interface for creating objects, 
    while subclasses are responsible for implementing the creation process.
    In this example, we'll create a factory for producing different types of vehicles: 
    Car and Bicycle.
*/

#include <iostream>
#include <string>

// Abstract base class for vehicles
class Vehicle {
public:
    virtual void drive() = 0;
};

// Concrete vehicle classes
class Car : public Vehicle {
public:
    void drive() override {
        std::cout << "Driving a car." << std::endl;
    }
};

class Bicycle : public Vehicle {
public:
    void drive() override {
        std::cout << "Riding a bicycle." << std::endl;
    }
};

// Abstract factory class
class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
};

// Concrete factory classes
class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Car();
    }
};

class BicycleFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Bicycle();
    }
};

int main() {
    // Using the Factory Method pattern
    VehicleFactory* carFactory = new CarFactory();
    VehicleFactory* bicycleFactory = new BicycleFactory();

    Vehicle* car = carFactory->createVehicle();
    Vehicle* bicycle = bicycleFactory->createVehicle();

    car->drive();
    bicycle->drive();

    delete carFactory;
    delete bicycleFactory;
    delete car;
    delete bicycle;

    return 0;
}
