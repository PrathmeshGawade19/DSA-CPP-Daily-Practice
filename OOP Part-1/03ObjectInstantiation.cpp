/*Static Instantiation :
Definition: The object is created on the stack. Its lifetime is tied to the scope in which it is declared, and it is automatically destroyed when it goes out of scope.
Use static instantiation when the object's size and lifetime are predictable and managed automatically.

Dynamic Instantiation :
Definition: The object is created on the heap using the new keyword. The programmer is responsible for managing the memory (deleting the object when it is no longer needed).
Use dynamic instantiation when you need more control over memory or want to allocate objects dynamically at runtime.
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
    Vehicle car; // static instantiation of object car
    car.name = "tata safari";
    car.start();
    car.stop(car.name);

    Vehicle *bike = new Vehicle(); // dynamice instantiation of object bike
    (*bike).name = "royal enfield"; // to access the data member
    bike->modelNum = 303; // arrow operator (->) can also be used to access the data member
    cout<<(*bike).name<<endl;
    cout<<bike->modelNum<<endl;
    bike->stop((*bike).name);

    delete bike; // Freeing heap memory

    return 0;
}