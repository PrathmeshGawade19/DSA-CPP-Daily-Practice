/*
Encapsulation : wrapping up data member and function.
when all data members of class are marked private it is termed as fully encapsulated class.

advantage : information/data hiding, if we want we can make our class read only, code reuseability, helpful in unit testing.
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

};

int main(){
    Vehicle car;
    car.name = "tata safari";
    car.start();
    car.run();
    car.stop(car.name);


    return 0;
}