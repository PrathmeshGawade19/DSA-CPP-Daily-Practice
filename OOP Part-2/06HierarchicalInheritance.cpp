/*
In hierarchical inheritance, multiple child classes inherit from a single parent class.

class Parent {
    // Parent members
};

class Child1 : public Parent {
    // Child1 members
};

class Child2 : public Parent {
    // Child2 members
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

class Cat : public Animal {
public:
    void meow() {
        cout << "Meowing..." << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    dog.eat();
    dog.bark();

    cat.eat();
    cat.meow();

    return 0;
}


