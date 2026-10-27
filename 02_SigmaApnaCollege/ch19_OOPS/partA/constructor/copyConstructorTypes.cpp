


/*


26th Oct 2026 (Monday)

Copy constructor: a special constructor used to copy prop of one obj into another

*/

#include <iostream>
#include <string>
using namespace std;



class Car {
public: 
    string name;
    string color;

    Car(string name, string color) {  //hm parameterized constructor bante hai
        this->name = name;
        this->color = color;
    }

    //ab hm apna copyConstructor 
    Car(Car &original) {
        cout << "copying original to new.. \n";
        name = original.name;
        color = original.color;
    }

};


int main() {
    Car c1("maruti 800", "white");

    Car c2(c1);
    cout << c2.name << endl;  //automatic copy  ho jayega 
    cout << c2.color << endl;  

    //custom copyConstructor
    Car c3(c1);


    return 0;
}