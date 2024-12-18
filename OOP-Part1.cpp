//OOP (object oriented programming) concepts part-1

#include<iostream>
using namespace std;

//class -  blueprint of objects
class car{
    private:
    int usedkm;

    public: //access modifier
    string name; 
    int modelNum;
    string color;

    void start(string carname){
        cout<<"the "<<carname<<" has started..."<<endl;
    }

    void stop(string carname){
        cout<<"the "<<carname<<" has stopped..."<<endl;
    }

    void setUsedkm(int value, int username){ //setter
        if(username == 123){
            usedkm = value;
        }
        else{
            usedkm = 0;
        }
    }

    int getUsedkm(){ //getter
        return usedkm;
    }

    car(){ //default constructor
        cout<<"default constructor is called"<<endl;
    }
    //constructor types - default, parameterized, copy

    ~car(){
        cout<<"default destructor is called"<<endl;
    }

};

int main(){
    /*
    car mercedes; //object instantiation/creation

    mercedes.name = "mercedes benz s"; //using dot operator to access class members
    mercedes.modelNum = 45;
    mercedes.color = "red";
    mercedes.start(mercedes.name);
    cout<<mercedes.name<<endl;
    cout<<mercedes.modelNum<<endl;
    cout<<mercedes.color<<endl;
    mercedes.stop(mercedes.name);

    mercedes.setUsedkm(150, 123);
    cout<<mercedes.getUsedkm()<<endl;
    */

//    static and dynamic allocation/instantiation of object
    // car toyota; //static
    car *toyota = new car; //dynamic

    toyota->name = "fortuner"; // -> arrow operator
    toyota->start(toyota->name);

    cout<<toyota->name<<endl;
    delete toyota;
    
    //other topics
    //copy assisgnment operator, shallow and deep copy, static keyword - static member and static function


    return 0;
}