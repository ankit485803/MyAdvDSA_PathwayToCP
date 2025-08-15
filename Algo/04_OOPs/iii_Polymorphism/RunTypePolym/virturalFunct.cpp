

#include <iostream>
using namespace std;
#include <vector>
#include <string>



/*

Virtual Funct: is a member funct that you expect to be redefined in derived class


Prop:
1. VirturalFunct is DYNAMIC in nature
2. defined by the keyword "VIRTUAL" inside a base class and are always declard with a base class and overidden in a child class.
3. A virtual fuct is called during Runtime.


*/




class Parent {
public:
    void getInfo() {
        cout << "Parent class \n";
    }


    //hm esko virtual banate hai
    virtual void hello() {
        cout << "Hello from parent \n";
    }

};




class Child : public Parent {
public:    
    void getInfo() {
        cout << "Child class \n";

    }

    //hm expect kar rahe hai ye read kare virtually -- work almost overriding
    void hello() {
        cout << "Hello from child \n";
    }
};




int main() {

    Child c1;
    c1.hello();


    return 0;
}
