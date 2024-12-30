/*
In single inheritance, a child class inherits from a single parent class.

class Parent {
    // Parent class members
};

class Child : public Parent {
    // Child class members
};
*/
#include<iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

int main() {
    Dog dog;
    dog.eat(); // Inherited from Animal
    dog.bark(); // Defined in Dog
    return 0;
}
