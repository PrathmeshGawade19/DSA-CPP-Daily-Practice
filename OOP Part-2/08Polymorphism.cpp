/*
Term "polymorphism" comes from the Greek words poly (many) and morph (forms), meaning that the same function or operator can behave differently based on the context. In C++, polymorphism allows you to perform a single action in different ways, enabling code reusability and extensibility.

Types of Polymorphism :
Polymorphism in C++ can be broadly categorized into two types:
1) Compile-Time Polymorphism (Static Polymorphism)
Compile-time polymorphism is achieved through function overloading and operator overloading. The behavior is resolved at compile time.
a) Function Overloading
Function overloading allows multiple functions to have the same name but with different parameters (type or number).
b) Operator Overloading
Operator overloading allows you to redefine the behavior of operators for user-defined types.

2) Run-Time Polymorphism (Dynamic Polymorphism)
Run-time polymorphism is achieved through inheritance and virtual functions. The behavior is determined at runtime.
a) Function Overriding
Function overriding occurs when a child class provides a specific implementation for a function already defined in its parent class.


*/

#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    cout << calc.add(5, 10) << endl;          // Calls add(int, int)
    cout << calc.add(5.5, 3.2) << endl;       // Calls add(double, double)
    cout << calc.add(1, 2, 3) << endl;        // Calls add(int, int, int)
    return 0;
}
