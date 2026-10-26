


/*

Constructor

Special method invoked automatically at time of object creation. Used for Initialisation.
• Same name as class
• Constructor doesn’t have a return type
• Only called once (automatically), at object creation
• Memory allocation happens when constructor is called


this is a special pointer in c++ that points to the currObj

Types of constructor: Non-parameterized, Parameterized, Copy constructor 

*/


#include <iostream>
using namespace std;


class Car {
    string name;
    string color;

public:
    //hm ek constructor banate hai
    Car(string nameVal, string colorVal) {
        cout << "constructor is called. object being created..\n";
        name = nameVal;
        color = colorVal;
    }


    void start() {
        cout << "car has started.. \n";
    }

    void stop() {
        cout << "car has stopped\n";
    }

};


int main() {
    Car c1;
    Car c1("maruti 800", "while");

    return 0;
}





class Car {
    string name;
    string color;

public:
    Car() {
        cout << "constructor without parameters\n";
    }

    Car(string nameVal, string colorVal) {
        cout << "Constructor is called. Object being created..\n";
        name = nameVal;
        color = colorVal;
        this->name = name;  //arrow operator
        this->color = color;
        //*this->color = color;
    }

    void start() {
        cout << "Car has started..\n";
    }

    void stop() {
        cout << "Car has stopped\n";
    }

    //getter
    string getName() {
        return name;
    }

};

int main() {
    Car c1("maruti 800", "white");
    Car c0;  //non parameterized constructor

    c1.start();
    c1.stop();

    return 0;
}
