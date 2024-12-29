/*
Used to make data member accessible without object creation. It belongs to class and not object.
*/

#include<iostream>
using namespace std;

class Vehicle{
    public:
    //static members
    static string name;
    static int modelNum;
    static int NumOfWheels;

    //static functions : can be called without object no neet to create object. No use of this keyword. Can access only static member. 
    static void start(){
        cout<<"vehicle has started"<<endl;
    }

    static void run(){
        cout<<"vehicle is running..."<<endl;
    }

    static void stop(string name){
        cout<<name<<" vehicle has stopped"<<endl;
    }

};

string Vehicle::name = "tata safari";
int Vehicle::modelNum = 505;
int Vehicle::NumOfWheels = 4;

int main(){
    cout<<Vehicle::name<<endl;
    cout<<Vehicle::modelNum<<endl;
    cout<<Vehicle::NumOfWheels<<endl;

    Vehicle::start();
    Vehicle::run();
    Vehicle::stop(Vehicle::name);

    return 0;
}