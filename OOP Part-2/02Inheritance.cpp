/*
Inheritance : Inheritance in object-oriented programming (OOP) allows one class to acquire properties and behaviors (methods) of another class. The class that inherits is called the child class (or derived class), and the class being inherited from is called the parent class (or base class).
syntax -

class parent_class{
    body of parent class
}

class child-class : access_modifier parent_class{
    body of child class
}

Access Specifiers and Inheritance : 
Public Inheritance: Public and protected members of the base class remain public and protected in the derived class.
Protected Inheritance: Public and protected members of the base class become protected in the derived class.
Private Inheritance: Public and protected members of the base class become private in the derived class.
*/

#include<iostream>
using namespace std;

class Animals{ //parent class
    public:
    string type;

    void run(){
        cout<<"runing..."<<endl;
    }

    void eat(){
        cout<<"eating..."<<endl;
    }
};

class Dog : protected Animals{ //child class
    public:
    string breed;
    
    void bark(){
        cout<<"barking..."<<endl;;
    }

    void setType(string type){
        this->type = type;
    }

    string getType(){
        return this->type;
    }

};


int main(){
    Dog shiro;
    shiro.breed = "german-shephard";
    cout<<shiro.breed<<endl;
    shiro.bark();

    // shiro.type = "domestic";
    // cout<<shiro.type<<endl;
    // shiro.run();
    // shiro.eat();
    shiro.setType("domestic");
    string ans = shiro.getType();
    cout<<ans<<endl;

    return 0;
}