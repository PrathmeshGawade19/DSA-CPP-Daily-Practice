/*
In multiple inheritance, a child class inherits from more than one parent class.

class Parent1 {
    // Parent1 members
};

class Parent2 {
    // Parent2 members
};

class Child : public Parent1, public Parent2 {
    // Child class members
};
*/

#include<iostream>
using namespace std;

class Vehicle {
public:
    void start() {
        cout << "Starting vehicle..." << endl;
    }
};

class Machine {
public:
    void operate() {
        cout << "Operating machine..." << endl;
    }
};

class Car : public Vehicle, public Machine {
public:
    void drive() {
        cout << "Driving car..." << endl;
    }
};

int main() {
    Car car;
    car.start();
    car.operate();
    car.drive();
    return 0;
}
