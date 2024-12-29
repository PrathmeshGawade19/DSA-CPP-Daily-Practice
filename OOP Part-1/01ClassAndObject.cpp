/*OOP (Object Oriented Programming) is a type of programming approach where program logic revolves around objects.
Object - Instance of class. They have properties and behaviour/actions to perform.
Class - User defined datatype or can also be called as blueprint of a object.
*/

#include<iostream>
using namespace std;

class Vehicle{
    public: // access modifier - public, private, protected
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

};

int main(){
    Vehicle car; // instantiating an object (car) of the class Vehicle.
    car.name = "tata safari"; // using dot operator (.) to access data members of class
    car.modelNum = 505;
    car.NumOfWheels = 4;

    cout<<car.name<<endl;
    cout<<car.modelNum<<endl;
    cout<<car.NumOfWheels<<endl;
    car.start();
    car.run();
    car.stop(car.name);

    cout<<endl;

    Vehicle bike;
    bike.name = "royal enfield";
    bike.modelNum = 303;
    bike.NumOfWheels = 2;

    cout<<bike.name<<endl;
    cout<<bike.modelNum<<endl;
    cout<<bike.NumOfWheels<<endl;
    bike.start();
    bike.run();
    bike.stop(bike.name);

    return 0;
}