/*
In multilevel inheritance, a class inherits from another child class, forming a chain.

class Grandparent {
    // Grandparent members
};

class Parent : public Grandparent {
    // Parent members
};

class Child : public Parent {
    // Child members
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

class Mammal : public Animal {
public:
    void walk() {
        cout << "Walking..." << endl;
    }
};

class Dog : public Mammal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

int main() {
    Dog dog;
    dog.eat(); // Inherited from Animal
    dog.walk(); // Inherited from Mammal
    dog.bark(); // Defined in Dog
    return 0;
}
