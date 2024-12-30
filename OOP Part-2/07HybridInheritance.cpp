/*
Hybrid inheritance is a combination of two or more types of inheritance. It often involves the use of multiple and hierarchical inheritance together.
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

class Bird : public Animal {
public:
    void fly() {
        cout << "Flying..." << endl;
    }
};

class Bat : public Mammal, public Bird {
public:
    void useEcholocation() {
        cout << "Using echolocation..." << endl;
    }
};

int main() {
    Bat bat;

    // Explicitly resolve ambiguity
    bat.Mammal::eat();  // Calls Animal::eat() via Mammal
    bat.Bird::eat();    // Calls Animal::eat() via Bird

    //instead of scope resolution operator (::) this we can also declare Animal as a virtual base class in both Mammal and Bird to resolve inheritance ambiguity.

    bat.walk(); // Inherited from Mammal
    bat.fly(); // Inherited from Bird
    bat.useEcholocation(); // Defined in Bat
    return 0;
}
