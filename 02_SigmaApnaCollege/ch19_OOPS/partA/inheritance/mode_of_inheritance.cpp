

/*

Inheritance:


*/

#include <iostream>
#include <string>
using namespace std;


class Animal {
public:
    string color;

    void eat() {
        cout << "eat\n";
    }

    void breathe() {
        cout << "breathes\n";
    }

};


class Fish : public Animal {
public:
    int fins;

    void swims() {
        cout << "can swims\n";
    }

};



int main() {
    Fish f1;
    f1.fins = 3;
    cout << f1.fins << endl;
    f1.swims();
  
    f1.eat();   //inherit prop from parent
    f1.breathe();


    return 0;
}