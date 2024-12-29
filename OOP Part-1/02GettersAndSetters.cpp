/*Getters and Setters are used to access the private members of class
Getter - a function to read
Setter - a function to manipulate/set value 
*/

#include<iostream>
using namespace std;

class Vehicle{
    private: 
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

    public:
    string getName(){ // getter to get the name value
        return name;
    }

    void setName(string newName){ // setter to set name value
         if (newName.empty() == false) {
            name = newName;
        } else {
            cout << "Error: Name cannot be empty!" << endl;
        }
    }

    void gettestDrive() {
        start();
        run();
        stop(name);
    }

};

int main(){
    Vehicle car;
    car.setName("tata nexon"); 
    cout<<car.getName()<<endl; 

    car.gettestDrive();

    return 0;
}