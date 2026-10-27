

/*

Types of Inheritance:
1. single-level: jis mai ek hi baseClass and derivedClass ho
2. Multi-Level inheritance: more than one derived class

3. multiple inheritance: two base and one one derived
4. Hierarchial inheritance: one baseClass and two derivedClass

5. Hybrid: is mix match of everything

*/


#include <iostream>
#include <string>
using namespace std;


class Animal {
public:
    void eat() {
        cout << "eats\n";
    }

    void breathe() {
        cout << "breathes\n";
    }
};


class Mammal : public Animal {
public:
    string bloodType = "warm";

    //constructor
    Mammal() {
        bloodType = "warm";
    }
};


class Dog : public Mammal {  //eg of multi-level inheritance
public:
    void tailLong() {
        cout << "Dog have its long tails\n";
    }
};


int main() {
    Dog d1;

    d1.eat();
    d1.breathe();
    d1.tailLong();
    cout <<  d1.bloodType << endl;


    return 0;
}