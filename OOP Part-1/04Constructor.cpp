/*
In Object-Oriented Programming (OOP), a constructor is a special type of member function that is automatically called when an object of a class is created. The primary purpose of a constructor is to initialize the object's data members and allocate any necessary resources when an instance of the class is created.

-> Constructors do not have a return type, not even void.
-> The constructor always has the same name as the class.

Types : Default, Parameterized, Copy

Default Constructor:
A constructor that takes no arguments or has default values for all parameters.
If you don't define any constructor, the compiler provides a default constructor automatically, which initializes all data members to their default values (e.g., 0 for integers, nullptr for pointers, and empty for strings).

Parameterized Constructor:
A constructor that takes one or more arguments and uses those values to initialize the object.
This allows you to create objects with specific initial values.

Copy Constructor:
A special constructor used to create a new object as a copy of an existing object.
This is used when you want to copy the values of one object to another (e.g., passing an object by value or returning an object from a function).

-> Constructor Overloading:
In C++, you can have multiple constructors with different parameter lists. This is called constructor overloading. The appropriate constructor is called based on the number and type of arguments provided during object creation.
*/


#include<iostream>
using namespace std;

class Vehicle{
    public:
    string name;
    int modelNum;
    int NumOfWheels;

    void start(){
        cout<<"vehicle has started"<<endl;
    }

    void run(){
        cout<<"vehicle is running..."<<endl;
    }

    void stop(string name){
        cout<<name<<" vehicle has stopped"<<endl;
    }

    //default constructor
    Vehicle(){
        name = "Unknow";
        modelNum = 0;
        NumOfWheels = 0;
        cout<<"this is a default constructor & it's called by default"<<endl;
    }

    //parameterized constructor
    Vehicle(string name, int modelNum){
        this->name = name; //this keyword stores the address of current object 
        this->modelNum = modelNum;
    }

    //copy constructor
    Vehicle(Vehicle& temp){
        this->name = temp.name;
        this->modelNum = temp.modelNum;
        this->NumOfWheels = temp.NumOfWheels;
    }

};

int main(){
    Vehicle car;
    car.name = "tata safari";
    cout<<car.name<<endl;
    car.stop(car.name);

    Vehicle truck("rambo", 101);
    cout<<truck.name<<endl;
    cout<<truck.modelNum<<endl;
    truck.stop(truck.name);

    Vehicle bike(truck);
    cout<<bike.name<<endl;
    cout<<bike.modelNum<<endl;
    bike.stop(bike.name);

    return 0;
}