

/*

deconstructor: jab hm alga se constructor bana hai jo static memory hota hai wah delete automatic ho jata hai
but dynamic wala nahi from heapDS es liye deconstructor karke hai 

if not delete to MEMORY LEAK ka prob hoga


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
        *mileage = 12;  //yah automatic delete nahi hota hai es liye deallocation
    }

    //ab hm apna copyConstructor 
    Car(Car &original) {
        cout << "copying original to new.. \n";
        name = original.name;
        color = original.color;
        mileage = original.mileage;  
    }


    //deconstructor
    ~Car() {
        cout << "deleting object.. \n";
        if(mileage != NULL) {
            delete mileage;
            mileage = NULL;  //eye se nahi dikha hai but as a programmer hm delete bhi memory ko karan chahiye
        }
    }

};


int main() {
    Car c1("maruti 800", "white");
    Car c2(c1);

    cout << c2.name << endl;  
    cout << c2.color << endl;  
    cout << *c2.mileage << endl;

    return 0;
}