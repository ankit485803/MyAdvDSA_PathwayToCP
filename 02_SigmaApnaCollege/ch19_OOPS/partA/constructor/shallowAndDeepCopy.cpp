

/*

27th Oct 2026 (Tuesday) Shallow & Deep Copy

Shallow copy copies references to original array. But array remains same.
Deep copy created a brand new copy of the array.

Compiler generally creates a shallow copy for array. or dynamic memory allocation
We need to define own copy constructor when deep copy is needed i.e. when class contains pointers to dynamically allocated memory.

*/



#include <iostream>
#include <string>
using namespace std;



class Car {
public: 
    string name;
    string color;
    int *mileage;

    Car(string name, string color) {  
        this->name = name;
        this->color = color;
        mileage = new int;  //Dynamic allocation
        *mileage = 12;
    }

    //ab hm apna copyConstructor 
    Car(Car &original) {
        cout << "copying original to new.. \n";
        name = original.name;
        color = original.color;
        mileage = original.mileage;
    }

};


int main() {
    Car c1("maruti 800", "white");
    Car c2(c1);

    cout << c2.name << endl;  
    cout << c2.color << endl;  
    cout << *c2.mileage << endl;

    c2.mileage = 10;
    cout << *c1.mileage << endl;  //10  yah heapDS mai under both change ho jata hai

    return 0;
}