/*
Destructor:
A destructor is the opposite of a constructor. It is used to clean up resources when an object is destroyed (e.g., deallocating memory, closing files, etc.).
Destructors have the same name as the class but are preceded by a tilde (~).

for static allocation of object destructor is called automatic.
for dynamic allocated object destructor is called manually (same as we free the memory in dyamic memory allocation) using delete.
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

    Vehicle(){
        cout<<"constructor called"<<endl;
    }

    ~Vehicle(){ 
        cout<<"destructor called"<<endl;
    }

};

int main(){
    // Vehicle car;
    // car.name = "tata safari";
    // cout<<car.name<<endl;

    Vehicle *bike = new Vehicle();
    bike->name = "royal enfield";
    cout<<bike->name<<endl;
    
    delete bike;

    return 0;
}